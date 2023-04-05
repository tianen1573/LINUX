#pragma once

#include "TCP_scoket.hpp"
#include "thread.hpp"
#include <memory>

namespace TCP
{
    class TcpServer
    {
    public:
        static void *HandlerRequest(void *args)
        {
            pthread_detach(pthread_self()); //分离线程
            ThreadData *p = (ThreadData *)(args);

            
            //直接把Service的逻辑搬过来也可以
            Service(p->_sock, p->_ip, p->_port, p->_handler); //线程为客户端提供服务

            return nullptr;
        }

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

        static void Service(int sock, std::string srcIp, int srcPort, Handler handler)
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

            while (true)
            {
                // 4. 获取链接
                // a. 保存通信方信息
                std::string srcIp;
                uint16_t srcPort;
                int sock = _sock.Accept(_listen_sock, &srcIp, &srcPort);
                if (sock < 0)
                    continue;

                //创建线程请求
                Thread *Ser(new Thread(sock, srcIp, srcPort, handler, HandlerRequest));
                Ser->start();
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