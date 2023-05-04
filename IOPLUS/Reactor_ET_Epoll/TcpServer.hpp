#pragma once

#include "TcpSocket.hpp"
#include "log.hpp"
#include "Epoll.hpp"
#include "Protocol.hpp"

#include <functional>
#include <vector>

class TcpServer;

//ET模式， 决定常规套接字必须要有自己的独立的接收缓冲区&&发送缓冲区
class Connection
{
    using func_t = std::function<void(Connection *)>;

public: //默认函数
    Connection(int sock = -1)
        : _sock(sock), _tsvr(nullptr)
    {
    }

    ~Connection()
    {
    }

public: //成员函数
    //设置回调函数
    void SetHandler(func_t recv_cb, func_t send_cb, func_t except_cb)
    {
        _recv_cb = recv_cb;
        _send_cb = send_cb;
        _except_cb = except_cb;
    }

public:        //成员变量
               //设置为私有，暴露Get函数
    int _sock; //负责IO的文件描述符

    //三个回调函数，对sock进行特定的处理事件方法
    func_t _recv_cb;   //读回调
    func_t _send_cb;   //写回调
    func_t _except_cb; //异常回调

    //接收缓冲区&&发送缓冲区
    std::string _inBuffer; //暂时无法处理二进制流，文本可以
    std::string _outBuffer;

    //设置对TcpServer的回值指针 -- 查找映射
    TcpServer *_tsvr;

    //时间戳 -- 断开不活跃链接
    uint64_t _lastTimeStamp;
};

class TcpServer
{
private: //静态全局变量
    static const uint16_t default_port = (uint16_t)8080;
    static const int gNum = 128;

    using func_t = std::function<void(Connection *)>;                           //回调函数类型
    using callback_t = std::function<void(Connection *, std::string &request)>; //业务处理函数类型

public: //六大函数
    TcpServer(const uint16_t &port = default_port)
        : _port(port), _revs_num(gNum)
    {
        //1. 创建监听套接字
        _listenSock = TCP::TcpSocket::Socket();
        TCP::TcpSocket::Bind(_listenSock, _port);
        TCP::TcpSocket::Listen(_listenSock);

        //2. 创建Epoll对象
        _epoll.CreateEpoll();

        //3. 添加_listenSock到Epoll模型中 -- 套接字不再是裸奔状态，具有各自的回调方法，缓冲区
        AddConnection(_listenSock, std::bind(&TcpServer::Accepter, this, std::placeholders::_1), nullptr, nullptr); //不要忽略了this指针

        //4. 构建一个获取就绪事件的缓冲区
        _revs = new struct epoll_event[_revs_num];
    }
    ~TcpServer()
    {
        if (_listenSock >= 0)
            close(_listenSock);
        if (_revs != nullptr)
            delete _revs;
    }

public: //成员函数
    void Accepter(Connection *conn)
    {
        conn->_lastTimeStamp = time(nullptr);//更新最近访问时间

        //此时_listenSock文件上的读事件一定就绪了，一定有新连接到来
        // logMessage(DEBUG, "Accepter() been called");

        //获取链接
        //此时，我们必须循环获取，直到该次调用没有新连接到来，强制要求
        while (true)
        {
            std::string clientIp;
            uint16_t clientPort;
            int accept_errno = 0;
            int sock = TCP::TcpSocket::Accept(_listenSock, &clientIp, &clientPort, &accept_errno);
            if (sock < 0)
            {
                if (accept_errno == EAGAIN || accept_errno == EWOULDBLOCK)
                    break; //读取完毕，无新连接了
                else if (accept_errno == EINTR)
                    continue; //被信号中断，继续读取
                else
                {
                    //失败
                    logMessage(WARNING, "accept error, %d : %s", accept_errno, strerror(accept_errno));
                    break;
                }
            }
            //添加到Epoll模型
            if (sock >= 0)
            {
                AddConnection(sock, std::bind(&TcpServer::Recver, this, std::placeholders::_1),
                              std::bind(&TcpServer::Sender, this, std::placeholders::_1),
                              std::bind(&TcpServer::Excepter, this, std::placeholders::_1));

                logMessage(DEBUG, "accept success, get a new line success : [%s : %d]", clientIp.c_str(), sock);
            }
        }
    }
    void Recver(Connection *conn)
    {
        // logMessage(DEBUG, "Recver() been called");

        conn->_lastTimeStamp = time(nullptr);//更新最近访问时间
        const int num = 1024; //缓冲区大小
        bool err = false;     //错误结束
        //--v1: 直接面向字节流，先进行常规读取
        //v2: 循环读取，解决粘报，业务处理
        while (true)
        {
            char buffer[num];

            ssize_t n = recv(conn->_sock, buffer, sizeof(buffer) - 1, 0);
            if (n < 0)
            {
                if (errno == EAGAIN || errno == EWOULDBLOCK) //读完
                    break;
                else if (errno == EINTR) //被中断
                    continue;
                else //异常出错
                {
                    logMessage(ERROR, "recv error, %d : %s", errno, strerror(errno));
                    conn->_except_cb(conn); //把异常交给回调函数处理
                    err = true;
                    break;
                }
            }
            else if (n == 0) //对端关闭连接
            {
                logMessage(DEBUG, "client[%d] quit, server close [%d]", conn->_sock, conn->_sock);
                conn->_except_cb(conn);
                err = true;
                break;
            }
            else
            {
                buffer[n] = 0;
                conn->_inBuffer += buffer; //保存到独立的缓冲区
            }
        } //此时代表这一次把数据读完了，接收的是字节流，需要解码，模拟个网络计算器协议

        //解码
        if (!err)
        {
            logMessage(DEBUG, "conn->_inbuffer[sock: %d]: %s", conn->_sock, conn->_inBuffer.c_str());

            std::vector<std::string> messages;         //保存完整报文
            SpliteMessage(conn->_inBuffer, &messages); //按协议切割，解决粘报问题

            //此时msg一定是一个完整报文
            for (auto &msg : messages)
            {
                _cb(conn, msg); //交付给上层处理
            }
        }
    }
    void Sender(Connection *conn)
    {
        conn->_lastTimeStamp = time(nullptr);//更新最近访问时间

        while (true)
        {
            ssize_t n = send(conn->_sock, conn->_outBuffer.c_str(), conn->_outBuffer.size(), 0);
            if (n > 0)
            {
                conn->_outBuffer.erase(0, n);
                if (conn->_outBuffer.empty())
                    break; //本次读取，读取完了
            }
            else
            {
                if (errno == EAGAIN || errno == EWOULDBLOCK) //出错了， 但还有数据
                    break;
                else if (errno == EINTR) //被中断，重新继续发送
                    continue;
                else //异常出错
                {
                    logMessage(ERROR, "send error, %d : %s", errno, strerror(errno));
                    conn->_except_cb(conn); //把异常交给回调函数处理
                    break;
                }
            }

            //循环发送
        }
        //数据发送完毕，关闭该fd的写权限
        if (conn->_outBuffer.empty())
        {
            EnableReadWrite(conn, true, false);
        }
        else //出错了，重新触发， 继续发
        {
            EnableReadWrite(conn, true, true);
        }
    }
    void Excepter(Connection *conn)
    {
        if (!IsConnectionExists(conn->_sock))
            return; //不存在了
        //1. 从epoll中移除
        bool res = _epoll.DelFromEpoll(conn->_sock);
        assert(res);
        //2. 从connections映射中移除
        _connections.erase(conn->_sock);
        //3. 关闭sock
        close(conn->_sock);
        //4. 释放conn
        delete conn;

        logMessage(DEBUG, "Excepter been called, and OK...");
    }

