#pragma once

#include <pthread.h>
#include <functional>

#include <cstring>
#include <cstdio>
#include <iostream>

// typedef std::function<void*(void*)> fun_t;
typedef void*(*fun_t)(void*);

class ThreadDate
{
public:
    void *args;
    std::string name;
};

class Thread
{

    public:
    Thread(int num, fun_t callback, void *args)
    : _func(callback)
    {
        //构建线程名
        char nameBuff[64];
        snprintf(nameBuff, sizeof(nameBuff), "Thread-%d", num);

        _name = nameBuff;

        //填充数据
        _tdata.name = _name;
        _tdata.args = args;
    }

    void Start()
    {
        pthread_create(&_tid, nullptr, _func, (void*)&_tdata);
    }
    void Join()
    {
        pthread_join(_tid, nullptr);
    }

    std::string Name()
    {
        return _name;
    }

    private:
    std::string _name;//线程名字
    fun_t _func;//线程执行函数
    ThreadDate _tdata;//数据
    pthread_t _tid;//线程tid

};