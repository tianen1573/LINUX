#include<cstdio>
#include<pthread.h>
#include<iostream>

pthread_mutex_t _g_mtx;
pthread_cond_t _g_cond;

void* Routine(void* arg)
{
    pthread_detach(pthread_self());

    std::cout << (char*)arg << "run..." << std::endl;
    
    while(1)
    {
        pthread_mutex_lock(&_g_mtx);//加锁进入临界区

        //是否满足
        pthread_cond_wait(&_g_cond, &_g_mtx);//条件变量，一定要在加锁解锁中间等待

        std::cout << (char*)arg << "runing..." << std::endl;

        pthread_mutex_unlock(&_g_mtx);//解锁出临界区
    }
}

int main()
{

    pthread_mutex_init(&_g_mtx, NULL);
    pthread_cond_init(&_g_cond, NULL);

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, Routine, (void*)"thread 1");
    pthread_create(&t2, NULL, Routine, (void*)"thread 2");
    pthread_create(&t3, NULL, Routine, (void*)"thread 3");

    while(1)
    {
        getchar();//手动阻塞
        pthread_cond_signal(&_g_cond);
    }

    pthread_mutex_destroy(&_g_mtx);
    pthread_cond_destroy(&_g_cond);

    return 0;
}