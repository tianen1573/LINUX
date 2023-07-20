#include <iostream>
#include <cstring>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

class Sem
{
public:
    Sem()
    {
    }
    Sem(int num)
    {
        sem_init(&_sem, 0, num);
    }
    ~Sem()
    {
        sem_destroy(&_sem);
    }

    void P()
    {
        sem_wait(&_sem);
    }
    void V()
    {
        sem_post(&_sem);
    }

private:
    sem_t _sem;
};

Sem sem(1);//二元信号量，等价于互斥锁
int tickets = 2000;

void *TicketGrabbing(void *arg)
{
    std::string name = (char *)arg;

    while (true)
    {
        sem.P();
        if (tickets > 0)
        {
            usleep(100);
            std::cout << name << "get a ticket, tickets left: " << --tickets << std::endl;
            sem.V();
        }
        else
        {
            sem.V();
            break;
        }
    }
    //现象， 某个线程一直能抢到票
    //二元信号量相当于互斥锁，且没有同步操作，
    //所以很大概率上，一个线程在执行完V操作时，仍在它的时间片，就仍能申请到信号量

    std::cout << name << "quit..." << std::endl;
    return (void *)0;
}

int main()
{
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, TicketGrabbing, (void *)"thread 1");
    pthread_create(&t2, NULL, TicketGrabbing, (void *)"thread 2");
    pthread_create(&t3, NULL, TicketGrabbing, (void *)"thread 3");
    pthread_create(&t4, NULL, TicketGrabbing, (void *)"thread 4");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    return 0;
}