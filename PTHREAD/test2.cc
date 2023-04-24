#include <cstdio>
#include<cstdlib>
#include<sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *Routine(void *arg)
{
    char *msg = (char *)arg;
    while (1)
    {
        printf("I am %s, and pid: %u, ppid: %u, tid: %u\n", msg, getpid(), getppid(), pthread_self());
        sleep(2);
    }
}

int main()
{
    pthread_t tid[5];
    for (int i = 0; i < 5; ++i)
    {
        char *buff = (char*)malloc(64);
        sprintf(buff, "thread %d", i);
        pthread_create(&tid[i], NULL, Routine, (void *)buff);
    }

    while (1)
    {
        printf("I am main thread, and pid: %u, ppid: %u, tid: %u\n", getpid(), getppid(), pthread_self());
        sleep(2);
    }

    return 0;
}