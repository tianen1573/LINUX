#pragma once

#include "udp_scoket.hpp"

namespace UDP
{
    class UdpServer
    {
    public:
        UdpServer()
        {
        }
        UdpServer(uint16_t port, std::string ip = "")
            : _port(port)
        {
            assert(_sock.Socket());
        }
        ~UdpServer()
        {
            _sock.Close();
        }

        bool Start(Handler handler)
        {
            //1. 创建套接字
            //2. 绑定端口号
            bool ret = _sock.Bind(_port);
            if (!ret)
            {
                return false;
            }

            std::cout << "Server Star" << std::endl;

            //3. 等待连接
            for (;;)
            {
                //4. 读取请求
                std::string req;
                std::string remote_ip;
                sockaddr_in peer;
                uint16_t remote_port = 0;
                bool ret = _sock.RecvFrom(&req, &remote_ip, &remote_port); //输入型参数
                if (!ret)
                    continue; //没读到数据，并不返回

                //保存用户
                auto it = _users.find(remote_ip);
                if (it == _users.end())
                {
                    sockaddr_in addr;
                    bzero(&addr, sizeof(addr));
                    addr.sin_family = AF_INET;
                    addr.sin_addr.s_addr = inet_addr(remote_ip.c_str());
                    addr.sin_port = htons(remote_port);

                    _users[remote_ip] = addr;
                }

                //5. 处理请求
                std::string resp;
                handler(req, &resp, remote_ip);

                //6. 返回请求
                for(auto it = _users.begin(); it != _users.end(); ++ it)
                {
                     _sock.Sendto(resp, inet_ntoa(it->second.sin_addr), ntohs(it->second.sin_port));
                }
                printf("[%s:%d] req: %s\n", remote_ip.c_str(), remote_port, req.c_str());
            }

            //7. 关闭套接字   --基本不执行
            _sock.Close();
            return true;
        }

    private:
        UdpSocket _sock;
        std::string _ip;
        uint16_t _port;
        std::unordered_map<std::string, sockaddr_in> _users;
        std::queue<std::string> messageQueue;
    };
}