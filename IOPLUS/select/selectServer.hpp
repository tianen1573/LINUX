#pragma once

#ifndef __SELECT_SVR_H__
#define __SELECT_SVR_H__

#include <iostream>
#include <sys/select.h>
#include <time.h>

#include "log.hpp"
#include "TCP_scoket.hpp"

#define BITS 8
#define NUM (sizeof(fd_set) * 8)
#define FD_NONE -1

//select实现: 只完成读取，写入和异常不做处理
class SelectServer
{
public:
    SelectServer(const uint16_t &port = 8080)
        : _port(port)
    {
        //监听套接字
        _listenSock = _sock.Socket();
        _sock.Bind(_listenSock, _port);
        _sock.Listen(_listenSock);
        logMessage(DEBUG, "create base sockte succes");

        //初始化rfd数组
        //约定：_rfdArr[0] = _listenScok
        _rfdArr[0] = _listenSock;
        for (int i = 1; i < NUM; ++i)
            _rfdArr[i] = FD_NONE;
    }
    ~SelectServer()
    {
        if (_listenSock >= 0)
            close(_listenSock);
    }

public:
    void Start()
    {
        //如何看待listenSock？获取新连接，我们依旧把它看做成IO时间，如果没有连接到来，依然是阻塞
        //则调用accept，依旧会阻塞等

        while (true)
        {
            //添加合法的fd至位图中
            int maxFd = _listenSock;
            fd_set readFds;
            FD_ZERO(&readFds);
            for (int i = 0; i < NUM; ++i)
            {
                if (_rfdArr[i] == FD_NONE)
                    continue; //非法

                //合法
                FD_SET(_rfdArr[i], &readFds);        //添加
                maxFd = std::max(maxFd, _rfdArr[i]); //更新最大fd
            }

            //第五个参数
            struct timeval timeout = {5, 0}; //每隔5秒初始化一次 -- 秒，微妙

            //第一个参数是_listenSock+1，最大fd+1
            //1. ndfs: 随着我们获取到的sock越来越多，则添加到select的sock越多，注定了nfds每一次都可能变化，需要使他动态更新
            //2. readFds/writeFds/exceptFds：都是输入输出型参数，输入输出后可能会变化，所以每一次都要对readFds进行重新添加
            //3. timeout: 输入输出型参数，根据需要，需要进行重置
            //1，2=》：代表我们需要把合法的fd保存起来，1. 更新fd最大值，2.更新位图
            // int n = select(_listenSock+1, &readFds, nullptr, nullptr, &timeout);//阻塞timeout秒的等
            int n = select(maxFd + 1, &readFds, nullptr, nullptr, nullptr); //非阻塞的等
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
                HandlerEvent(readFds);                        //取走就绪的读事件
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

        //获取的新连接后怎么办？
        //肯定不能直接读取，recv/read，因为可能会阻塞在该文件读事件
        //应该把这个文件描述符添加到readFds，托管给select，让select监测对应的fd是否有读事件就绪
        //实际上，添加到自定义的合法fd数组中
        int pos = 1;
        for (; pos < NUM; ++pos)
        {
            if (_rfdArr[pos] == FD_NONE)//填补空位置
            {
                _rfdArr[pos] = sock;
                break;
            }
        }
        if (pos == NUM)//位图满了
        {
            logMessage(WARNING, "%s:%d", "select server already full, close: %d", sock);
            close(sock);
        }
    }
    void Recver(int &sock)//输入输出型参数
    {
        char buffer[1024];
        ssize_t s = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (s > 0)
        {
            buffer[s] = '\0';
            logMessage(DEBUG, "client[%d]# %s", sock, buffer);
        }
        else if (s == 0)
        {
            logMessage(DEBUG, "client[%d] quit, me too...", sock);
            //关闭
            close(sock);
            sock = FD_NONE;
        }
        else
        {
            logMessage(WARNING, "%d sock recv error, %d : %s", sock, errno, strerror(errno));
            //关闭
            close(sock);
            sock = FD_NONE;
        }
    }
    void HandlerEvent(const fd_set &rfds)
    {

        for (int i = 0; i < NUM; ++i)//遍历找
        {
            if (_rfdArr[i] == FD_NONE)
                continue;                    //不合法
            if (FD_ISSET(_rfdArr[i], &rfds)) //合法并就绪
            {
                if (i == 0 && _rfdArr[i] == _listenSock) //监听套接字就绪
                {
                    //读事件就绪：有新的连接
                    Accepter();
                }
                else//普通套接字就绪
                {
                    //读事件就绪：有数据到来
                    logMessage(DEBUG, "message in, get IO event: %d", _rfdArr[i]);
                    Recver(_rfdArr[i]);
                }
            }
        }
    }

private:
    TCP::TcpSocket _sock;
    int _listenSock;
    uint16_t _port;

    int _rfdArr[NUM]; //根据位图大小
};

#endif
