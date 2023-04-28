#pragma once

#include "lockGuard.hpp"
#include "thread.hpp"

#include <vector>
#include <queue>

const int _g_thread_num = 10; //默认的最大线程数

template <class T>
class ThreadPool
{

private:
    ThreadPool(int numT = _g_thread_num)
        : _num(numT)
    {
        //初始化任务队列线程安全变量
        pthread_mutex_init(&_mtxQueue, nullptr);
        pthread_cond_init(&_cond, nullptr);

        //填充线程
        for (int i = 0; i < _num; ++i)
        {
            //i：构建线程id
            //routine：回调函数
            //this：数据指针
            _threads.push_back(new Thread(i, routine, (void *)this));
        }
    }
    //单例模式
    ThreadPool(const ThreadPool<T>& tp) = delete;
    const ThreadPool<T>& operator=(const ThreadPool<T> &tp) = delete;
public:

    static ThreadPool<T>* GetThreadPool(int numT = _g_thread_num)
    {
        
        //只有单例线程池不存在的时候，才需要加锁创建，保证线程安全
        //先判断再加锁，可以减少竞争锁消耗的性能

        if(nullptr == _threadPtr)
        {
            lockGuard lg(&_mtx);//加锁， RAII锁
            
            //一开始，若有多个线程都调用Get接口，则会有大量的线程阻塞在竞争锁状态
            //当第一个线程创建单例线程池后，其他线程仍会继续竞争这个锁，往下执行
            //我们再判断一次，避免多次创建
            if(nullptr == _threadPtr)
            {
                _threadPtr = new ThreadPool<T>(numT);//生成线程类对象
                _threadPtr->Run();
            }
        }//出作用域，RAII释放资源，解锁

        return _threadPtr;
    }
    
    ~ThreadPool()
    {
        //释放线程
        for(auto &thr : _threads)
        {
            thr->Join();//释放线程
            delete thr;//释放空间
        }

        //销毁
        pthread_mutex_destroy(&_mtxQueue);
        pthread_cond_destroy(&_cond);
        //线程池的锁是静态分配的，不需要销毁
    }

public:

    pthread_mutex_t* GetMtx()//任务队列锁
    {
        return &_mtxQueue;
    }

    bool IsEmpty()//任务队列是否空
    {
        return _taskQueue.empty();
    }
    void WaitCond()
    {
        pthread_cond_wait(&_cond, &_mtxQueue);
    }

    T GetTask()
    {
        //执行该函数时，一定时线程安全的

        T t = _taskQueue.front();
        _taskQueue.pop();

        return t;
    }

public:

    //执行线程池
    void Run()
    {
        for(auto & iter : _threads)
        {
            iter->Start();//真正的生成线程
        }
    }

    //生产任务 -- 生产 -- 外部使用
    void PushTask(const T &task)
    {
        lockGuard lg(&_mtxQueue);

        _taskQueue.push(task);

        pthread_cond_signal(&_cond);//存在任务了，唤醒等待的线程
    }

    //回调函数 -- 消费 -- 线程使用
    static void *routine(void *args)
    {
        ThreadDate *td = (ThreadDate*)args;
        ThreadPool<T> *tp = (ThreadPool<T>*)td->args;

        while(true)
        {
            T task;
            //RAII
            {
                //私有成员，外界不能获取
                lockGuard lg(tp->GetMtx());

                //同步 -- 条件变量
                while(tp->IsEmpty())
                {
                    tp->WaitCond();
                }
                
                //获取任务
                task = tp->GetTask();

            }

            //此时我们已经获取任务了，我们使用的时模板编译
            //这个任务如何执行，是可以自定义的，比如Run函数，重载括号运算符
            //这里我使用Run函数

            //执行任务
            task.Run();//我明确知道task具有Run函数，或者所有的模板变量T都要具有Run
        }
    }

private:
    int _num;
    std::vector<Thread *> _threads; //线程组
    std::queue<T> _taskQueue;       //任务队列

    pthread_mutex_t _mtxQueue; //任务队列互斥锁
    pthread_cond_t _cond;      //任务队列条件变量

    //单例模式 -- 声明
    static ThreadPool<T> *_threadPtr; //指针
    static pthread_mutex_t _mtx;      //单例模式锁
};

//定义
template <class T>
ThreadPool<T> *ThreadPool<T>::_threadPtr = nullptr;
template <class T>
pthread_mutex_t ThreadPool<T>::_mtx = PTHREAD_MUTEX_INITIALIZER; //静态分配锁
