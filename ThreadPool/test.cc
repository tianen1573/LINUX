#include<iostream>

#include"Task.hpp"
#include"threadPool.hpp"

#include<unistd.h>

int main()
{

    ThreadPool<Task> *tp = ThreadPool<Task>::GetThreadPool();
    tp->Run();
    //推荐创建好线程池后就润，因为该逻辑我们不能保证只润一次
    //但服务器程序，我们可以保证只Run一次，因为服务器只启动一次

    while(true)
    {
        sleep(1);

        Task t;

        tp->PushTask(t);
        
    }

    return 0;
}