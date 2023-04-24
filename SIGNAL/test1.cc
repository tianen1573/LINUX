#include<cstdio>
#include<unistd.h>

#include<signal.h>

void handler(int sig)
{
    printf("get a signal: %d\n", sig);
}

int main()
{

    signal(2, handler);
    while(true)
    {
        printf("hello signal!\n");
        sleep(1);
    }

    return 0;
}