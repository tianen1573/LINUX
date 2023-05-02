
#include "epollServer.hpp"
#include <memory>

void Change(std::string request)
{
    //业务逻辑

    std::cout << "Change# " << request << std::endl;

}

int main()
{

    std::unique_ptr<EpollServer> epoll_svr(new EpollServer(Change));
    epoll_svr->Start();


    return 0;
}