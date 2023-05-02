#pragma once

#ifndef __EPOLL_SERVER_HPP__
#define __EPOLL_SERVER_HPP__

#include "TCP_scoket.hpp"
#include "log.hpp"
#include "epoll.hpp"

#include <sys/epoll.h>
#include <cassert>
#include <functional>
class EpollServer
{
private:
    static const uint16_t default_port = (uint16_t)8080;
    static const int gNum = 64;

    using func_t = std::function<void(std::string)>;

public:
    EpollServer(func_t HandlerRequest, const uint16_t &port = default_port, const int &num = gNum)
        : _port(port), _revsSize(num), _HandlerRequest(HandlerRequest)
    {
        //0. 申请空间
        _revs = new struct epoll_event[_revsSize];

        //1. 创建监听套接字
        //创建， 绑定， 监听
        _listenSock = TCP::TcpSocket::Socket();
        TCP::TcpSocket::Bind(_listenSock, _port);
        TCP::TcpSocket::Listen(_listenSock);

        //2. 创建epoll模型
        _epfd = Epoll::CreateEpoll();

        logMessage(DEBUG, "init success, listenSock: %d, epfd: %d", _listenSock, _epfd);

        //3. 添加_listenSock到Epoll
        if (Epoll::CtlEpoll(_epfd, EPOLL_CTL_ADD, _listenSock, EPOLLIN))
        {
            logMessage(DEBUG, "add listenSock to epoll success.");
        }
        else
        {
            logMessage(ERROR, "add listenSock to epoll error.");
            exit(6);
        }
    }
    ~EpollServer()
    {
        //关闭文件
        if (_listenSock >= 0)
            close(_listenSock);
        if (_epfd >= 0)
            close(_epfd);
    }

public:
    void Accepter()
    {

        //此时_listenSock文件上的读事件一定就绪了，有新连接到来

        //获取链接
        std::string clientIp;
        uint16_t clientPort;
        int sock = TCP::TcpSocket::Accept(_listenSock, &clientIp, &clientPort);
        if (sock < 0)
        {
            logMessage(WARNING, "accept error");
            return;
        }
        logMessage(DEBUG, "get a new line success : [%s : %d]", clientIp.c_str(), sock);

        //添加到Epoll模型
        if (Epoll::CtlEpoll(_epfd, EPOLL_CTL_ADD, sock, EPOLLIN))
        {
            logMessage(DEBUG, "add listenSock to epoll success.");
        }
        else
        {
            logMessage(ERROR, "add listenSock to epoll error.");
        }
    }
    void Recver(int sock) //输入输出型参数
    {

        char buffer[1024];
        ssize_t s = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (s > 0)
        {
            buffer[s] = '\0';
            // logMessage(DEBUG, "client[%d]# %s", sock, buffer);
            _HandlerRequest(buffer);
        }
        else if (s == 0) //对端关闭
        {
            logMessage(NORMAL, "client[%d] quit, me too...", sock);

            //从模型中删掉该sock
            //先删再关：Epoll要求操作时，必须是合法的fd，所以需要先删
            if (Epoll::CtlEpoll(_epfd, EPOLL_CTL_DEL, sock, 0))
            {
                close(sock);
                logMessage(DEBUG, "client[%d] quit, close quit sock", sock);
            }
            else
            {
                logMessage(ERROR, "del sock to epoll error.");
                assert(false);
            }
        }
        else //读取失败
        {
            logMessage(WARNING, "%d sock recv error, %d : %s", sock, errno, strerror(errno));
            //从模型中删掉该sock
            //先删再关：Epoll要求操作时，必须是合法的fd，所以需要先删
            if (Epoll::CtlEpoll(_epfd, EPOLL_CTL_DEL, sock, 0))
            {
                close(sock);
                logMessage(DEBUG, "client recv %d error, close errot sock", sock);
            }
            else
            {
                logMessage(ERROR, "del sock to epoll error.");
                assert(false);
            }
        }
    }
    void HandlerEvents(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            uint32_t revents = _revs[i].events;
            int sock = _revs[i].data.fd;
            if (revents & EPOLLIN)
            {
                if (sock == _listenSock) //监听套接字
                {
                    Accepter();
                }
                else //普通读事件
                {
                    Recver(sock);
                }
            }
        }
    }
    void LoopOnce(int timeout)
    {
        int n = Epoll::WaitEpoll(_epfd, _revs, _revsSize, timeout);
        switch (n)
        {
        case 0:
            logMessage(DEBUG, "timeout...");
            break;
        case -1:
            logMessage(WARNING, "epoll wait error: %s", strerror(errno));
            break;
        default:
            logMessage(DEBUG, "git a new event");
            HandlerEvents(n);
            break;
        }
    }
    void Start()
    {
        int timeout = 1000;
        while (true)
        {
            LoopOnce(timeout);
        }
    }

private:
    //网络编程
    int _listenSock;
    uint16_t _port;

    //Epoll编程
    int _epfd; //epoll模型
    struct epoll_event *_revs;
    int _revsSize;

    //回调函数
    func_t _HandlerRequest;
};

const uint16_t EpollServer::default_port;
const int EpollServer::gNum;

#endif