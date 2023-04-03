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
                uint16_t remote_port = 0;
                bool ret = _sock.RecvFrom(&req, &remote_ip, &remote_port); //输入型参数
                if (!ret)
                    continue; //没读到数据，并不返回

                //5. 处理请求
                std::string resp;
                handler(req, &resp);

                //6. 返回请求
                _sock.Sendto(resp, remote_ip, remote_port);
                printf("[%s:%d] req: %s, resp: %s\n", remote_ip.c_str(), remote_port,
                       req.c_str(), resp.c_str());
            }

            //7. 关闭套接字   --基本不执行
            _sock.Close();
            return true;
        }

    private:
        UdpSocket _sock;
        std::string _ip;
        uint16_t _port;
    };
}