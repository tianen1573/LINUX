#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <queue>

#define NUM 5

namespace CP
{
    template <class T>
    class BlockQueue
    {

    private:
        bool IsFull()//判满
        {
            return _que.size() == _maxCap;
        }
        bool IsEmpty()//判空
        {
            return _que.empty();
        }
    public:
        BlockQueue(int cap = NUM)
            : _maxCap(cap)
        {
            pthread_mutex_init(&_mtx, NULL);
            pthread_cond_init(&_full, NULL);
            pthread_cond_init(&_empty, NULL);
        }
        ~BlockQueue()
        {
            pthread_mutex_destroy(&_mtx);
            pthread_cond_destroy(&_full);
            pthread_cond_destroy(&_empty);
        }

        void Push(const T& data)
        {
            pthread_mutex_lock(&_mtx);//加锁
            while(IsFull())//判断资源
            {
                pthread_cond_wait(&_full, &_mtx);//等待
            }

            _que.push(data);

            pthread_mutex_unlock(&_mtx);//解锁
            pthread_cond_signal(&_empty);//唤醒，和解锁没有强制顺序
        }
        void Pop(T& data)
        {
            pthread_mutex_lock(&_mtx);
            while(IsEmpty())
            {
                pthread_cond_wait(&_empty, &_mtx);
            }

            data = _que.front();
            _que.pop();

            pthread_mutex_unlock(&_mtx);
            pthread_cond_signal(&_full);
        }

    private:
        std::queue<T> _que;
        int _maxCap;
        pthread_mutex_t _mtx;
        pthread_cond_t _full;
        pthread_cond_t _empty;
    };

}
