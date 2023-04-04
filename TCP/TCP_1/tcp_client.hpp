#include "TCP_scoket.hpp"

namespace TCP
{
    class TcpClient
    {
    public:
        TcpClient(const uint16_t &descPort, const std::string &descIp)
            : _server_port(descPort), _server_ip(descIp)
        {

            // 1.创建套接字
            _sockfd = _sock.Socket();
            assert(_sockfd != -1);

            // 2.绑定套接字

            std::cout << "Client start" << std::endl;
        }

        void Request(std::string srcIp, int srcPort)
        {
            char buffer[1024];
            std::string req, resp;
            //直到通信关闭
            while (true)
            {
                std::cout << "Please Enter# ";
                std::getline(std::cin, req);

                write(_sockfd, req.c_str(), req.size());

                ssize_t size = read(_sockfd, buffer, sizeof(buffer) - 1);
                if (size > 0)
                {
                    buffer[size] = '\0';
                    resp = buffer;
                    std::cout << resp << std::endl;
                }
                if (size == 0) //服务端关闭
                {
                    std::cout << srcIp << "close" << std::endl;
                    break;
                }
                if (size < 0) //读取失败
                {
                    std::cout << "read error" << std::endl;
                    break;
                }
            }
        
        }
        void Start()
        {

            if (_sock.Connect(_sockfd, _server_ip, _server_port))
            {
                Request(_server_ip, _server_port);
            }
            close(_sockfd);

            std::cout << "client end" << std::endl;
        }

    private:
        TcpSocket _sock;
        int _sockfd;

        uint16_t _server_port;
        std::string _server_ip;
    };
}