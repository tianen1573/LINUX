#pragma once

#define SIZE 1024

#include <sys/types.h>  //通信类型
#include <sys/socket.h> //套接字函数
#include <netinet/in.h> //结构体
#include <arpa/inet.h>  //结构体

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

#include <unistd.h> //文件操作

typedef void (*Handler)(const std::string &req, std::string *resp);
// #include <functional>
// typedef std::function<void(const std::string &, std::string *resp)> Handler;

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

namespace UDP
{
    class UdpSocket
    {
    public:
        UdpSocket()
            : _sockfd(-1)
        {
        }
        bool Socket()
        {
            //创建套接字
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sockfd < 0) // 失败返回-1
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool Bind(uint16_t port, const std::string &ip = "")
        {
            // 绑定

            // a. 创建sockaddr_in结构体
            sockaddr_in local;
            bzero(&local, sizeof(local));//全部初始化为0
            local.sin_family = AF_INET;   // 通信类型
            local.sin_port = htons(port); // 主机转网络
            if (!ip.empty())
                local.sin_addr.s_addr = inet_addr(ip.c_str()); // 主机转网络
            else
                local.sin_addr.s_addr = INADDR_ANY;
            // b. 绑定
            if (bind(_sockfd, (sockaddr *)&local, sizeof(local)) < 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool RecvFrom(std::string *buf, std::string *ip = NULL, uint16_t *port = NULL)
        {
            // 接收数据
            // a. 为客户端进程创建通信数据结构保存其信息
            sockaddr_in peer;
            bzero(&peer, sizeof(peer));//全部初始化为0
            socklen_t peer_len = sizeof(peer);
            // b. 创建接收缓冲区
            char buffer[SIZE];
            // c. 接收数据
            ssize_t size = recvfrom(_sockfd, buffer, sizeof(buffer) - 1, 0, (sockaddr *)&peer, &peer_len);
            if (size < 0)
            {
                perror("recvrrom");
                return false;
            }
            buffer[size] = '\0';//以C方式保存字符串
            buf->assign(buffer, size); //将读到的数据放到输出型参数buf
            // d. 是否关系客户端信息
            if (ip != NULL)
            {
                *ip = inet_ntoa(peer.sin_addr);
            }
            if (port != NULL)
            {
                *port = ntohs(peer.sin_port);
            }

            return true;
        }
        bool Sendto(const std::string &buf, const std::string &ip, uint16_t port)
        {
            sockaddr_in addr;
            bzero(&addr, sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            addr.sin_port = htons(port);

            ssize_t write_size = sendto(_sockfd, buf.c_str(), buf.size(), 0, (sockaddr *)&addr, sizeof(addr));
            if (write_size < 0)
            {
                perror("sendto");
                return false;
            }
            return true;
        }
        bool Close()
        {
            close(_sockfd);
            return true;
        }
        ~UdpSocket()
        {
        }

    private:
        int _sockfd; // 套接字，即文件描述符
    };
}
