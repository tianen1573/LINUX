#pragma once

#include "TcpSocket.hpp"
#include "log.hpp"
#include "Epoll.hpp"

#include <functional>

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
};

class TcpServer
{
private: //静态全局变量
    static const uint16_t default_port = (uint16_t)8080;
    static const int gNum = 128;
    using func_t = std::function<void(Connection *)>;

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

        //此时_listenSock文件上的读事件一定就绪了，有新连接到来
        logMessage(DEBUG, "Accepter been called");
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

        // //添加到Epoll模型
        // if (Epoll::CtlEpoll(_epfd, EPOLL_CTL_ADD, sock, EPOLLIN))
        // {
        //     logMessage(DEBUG, "add listenSock to epoll success.");
        // }
        // else
        // {
        //     logMessage(ERROR, "add listenSock to epoll error.");
        // }
    }


    int LoopOnce()
    {
        int timeout = 1000;
        int n = _epoll.WaitEpoll(_revs, _revs_num, timeout);

        for(int i = 0; i < n; ++ i)
        {
            int sock = _revs[i].data.fd;
            uint32_t revents = _revs[i].events;

            //读事件
            if(revents & EPOLLIN)
            {   
                //存在，并且具有合法的读事件的回调函数
                if(IsConnectionExists(sock) && _connections[sock]->_recv_cb)
                {
                    _connections[sock]->_recv_cb(_connections[sock]);
                }
            }
            //写事件
            if(revents & EPOLLOUT)
            {
                if(IsConnectionExists(sock) && _connections[sock]->_send_cb)
                {
                    _connections[sock]->_send_cb(_connections[sock]);
                }
            }
            //异常事件
            //...
        }
    }
    //根据就绪的事件， 进行特定事件的派发
    void Dispather()
    {
        //ET模式
        while (true)
        {
            LoopOnce();
        }
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
        Connection *conn = new Connection(_listenSock);
        //2. 设置回调
        conn->SetHandler(recv_cb, send_cb, except_cb);
        //3. 设置回值指针
        conn->_tsvr = this;
        //4. 将sock[]添加到_epoll中
        // a. sock添加到epoll模型
        _epoll.AddSockToEpoll(_listenSock, EPOLLIN | EPOLLET); //任何多路转接服务器，只会默认关心读事件，且默认是LT模式，写事件按需关心
        // b. 建立映射
        _connections.insert({_listenSock, conn});
    }

private: //成员变量
    //网络
    int _listenSock;
    uint16_t _port;

    //Epoll
    Epoll _epoll;

    //管理sock与Connection的映射
    std::unordered_map<int, Connection *> _connections; //sock : connection

    //
    struct epoll_event *_revs;
    int _revs_num;
};
const uint16_t TcpServer::default_port;
const int TcpServer::gNum;
