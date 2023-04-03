#pragma once



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
    class UdpClient
    {
    public:
        UdpClient()
        {
        }
        UdpClient(std::string ip, uint16_t port)
            : _server_ip(ip), _server_port(port)
        {
            // 1. 创建套接字
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sockfd < 0) // 失败返回-1
            {
                std::cout << "socket error" << std::endl;
            }
            else
            {
                std::cout << "socket create success, sockfd: " << _sockfd << std::endl;
            }
        }
        void Start()
        {
            // 2. 绑定
            //对于客户端，我们不需要手动绑定IP+端口号，因为客户端不会是被动链接的，是主动连接的发起者
            //那么客户端需要知道服务器的IP+端口号，而自身的IP+端口号会在通信过程中交付给服务器
            //则我们一般并不给客户端套接字进行绑定操作，这个任务一般由OS进行，绑定 主机IP+随机的端口号

            // 3. 发送数据 -- 接收数据
            // a. 为目标服务器进程创建通信数据结构
            struct sockaddr_in server;
            server.sin_family = AF_INET;                            // 通信类型
            server.sin_port = htons(_server_port);                  // 主机转网络
            server.sin_addr.s_addr = inet_addr(_server_ip.c_str()); // 主机转网络
            // b. 创建发送缓冲区
            std::string sentdoBuf;
            std::string recvBuf;

            // c.发送数据
            for (;;)
            {
                std::cout << "client # ";
                std::cin >> sentdoBuf;
                ssize_t write_size = sendto(_sockfd, sentdoBuf.c_str(), sentdoBuf.size(), 0, (const sockaddr *)&server, sizeof(server));
                if (write_size == 0)
                {
                    std::cout << "server sockfd is closed" << std::endl;
                    return;
                }
                else if (write_size < 0)
                {
                    std::cout << "sentdo error " << std::endl;
                    return;
                }
                else
                {
                    std::cout << "sendto sussess." << std::endl;
                }
            }
        }
        ~UdpClient()
        {
            if (_sockfd >= 0)
            {
                close(_sockfd);
            }
        }

    private:
    private:
        uint16_t _server_port;  // 16位端口号
        std::string _server_ip; // 字符串型IP
        int _sockfd;            // 套接字，即文件描述符
    };
}