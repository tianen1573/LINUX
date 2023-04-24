#include<cstdlib>
#include<cstdio>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

void* Routine(void *arg)
{
    char *msg = (char*)arg;
    int cnt = 0;
    while(cnt < 5)
    {
        printf("I am %s, and pid: %u, ppid: %u, tid: %u\n", msg, getpid(), getppid(), pthread_self());
        sleep(2);
        ++ cnt;
    }

    return (void*)8848;
}

int main()
{
    pthread_t tid[5];
    for (int i = 0; i < 5; ++i)
    {
        char *buff = (char*)malloc(64);
        sprintf(buff, "thread %d", i);
        pthread_create(&tid[i], NULL, Routine, (void *)buff);
        printf("%s tid is %u\n", buff, tid[i]);
    }

    printf("I am main thread, and pid: %u, ppid: %u, tid: %u\n", getpid(), getppid(), pthread_self());
    for(int i = 0; i < 5; ++ i)
    {
        void *ret = NULL;//输出型参数
        pthread_join(tid[i], &ret);//等待线程退出
        printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], ((int)ret));
    }

    return 0;
}