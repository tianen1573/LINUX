#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>

int main()
{
    int ret = fork();

    if (ret < 0) //err
    {
        perror("fork");
        return 1;
    }
    else if (ret == 0) //child
    {
        printf("I am child, pid: %d, ret: %d\n", getpid(), ret);
    }
    else
    {
        printf("I am father, pid: %d, ret: %d\n", getpid(), ret);
    }

    sleep(1);
    return 0;
}
