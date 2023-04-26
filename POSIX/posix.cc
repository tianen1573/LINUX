#include"RingQueue.hpp"
#include"Task.hpp"

void* Producer(void* arg)
{
    RQ::RingQueue<Task> *rq = (RQ::RingQueue<Task>*)arg;

    const char* opArr = "+-*/%";

    while(1)
    {
        int left = rand() % 100 + 1;//1~100
        sleep(1);
        int rig = rand() % 100 + 1;//1~100
        int op = opArr[rand() % 5];

        
        Task t(left, rig, op);
        rq->Push(t);
        std::cout << "producer task done" << std::endl;
    }
}
void* Consumer(void* arg)
{
    RQ::RingQueue<Task> *rq = (RQ::RingQueue<Task>*)arg;

    while(1)
    {
        // sleep(1);
        Task t;
        rq->Pop(t);
        t.Run();
    }
}

int main()
{
    srand( (unsigned int)time(nullptr) );

    //变量
    pthread_t proer, coner;
    RQ::RingQueue<Task> *rq = new RQ::RingQueue<Task>();

    //生产者线程，消费者线程
    pthread_create(&proer, NULL, Producer, (void*)rq);
    pthread_create(&coner, NULL, Consumer, (void*)rq);

    //等待线程
    pthread_join(proer, NULL);
    pthread_join(coner, NULL);

    delete rq;

    return 0;
}