#include <cstdio>

#include <cstdlib>
#include <unistd.h>

#include <pthread.h>
#include <sys/types.h>

pthread_t _g_main_threadid;

void *Routine(void *arg)
{
    pthread_detach(pthread_self());
    char *msg = (char *)arg;
    int cnt = 0;
    while (cnt < 5)
    {
        printf("I am %s, and pid: %u, ppid: %u, tid: %u\n", msg, getpid(), getppid(), pthread_self());
        sleep(1);
        ++cnt;
    }

    return (void *)8848;
    // pthread_exit((void*)9969);
}

int main()
{
    _g_main_threadid = pthread_self();
    pthread_t tid[5];
    for (int i = 0; i < 5; ++i)
    {
        char *buff = (char *)malloc(64);
        sprintf(buff, "thread %d", i);
        pthread_create(&tid[i], NULL, Routine, (void *)buff);
        printf("%s tid is %u\n", buff, tid[i]);
    }

    while (1)
    {
        printf("I am main thread, and pid: %u, ppid: %u, tid: %u\n", getpid(), getppid(), pthread_self());
        sleep(1);
    }

    return 0;
}