#include"TcpServer.hpp"

#include <memory>

int main()
{

    std::unique_ptr<TcpServer> tsvr(new TcpServer());
    tsvr->Dispather();

    return 0;
}