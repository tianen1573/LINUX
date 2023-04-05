#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <cstdio>

// typedef std::function<void* (void*)> fun_t;
typedef void *(*fun_t)(void *);
typedef void (*Handler)(const std::string &req, std::string *resp);


class ThreadData
{
public:
    ThreadData(int sock, std::string ip, int port, Handler handler)
        : _sock(sock), _ip(ip), _port(port), _handler(handler)
    {
        
    }
    ~ThreadData()
    {
    }

public:
    int _sock;
    std::string _ip;
    int _port;
    Handler _handler;
};

class Thread
{
public:
    Thread(int sock, std::string ip, int port, Handler handler, fun_t callback) 
    : _func(callback)
    , _tdata(sock, ip, port, handler)
    {
        
    }
    void start()
    {
        pthread_create(&_tid, NULL, _func, (void *)&_tdata);
    }
    void join()
    {
        pthread_join(_tid, NULL);
    }

    ~Thread()
    {
    }

private:
    fun_t _func;
    ThreadData _tdata;
    pthread_t _tid;
};