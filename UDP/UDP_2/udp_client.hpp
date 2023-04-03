#pragma once

#include "udp_scoket.hpp"

namespace UDP
{
    class UdpClient
    {
    public:
        UdpClient()
        {
        }
        UdpClient(uint16_t port, std::string ip)
            : _server_port(port), _server_ip(ip)
        {
            assert(_sock.Socket());

            std::cout << "Client Star" << std::endl;

        }
        ~UdpClient()
        {
            _sock.Close();
        }

        //1. 创建套接字
        //2. 绑定端口号
        //3. 发送数据
        bool SendTo(const std::string &buf)
        {
            return _sock.Sendto(buf, _server_ip, _server_port);
        }
        //4. 接收数据
        bool RecvFrom(std::string *buf)
        {
            return _sock.RecvFrom(buf);
        }

    private:
        UdpSocket _sock;
        std::string _server_ip;
        uint16_t _server_port;
    };
}