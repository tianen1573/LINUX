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
            while (true)
            {
                // 4. 获取链接
                // a. 保存通信方信息
                std::string srcIp;
                uint16_t srcPort;
                int sock = _sock.Accept(_listen_sock, &srcIp, &srcPort);
                if (sock < 0)
                    continue;
                
                //当前服务器只能执行一条通信
                //一个结束才能另一个

                Service(sock, srcIp, srcPort, handler);

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