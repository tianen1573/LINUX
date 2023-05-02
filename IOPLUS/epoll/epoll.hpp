#pragma once

#include <iostream>
#include <sys/epoll.h>

class Epoll
{
private:
    static const int gSize = 256;

public:
    static int CreateEpoll()
    {
        int epfd = epoll_create(gSize);
        if (epfd > 0)
            return epfd;
        
        exit(5);//失败直接终止
    }
    static bool CtlEpoll(int epfd, int oper, int sock, uint32_t events)
    {
        struct epoll_event ev;
        ev.events = events;
        ev.data.fd = sock;

        int n = epoll_ctl(epfd, oper, sock, &ev);

        return n == 0;
    }

    static int WaitEpoll(int epfd, struct epoll_event* events, int num, int timeout)
    {
        //细节1. 如果底层就绪的sock非常多，一次拿不完怎么办？不影响，可以下一次拿；或者进行扩容
        //细节2. wait的返回值：有几个fd上的事件就绪，就返回及，并且返回的时候，会将所有就绪的event按照顺序放入到revs数组中，所以这个返回值能保证我们高效有序的遍历
        return epoll_wait(epfd, events, num, timeout);
    }
};