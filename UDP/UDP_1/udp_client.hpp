#pragma once



#include <sys/types.h>  //ͨ������
#include <sys/socket.h> //�׽��ֺ���
#include <netinet/in.h> //�ṹ��
#include <arpa/inet.h>  //�ṹ��

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <unistd.h> //�ļ�����

namespace UDP
{
    class UdpClient
    {
    public:
        UdpClient()
        {
        }
        UdpClient(std::string ip, uint16_t port)
            : _server_ip(ip), _server_port(port)
        {
            // 1. �����׽���
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sockfd < 0) // ʧ�ܷ���-1
            {
                std::cout << "socket error" << std::endl;
            }
            else
            {
                std::cout << "socket create success, sockfd: " << _sockfd << std::endl;
            }
        }
        void Start()
        {
            // 2. ��
            //���ڿͻ��ˣ����ǲ���Ҫ�ֶ���IP+�˿ںţ���Ϊ�ͻ��˲����Ǳ������ӵģ����������ӵķ�����
            //��ô�ͻ�����Ҫ֪����������IP+�˿ںţ��������IP+�˿ںŻ���ͨ�Ź����н�����������
            //������һ�㲢�����ͻ����׽��ֽ��а󶨲������������һ����OS���У��� ����IP+����Ķ˿ں�

            // 3. �������� -- ��������
            // a. ΪĿ����������̴���ͨ�����ݽṹ
            struct sockaddr_in server;
            server.sin_family = AF_INET;                            // ͨ������
            server.sin_port = htons(_server_port);                  // ����ת����
            server.sin_addr.s_addr = inet_addr(_server_ip.c_str()); // ����ת����
            // b. �������ͻ�����
            std::string sentdoBuf;
            std::string recvBuf;

            // c.��������
            for (;;)
            {
                std::cout << "client # ";
                std::cin >> sentdoBuf;
                ssize_t write_size = sendto(_sockfd, sentdoBuf.c_str(), sentdoBuf.size(), 0, (const sockaddr *)&server, sizeof(server));
                if (write_size == 0)
                {
                    std::cout << "server sockfd is closed" << std::endl;
                    return;
                }
                else if (write_size < 0)
                {
                    std::cout << "sentdo error " << std::endl;
                    return;
                }
                else
                {
                    std::cout << "sendto sussess." << std::endl;
                }
            }
        }
        ~UdpClient()
        {
            if (_sockfd >= 0)
            {
                close(_sockfd);
            }
        }

    private:
    private:
        uint16_t _server_port;  // 16λ�˿ں�
        std::string _server_ip; // �ַ�����IP
        int _sockfd;            // �׽��֣����ļ�������
    };
}