#include "selectServer.hpp"
#include <memory>
int main()
{

    // fd_set fds;

    std::unique_ptr<SelectServer> svr(new SelectServer());
    svr->Start();

    return 0;
}