#include<cstdio>
#include<unistd.h>
#include<pthread.h>

void* Routine(void* arg)
{
    char *msg = (char*)arg;
    while(1)
    {
        printf("I am %s, and pid: %d, ppid: %d\n", msg, getpid(), getppid());
        sleep(1);
    }
    
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, Routine, (void*)"thread 1");

    while(1)
    {
        printf("I am main thread, and pid: %d, ppid: %d\n", getpid(), getppid());
        sleep(2);
    }

    return 0;
}