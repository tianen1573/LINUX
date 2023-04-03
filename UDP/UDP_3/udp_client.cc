#include "udp_client.hpp"

//命令行提示
static void usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " ip : port\n"
              << std::endl;
}

// ./udp_server ip port
int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        usage(argv[0]);
    }
    UDP::UdpClient *Client = new UDP::UdpClient(atoi(argv[2]), argv[1]);

    for (;;)
    {
        std::string req;
        std::string resp;
        std::cout << std::endl;
        std::getline(std::cin, req);

        Client->SendTo(req);
        Client->RecvFrom(&resp);
        std::cout << std::endl;

        std::cout << resp;
    }

    return 0;
}