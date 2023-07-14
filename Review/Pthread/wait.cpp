#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void *Routine(void *arg)
{
    char *msg = (char *)arg;
    int count = 0;
    while (count < 2)
    {
        printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
        sleep(1);
        count++;
    }
    return (void *)2022;
}
int main()
{
    pthread_t tid[5];
    for (int i = 0; i < 5; i++)
    {
        char *buffer = (char *)malloc(64);
        sprintf(buffer, "thread %d", i);
        pthread_create(&tid[i], NULL, Routine, buffer);
        printf("%s tid is %lu\n", buffer, tid[i]);
    }
    printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
    for (int i = 0; i < 5; i++)
    {
        void *ret = NULL;
        pthread_join(tid[i], &ret);
        printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int)ret); // g++ wait.cpp -lpthread -fpermissive
        printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int*)ret);
    }
    return 0;
}