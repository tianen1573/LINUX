#pragma once

#ifndef __Poll_SVR_H__
#define __Poll_SVR_H__

#include <iostream>
#include <time.h>
#include <sys/poll.h>

#include "log.hpp"
#include "TCP_scoket.hpp"

#define BITS 8
#define NUM (sizeof(fd_set) * 8)
#define FD_NONE -1

//select实现: 只完成读取，写入和异常不做处理
class PollServer
{
public:
    static const nfds_t _nfds = 100;//声明
public:
    PollServer(const uint16_t &port = 8080)
        : _port(port)
    {
        //监听套接字
        _listenSock = _sock.Socket();
        _sock.Bind(_listenSock, _port);
        _sock.Listen(_listenSock);
        logMessage(DEBUG, "create base sockte succes");

        //初始化pollfd
        _fds = new struct pollfd[_nfds];
        for(int i = 0; i < _nfds; ++ i)
        {
            _fds[i].fd = FD_NONE;
            _fds[i].events = _fds[i].revents = 0;
        }
        _fds[0].fd = _listenSock;
        _fds[0].events = POLLIN;

        //等待时间
        _timeout = 1000;
    }
    ~PollServer()
    {
        if (_listenSock >= 0)
            close(_listenSock);
        if(_fds) delete _fds;
    }

public:
    void Start()
    {
        //如何看待listenSock？获取新连接，我们依旧把它看做成IO时间，如果没有连接到来，依然是阻塞
        //则调用accept，依旧会阻塞等

        while (true)
        {

            int n = poll(_fds, _nfds, _timeout); //非阻塞的等
            //作为服务器，rfds中会有两种套接字，一是检测套接字，另一种是普通套接字
            //所以还需要区分两种套接字，指定不同的处理方法
            switch (n)
            {
            case 0:
                logMessage(DEBUG, "time out ...");
                break;
            case -1:
                logMessage(WARNING, "select error : %d : %s", errno, strerror(errno));
                break;
            default:
                logMessage(DEBUG, "get a new link event..."); //问什么一直打印连接到来？连接到了，你没取走，会一直通知
                HandlerEvent();                        //取走就绪的读事件
                break;
            }
        }
    }

private:
    void Accepter()
    {

        //此时_listenSock文件上的读事件一定就绪了，有新连接到来

        //获取链接
        std::string clientIp;
        uint16_t clientPort;
        int sock = _sock.Accept(_listenSock, &clientIp, &clientPort);
        if (sock < 0)
        {
            logMessage(WARNING, "accept error");
            return;
        }
        logMessage(DEBUG, "get a new line success : [%s : %d]", clientIp.c_str(), sock);

        int pos = 1;
        for (; pos < NUM; ++pos)
        {
            if (_fds[pos].fd == FD_NONE)//填补空位置
            {
                _fds[pos].fd = sock;
                _fds[pos].events = POLLIN;
                break;
            }
        }
        if (pos == NUM)//pollfd数组满了
        {
            //理论上poll是没上限的，可以在这里对_fds扩容
            logMessage(WARNING, "%s:%d", "select server already full, close: %d", sock);
            close(sock);
        }
    }
    void Recver(int pos)//输入输出型参数
    {
        char buffer[1024];
        ssize_t s = recv(_fds[pos].fd, buffer, sizeof(buffer) - 1, 0);
        if (s > 0)
        {
            buffer[s] = '\0';
            logMessage(DEBUG, "client[%d]# %s", _fds[pos].fd, buffer);
        }
        else if (s == 0)//对端关闭
        {
            logMessage(DEBUG, "client[%d] quit, me too...", _fds[pos].fd);
            //关闭
            close(_fds[pos].fd);
           _fds[pos].fd = FD_NONE;
           _fds[pos].events = POLLNVAL;
        }
        else//读取失败
        {
            logMessage(WARNING, "%d sock recv error, %d : %s", _fds[pos].fd, errno, strerror(errno));
            //关闭
            close(_fds[pos].fd);
            _fds[pos].fd = FD_NONE;
           _fds[pos].events = POLLNVAL;
        }
    }
    void HandlerEvent()
    {

        for (int i = 0; i < NUM; ++i)//遍历找
        {
            if (_fds[i].fd == FD_NONE)
                continue;                    //不合法
            if (_fds[i].revents & POLLIN) //合法并就绪
            {
                if (i == 0 && _fds[i].fd == _listenSock) //监听套接字就绪
                {
                    //读事件就绪：有新的连接
                    Accepter();
                }
                else//普通套接字就绪
                {
                    //读事件就绪：有数据到来
                    logMessage(DEBUG, "message in, get IO event: %d", _fds[i].fd);
                    Recver(i);
                }
            }
        }
    }

private:

    TCP::TcpSocket _sock;
    int _listenSock;
    uint16_t _port;

    struct pollfd *_fds;
    int _timeout;
};

const nfds_t PollServer::_nfds;//定义

#endif
