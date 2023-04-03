#pragma once

#ifndef _UDP_SERVER_HPP
#define _UDP_SERVER_HPP
#endif

#define SIZE 1024


#include <sys/types.h>  //通信类型
#include <sys/socket.h> //套接字函数
#include <netinet/in.h> //结构体
#include <arpa/inet.h>  //结构体

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <unistd.h> //文件操作

namespace UDP
{
    class UdpServer
    {
    public:
        UdpServer()
        {
        }
        UdpServer(std::string ip, uint16_t port)
            : _port(port), _ip(ip)
        {
            // 1. 创建套接字
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sockfd < 0) // 失败返回-1
            {
                std::cout << "socket error" << std::endl;
            }
            else
            {
                std::cout << "socket create sussess, sockfd: " << _sockfd << std::endl;
            }
        }
        void Start()
        {
            // 2. 绑定
            // 对于服务器，因为服务器是被链接的，别人需要知道服务器进程的IP+端口号
            // 所以我们给服务器进程指定 固定的IP+端口号，使得客户端可以找到我们

            // a. 创建sockaddr_in结构体
            struct sockaddr_in local;
            local.sin_family = AF_INET;                     // 通信类型
            local.sin_port = htons(_port);                  // 主机转网络
            local.sin_addr.s_addr = inet_addr(_ip.c_str()); // 主机转网络
            // b. 绑定
            if (bind(_sockfd, (sockaddr *)&local, sizeof(local)) < 0)
            {
                std::cerr << "bind error" << std::endl;
            }
            else
            {
                std::cout << "bind success" << std::endl;
            }

            // 3. 发送数据 -- 接收数据
            // a. 为客户端进程创建通信数据结构保存其信息
            struct sockaddr_in client;
            socklen_t client_len = sizeof(client);
            // b. 创建接收缓冲区
            char buffer[SIZE];
            // c.接收数据
            for (;;)
            {
                
               ssize_t size = recvfrom(_sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&client, &client_len);
                if (size < 0)
                {
                    std::cout << "recvfrom error " << std::endl;
                    //可能有多个客户端发送数据，一次失败不代表直接结束
                }
                else
                {
                    buffer[size] = '\0';
                    int client_port = ntohs(client.sin_port);
                    std::string client_ip = inet_ntoa(client.sin_addr);
                    std::cout << client_ip << ":" << client_port << " # ";
                    std::cout << buffer << std::endl;
                }
            }

        }
        ~UdpServer()
        {
            if (_sockfd >= 0)
            {
                close(_sockfd);
            }
        }

    private:
        uint16_t _port;  // 16位端口号
        std::string _ip; // 字符串型IP
        int _sockfd;     // 套接字，即文件描述符
    };
}