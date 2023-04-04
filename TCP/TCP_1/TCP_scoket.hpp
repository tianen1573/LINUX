#pragma once

#define SIZE 1024

#include <sys/types.h>  //通信类型
#include <sys/socket.h> //套接字函数
#include <netinet/in.h> //结构体
#include <arpa/inet.h>  //结构体
#include <ctype.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

#include <queue>
#include <unordered_map>

#include <unistd.h> //文件操作

typedef void (*Handler)(const std::string &req, std::string *resp);
// #include <functional>
// typedef std::function<void(const std::string &, std::string *resp)> Handler;

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

namespace TCP
{
    class TcpSocket
    {
    public:
        TcpSocket(int num = 5)
        :_gbacklog(num)
        {
        }
        int Socket()
        {
            //1. 创建套接字
            int sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) // 失败返回-1
            {
                std::cout << "创建监听套接字失败" << std::endl;
                assert(false);
            }

            return sock;
        }
        void Bind(int sockfd, uint16_t port, const std::string &ip = "0.0.0.0")
        {
            // 2. 绑定套接字

            // a. 创建sockaddr_in结构体
            sockaddr_in local;
            bzero(&local, sizeof(local)); //全部初始化为0
            local.sin_family = AF_INET;   // 通信类型
            local.sin_port = htons(port); // 主机转网络
            
            inet_pton(AF_INET, ip.c_str(), &(local.sin_addr)); // 主机转网络
            
            // b. 绑定
            if (bind(sockfd, (sockaddr *)&local, sizeof(local)) < 0)
            {
                std::cout << "bind error" << std::endl;
                assert(false);
            }
        }
        void Listen(int sockfd)
        {
            // 3. 监听
            if (listen(sockfd, _gbacklog) < 0)
            {
                assert(false);
            }
        }
        
        // const &输入
        // * 输出
        // & 输入&&输出
        int Accept(int listenSock, std::string *ip, uint16_t *port)
        {
            // 4. 获取连接， 获取通信套接字
            // UDP不需要连接，服务端是一对多的
            // 而TCP是需要连接的，是一对一的
            // 此时，通信准备已经做好了
            sockaddr_in src;
            socklen_t len = sizeof(src);

            int serviceSock = accept(listenSock, (sockaddr *)&src, &len);
            if (serviceSock < 0)
            {
                assert(false);
            }

            //关系通信方身份信息
            if (port)
                *port = ntohs(src.sin_port);
            if (ip)
                *ip = inet_ntoa(src.sin_addr);
            return serviceSock;
        }
        bool Connect(int socket, const std::string &server_ip, const uint16_t &server_port)
        {
            //请求连接
            sockaddr_in server;
            bzero(&server, sizeof(server));
            server.sin_family = AF_INET;
            server.sin_port = htons(server_port);
            server.sin_addr.s_addr = inet_addr(server_ip.c_str());

            if (connect(socket, (sockaddr *)&server, sizeof(server)) == 0)
                return true;
            else
                return false;
        }

        ~TcpSocket()
        {
        }

    private:
        const int _gbacklog;
    };
}
