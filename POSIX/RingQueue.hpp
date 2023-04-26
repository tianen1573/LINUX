#pragma once

#include <iostream>
#include <cstring>
#include <vector>

#include <unistd.h>

#include <pthread.h>
#include <semaphore.h>

#define NUM 8

namespace RQ
{
    template <class T>
    class RingQueue
    {

    private:
        void P(sem_t &s)
        {
            sem_wait(&s);
        }
        void V(sem_t &s)
        {
            sem_post(&s);
        }

    public:
        RingQueue(int cap = NUM)
            : _cap(cap), _p_pos(0), _c_pos(0) //临界区资源最大数， 待生产下标， 待消费下标
        {
            _que.resize(_cap);
            sem_init(&_blank_sem, 0, _cap); //空间资源初始为_cap
            sem_init(&_data_sem, 0, 0);     //数据资源初始为0
        }
        ~RingQueue()
        {
            sem_destroy(&_blank_sem);
            sem_destroy(&_data_sem);
        }

    public:
        void Push(const T &data)
        {
            P(_blank_sem);       //申请空间信号量
            _que[_p_pos] = data; //放入资源
            V(_data_sem);        //生成资源信号量

            //实现的是单消费者单生成者模型
            //移动
            ++_p_pos;
            _p_pos %= _cap;
        }
        void Pop(T &data)
        {
            P(_data_sem);        //申请资源信号量
            data = _que[_c_pos]; //拿取资源
            V(_blank_sem);       //生成空间信号量

            ++_c_pos;
            _c_pos %= _cap;
        }

    private:
        sem_t _blank_sem;
        sem_t _data_sem;

        int _p_pos;
        int _c_pos;

        int _cap;

        std::vector<T> _que;
    };
}