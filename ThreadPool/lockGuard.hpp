
#pragma once

#include <iostream>
#include <pthread.h>

class Mutex
{
public:
    Mutex(pthread_mutex_t *mtx)
        : _pmtx(mtx)
    {
    }
    ~Mutex()
    {
    }

    void Lock()
    {
        pthread_mutex_lock(_pmtx);
    }
    void UnLock()
    {
        pthread_mutex_unlock(_pmtx);
    }

private:
    pthread_mutex_t *_pmtx; //只接收锁， 不创建
};

//RAII
class lockGuard
{
public:
    lockGuard(pthread_mutex_t *mtx)
        : _mutex(mtx)
    {
        _mutex.Lock();
    }
    ~lockGuard()
    {
        _mutex.UnLock();
    }

private:
    Mutex _mutex;
};