#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unistd.h>
#include "thread.hpp"
#include "lockGuard.hpp"

const int g_thread_num = 10;
// 本质是: 生产消费模型
template <class T>
class ThreadPool
{
public:
    pthread_mutex_t *getMutex()
    {
        return &lock;
    }
    bool isEmpty()//任务队列
    {
        return task_queue_.empty();
    }
    void waitCond()//将lock释放掉，并阻塞在cond，等待唤醒，并尝试获取锁
    {
        pthread_cond_wait(&cond, &lock);
    }
    T getTask()//获取任务
    {
        T t = task_queue_.front();
        task_queue_.pop();
        return t;
    }

private:
    ThreadPool(int thread_num = g_thread_num) : num_(thread_num)//线程池线程个数
    {
        pthread_mutex_init(&lock, nullptr);//初始化锁
        pthread_cond_init(&cond, nullptr);//初始化条件变量
        for (int i = 1; i <= num_; i++)
        {
            threads_.push_back(new Thread(i, routine, this));//构建线程池
        }
    }
    ThreadPool(const ThreadPool<T> &other) = delete;//单例模式
    const ThreadPool<T> &operator=(const ThreadPool<T> &other) = delete;

public:
    // 单例模式 -- 考虑一下多线程使用单例的过程
    static ThreadPool<T> *getThreadPool(int num = g_thread_num)
    {   
        // 先判断再加锁
        // 可以有效减少未来必定要进行加锁检测的问题
        // 拦截大量的在已经创建好单例的时候，剩余线程请求单例的而直接访问锁的行为
        if (nullptr == thread_ptr) 
        {
            lockGuard lockguard(&mutex);//RAII锁
            // 但是，未来任何一个线程想获取单例，都必须调用getThreadPool接口
            // 但是，一定会存在大量的申请和释放锁的行为，这个是无用且浪费资源的
            // pthread_mutex_lock(&mutex);
            if (nullptr == thread_ptr)
            {
                thread_ptr = new ThreadPool<T>(num);
            }
            // pthread_mutex_unlock(&mutex);
        }
        return thread_ptr;
    }
    // 1. run()
    void run()
    {
        for (auto &iter : threads_)
        {
            iter->start();//构建线程
        }
    }
    
    
    // 2. pushTask() 生产
    void pushTask(const T &task)
    {
        //生产者模型
        lockGuard lockguard(&lock);//RAII锁
        task_queue_.push(task);
        pthread_cond_signal(&cond);//唤醒阻塞在cond的线程
    }

    // 3. 消费
    // 线程池本质也是一个生产消费模型
    // void *routine(void *args)
    // 消费过程 -- 消费者竞争
    static void *routine(void *args)
    {
        ThreadData *td = (ThreadData *)args;
        ThreadPool<T> *tp = (ThreadPool<T> *)td->args_;//线程池指针
        while (true)
        {
            T task;
            {
                lockGuard lockguard(tp->getMutex());//RAII锁 -- 静态函数只能访问静态成员
                while (tp->isEmpty())
                    tp->waitCond();//解锁，条件变量阻塞，被唤醒申请锁
                // 读取任务
                task = tp->getTask(); // 任务队列是共享的-> 将任务从共享，拿到自己的私有空间
            }
            task(td->name_);//得到了任务，每个任务有自己的处理方法
        }
    }
    
    ~ThreadPool()
    {
        for (auto &iter : threads_)//释放线程
        {
            iter->join();
            delete iter;
        }
        pthread_mutex_destroy(&lock);//销毁
        pthread_cond_destroy(&cond);//销毁
    }

private:
    std::vector<Thread *> threads_;//线程数组
    int num_;//线程个数
    std::queue<T> task_queue_;//任务队列

    static ThreadPool<T> *thread_ptr;//声明 单例模式线程池的指针
    static pthread_mutex_t mutex;//声明 单例模式的锁

    pthread_mutex_t lock;//任务的锁
    pthread_cond_t cond;//任务的条件变量
};
template <typename T>
ThreadPool<T> *ThreadPool<T>::thread_ptr = nullptr;

template <typename T>
pthread_mutex_t ThreadPool<T>::mutex = PTHREAD_MUTEX_INITIALIZER;