#include <iostream>
#include <signal.h>

using namespace std;


int main()
{
    sigset_t sset;

    sigemptyset(&sset);

    sigfillset(&sset);

    sigaddset(&sset, SIGINT);

    sigdelset(&sset, SIGINT);

    sigismember(&sset, SIGINT);

    return 0;
}