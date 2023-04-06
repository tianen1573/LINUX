#include "tcp_server.hpp"

static void usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " port\n" << std::endl;
}

//./server 8080


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        usage(argv[0]);
        exit(1);
    }

    uint16_t port = atoi(argv[1]);
   

    TCP::TcpServer Server(port);
    
    Server.Start();
    
    return 0;

}