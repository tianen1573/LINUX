#pragma once

#include "TCP_scoket.hpp"
#include "ThreadPool/Task.hpp"
#include "ThreadPool/threadPool.hpp"
#include <memory>

namespace TCP
{
    class TcpServer
    {
    public:
        static void ServiceEcho(int sock, const std::string &srcIp, int srcPort, const std::string &name)
        {
            char buffer[1024];
            //直到通信关闭
            while (true)
            {
                ssize_t size = read(sock, buffer, sizeof(buffer) - 1);
                if (size > 0)
                {
                    buffer[size] = '\0';

                    std::string req = buffer;
                    std::string resp;
                    resp = '[' + srcIp + ':' + std::to_string(srcPort) + "]# " + req + '\n';
                    std::cout << name << " execute and resp is : " << resp << std::endl;
                    write(sock, resp.c_str(), resp.size());
                }
                if (size == 0) //客户端关闭
                {
                    std::cout << srcIp << " close" << std::endl;
                    break;
                }
                if (size < 0) //读取失败
                {
                    std::cout << "read error " << std::endl;
                    break;
                }
            }
            close(sock);
        }

    public:
        TcpServer(const uint16_t &port, const std::string &ip = "", const int gbl = 5)
            : _port(port), _ip(ip)
        {

            // 1.创建套接字
            _listen_sock = _sock.Socket();
            assert(_listen_sock != -1);

            // 2.绑定监听套接字
            _sock.Bind(_listen_sock, _port);

            // 3.监听套接字
            _sock.Listen(_listen_sock);

            // 4.获取线程池 -- 单例
            _tp = ThreadPool<Task>::getThreadPool(); //可以写在初始化列表中

            std::cout << "server start" << std::endl;
        }

        void Start()
        {

            //线程池只有一个，需要启动：创建进程执行处理
            //服务器也只有一个，我们可以手动run，也可以在创建好线程池的时候，去润
            _tp->run();

            while (true)
            {
                // 4. 获取链接
                // a. 保存通信方信息
                std::string srcIp;
                uint16_t srcPort;
                int sock = _sock.Accept(_listen_sock, &srcIp, &srcPort);
                if (sock < 0)
                    continue;

                //生成任务
                Task t(sock, srcIp, srcPort, ServiceEcho);
                _tp->pushTask(t);
            }
        }

    private:
        TcpSocket _sock;
        int _listen_sock;

        uint16_t _port;
        std::string _ip;

        ThreadPool<Task> *_tp; //线程池
    };
}