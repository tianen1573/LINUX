#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdio>

int main()
{
    printf("pid: %d\n", getpid());
    printf("ppid: %d\n", getppid());


    while(1)
    {
        sleep(1);

        printf("I am %d\n", getpid());
    }

    return 0;
}