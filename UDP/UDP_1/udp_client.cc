#include "udp_client.hpp"

//命令行提示
static void usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " ip  port\n" << std::endl;
}

//命令行参数
// ./unp_client ip port
int main(int argc, char* argv[])
{

    if(argc != 3)
    {
        usage(argv[0]);
        exit(1);
    }

    std::string server_ip = argv[1];
    uint16_t server_port = atoi(argv[2]);

    UDP::UdpClient *Client = new UDP::UdpClient(server_ip, server_port);//初始化客户端
    Client->Start();//启动客户端


    return 0;
}