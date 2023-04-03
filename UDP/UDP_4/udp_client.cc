#include "udp_client.hpp"
#include "thread.hpp"
#include <memory>

//命令行提示
static void usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " ip : port\n"
              << std::endl;
}

static void *udpSend(void *args)
{
    UDP::UdpClient *Client = (UDP::UdpClient *)(((ThreadData *)(args))->args_);
    std::string req;

    for (;;)
    {
        std::cout << std::endl;
        std::getline(std::cin, req);

        Client->SendTo(req);
    }
}
static void *udpRecv(void *args)
{
    UDP::UdpClient *Client = (UDP::UdpClient *)(((ThreadData *)(args))->args_);
    std::string resp;

    for (;;)
    {
        std::cout << std::endl;
        Client->RecvFrom(&resp);
        std::cout << resp;
    }
}

// ./udp_server ip port
int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        usage(argv[0]);
    }
    UDP::UdpClient *Client = new UDP::UdpClient(atoi(argv[2]), argv[1]);

    std::unique_ptr<Thread> sender(new Thread(1, udpSend, (void *)Client));
    std::unique_ptr<Thread> recver(new Thread(2, udpRecv, (void *)Client));

    sender->start();
    recver->start();

    sender->join();
    recver->join();

    

    return 0;
}