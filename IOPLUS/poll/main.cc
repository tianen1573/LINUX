#include "pollServer.hpp"
#include <memory>



int main()
{

    // fd_set fds;

    std::unique_ptr<PollServer> svr(new PollServer());
    svr->Start();

    return 0;
}