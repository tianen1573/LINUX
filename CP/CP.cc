#include"BlockQueue.hpp"
#include"Task.hpp"

void* Producer(void* arg)
{
    // CP::BlockQueue<int> *bq = (CP::BlockQueue<int>*)arg;
    CP::BlockQueue<Task> *bq = (CP::BlockQueue<Task>*)arg;

    const char* opArr = "+-*/%";

    while(1)
    {
        int left = rand() % 100 + 1;//1~100
        sleep(1);
        int rig = rand() % 100 + 1;//1~100
        int op = opArr[rand() % 5];

        Task t(left, rig, op);
        bq->Push(t);
        std::cout << "producer task done" << std::endl;
    }
}
void* Consumer(void* arg)
{
    // CP::BlockQueue<int> *bq = (CP::BlockQueue<int>*)arg;
    CP::BlockQueue<Task> *bq = (CP::BlockQueue<Task>*)arg;

    while(1)
    {
        // sleep(1);
        Task t;
        bq->Pop(t);
        t.Run();
    }
}

int main()
{
    srand( (unsigned int)time(nullptr) );

    //变量
    pthread_t proer, coner;
    // CP::BlockQueue<int> *bq = new CP::BlockQueue<int>;
    CP::BlockQueue<Task> *bq = new CP::BlockQueue<Task>;


    //生产者线程，消费者线程
    pthread_create(&proer, NULL, Producer, (void*)bq);
    pthread_create(&coner, NULL, Consumer, (void*)bq);

    //等待线程
    pthread_join(proer, NULL);
    pthread_join(coner, NULL);

    delete bq;

    return 0;
}