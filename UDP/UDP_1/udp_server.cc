#include "udp_server.hpp"

//��������ʾ
static void usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " port\n" << std::endl;
}

//�����в���
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
    Server->Start();//����������

    return 0;
}
