#include "udp_server.hpp"

//命令行提示
static void usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " port\n" << std::endl;
}

//命令行参数
// ./unp_server ip port
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        usage(argv[0]);
        exit(1);
    }

    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);
    UDP::UdpServer *Server = new UDP::UdpServer(ip, port);
    Server->Start();//启动服务器

    return 0;
}
