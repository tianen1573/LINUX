#include<unistd.h>
#include<pthread.h>
#include<cstdio>

pthread_mutex_t mtx;

void* Routine(void*arg)
{
    pthread_mutex_lock(&mtx);
    pthread_mutex_lock(&mtx);


    pthread_mutex_unlock(&mtx);

    pthread_exit((void*)0);

}

int main()
{   
    pthread_mutex_init(&mtx, NULL);

    pthread_t tid;
    pthread_create(&tid, NULL, Routine, NULL);

    pthread_join(tid, NULL);

    pthread_mutex_destroy(&mtx);

    return 0;
}