    void ConnectAliveCheck()
    {
        uint64_t timeout = 3;
        std::vector<Connection*> delConns;
        //遍历所有的conn， 去除不活跃的conn
        for(auto &iter : _connections)//不能直接在unordered_map删除，会引起迭代器失效问题
        {
            if(iter.first == _listenSock) continue;//忽略监听套接字

            uint64_t curTime = time(nullptr);
            if(curTime - iter.second->_lastTimeStamp > timeout)
                delConns.push_back(iter.second);

        }
        for(auto &iter : delConns)
        {
            iter->_except_cb(iter);
            logMessage(DEBUG, "This is an inactive link.");
        }
    }
    int LoopOnce()
    {
        int timeout = 1000;
        int n = _epoll.WaitEpoll(_revs, _revs_num, timeout);

        for (int i = 0; i < n; ++i)
        {
            int sock = _revs[i].data.fd;
            uint32_t revents = _revs[i].events;

            //统一异常处理
            //将所有的异常，交给read/write统一处理：通过读写失败，调用异常回调
            if(revents & EPOLLERR) revents |= (EPOLLIN | EPOLLOUT);
            if(revents & EPOLLHUP) revents |= (EPOLLIN | EPOLLOUT);

            //读事件
            if (revents & EPOLLIN)
            {
                //存在，并且具有合法的读事件的回调函数
                if (IsConnectionExists(sock) && _connections[sock]->_recv_cb)
                {
                    _connections[sock]->_recv_cb(_connections[sock]);
                }
            }
            //写事件
            if (revents & EPOLLOUT)
            {
                if (IsConnectionExists(sock) && _connections[sock]->_send_cb)
                {
                    _connections[sock]->_send_cb(_connections[sock]);
                }
            }
            //异常事件
            //...
        }
    }
    //根据就绪的事件， 进行特定事件的派发
    void Dispather(callback_t cb)
    {
        _cb = cb;
        //ET模式
        while (true)
        {
            LoopOnce();
            ConnectAliveCheck();
        }
    }

    void EnableReadWrite(Connection *conn, const bool readAble, const bool writeAble)
    {
        uint32_t events = (readAble ? EPOLLIN : 0) | (writeAble ? EPOLLOUT : 0);

        bool res = _epoll.CtrlEpoll(conn->_sock, events);
        assert(res);
    }

    bool IsConnectionExists(int sock)
    {
        return _connections.find(sock) != _connections.end();
    }

    void AddConnection(int sock, func_t recv_cb, func_t send_cb, func_t except_cb)
    {

        //0. 将文件设置为非阻塞状态
        TCP::TcpSocket::SetNonBlock(sock);
        //1. 创建Connection对象
        Connection *conn = new Connection(sock);
        //2. 设置回调
        conn->SetHandler(recv_cb, send_cb, except_cb);
        //3. 设置回值指针, 时间戳
        conn->_tsvr = this;
        conn->_lastTimeStamp = time(nullptr);
        //4. 将sock[]添加到_epoll中
        // a. sock添加到epoll模型
        _epoll.AddSockToEpoll(sock, EPOLLIN | EPOLLET); //任何多路转接服务器，只会默认关心读事件，且默认是LT模式，写事件按需关心
        // b. 建立映射
        _connections.insert({sock, conn});

    }

private: //成员变量
    //网络
    int _listenSock;
    uint16_t _port;

    //Epoll
    Epoll _epoll;

    //管理sock与Connection的映射
    std::unordered_map<int, Connection *> _connections; //sock : connection

    //就绪事件
    struct epoll_event *_revs;
    int _revs_num;

    //上层业务处理函数
    callback_t _cb;
};
const uint16_t TcpServer::default_port;
const int TcpServer::gNum;
