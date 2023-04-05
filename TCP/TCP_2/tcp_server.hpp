#pragma once

#include "TCP_scoket.hpp"

namespace TCP
{
    class TcpServer
    {
    public:
        TcpServer(const uint16_t &port, const std::string &ip = "", const int gbl = 5)
            : _port(port), _ip(ip), _gblaklog(gbl)
        {

            // 1.创建套接字
            _listen_sock = _sock.Socket();
            assert(_listen_sock != -1);
            
            // 2.绑定监听套接字
            _sock.Bind(_listen_sock, _port);

            
            // 3.监听套接字
            _sock.Listen(_listen_sock);

            std::cout << "server start" << std::endl;
        }

        void Service(int sock, std::string srcIp, int srcPort, Handler handler)
        {
            
            char buffer[1024];

            //直到通信关闭
            while (true)
            {
                ssize_t size = read(sock, buffer, sizeof(buffer) - 1);
                if (size > 0)
                {
                    buffer[size] = '\0';

                    std::string req = buffer;
                    std::string resp;
                    handler(req, &resp);
                    std::cout << '[' << srcIp << ':' << srcPort << "]# " << req << std::endl;
                    write(sock, resp.c_str(), resp.size());
                }
                if (size == 0) //客户端关闭
                {
                    std::cout << srcIp << " close" << std::endl;
                    break;
                }
                if (size < 0) //读取失败
                {
                    std::cout << "read error" << std::endl;
                    break;
                }
            }
            close(sock);
        }

        void Start(Handler handler)
        {
            // //信号
            // signal(SIGCHLD, SIG_IGN);//忽略子进程退出
            while (true)
            {
                // 4. 获取链接
                // a. 保存通信方信息
                std::string srcIp;
                uint16_t srcPort;
                int sock = _sock.Accept(_listen_sock, &srcIp, &srcPort);
                if (sock < 0)
                    continue;
                
                // //子进程执行处理，父进程继续获取链接
                // pid_t pid = fork();
                // if(pid == 0)
                // {
                //     close(_listen_sock);//子进程不需要关心监听套接字
                //     Service(sock, srcIp, srcPort, handler);
                //     exit(0);
                // }
                // close(sock);//父进程不需要关心通信套接字

                //子进程执行处理，父进程继续获取链接
                pid_t pid = fork();
                if(pid == 0)
                {
                    close(_listen_sock);//子进程不需要关心监听套接字
                    if(fork() > 0)
                    {
                        exit(0);//子进程退出--会关闭资源
                    }
                    Service(sock, srcIp, srcPort, handler);//孙子进程处理通信连接
                    exit(0);//孤儿进程，init接管
                    
                }
                close(sock);//父进程不需要关心通信套接字
                waitpid(pid, nullptr, 0);//子进程已退出
                

            }

            
        }

    private:
        TcpSocket _sock;
        int _listen_sock;

        uint16_t _port;
        std::string _ip;

        int _gblaklog;
    };
}