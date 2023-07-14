#include <iostream>
#include <memory>
#include "BQueue.hpp"
#include "Task.hpp"

void Cal(int l, int r, char op)
{
    switch (op)
    {
    case '+':
        printf("%d + %d = %d\n", l, r, l + r);
        break;
    case '-':
        printf("%d - %d = %d\n", l, r, l - r);
        break;
    case '*':
        printf("%d * %d = %d\n", l, r, l * r);
        break;
    default:
        break;
    }
}

void *Producer(void *arg)
{
    qlz::BQueue<qlz::Task> *bq = (qlz::BQueue<qlz::Task> *)arg;
    const char *OP = "+-*";
    while (true)
    {
        int l = rand() % 100 + 1;
        sleep(1);
        int r = rand() % 100 + 1;
        char op = *(rand() % 3 + OP);
        qlz::Task t(l, r, op, Cal);

        bq->Push(t);

        sleep(1);
    }
}
void *Consumer(void *arg)
{
    qlz::BQueue<qlz::Task> *bq = (qlz::BQueue<qlz::Task> *)arg;

    while (true)
    {
        sleep(2);

        qlz::Task t;
        bq->Pop(t);
        t.Run();
    }
}

int main()
{
    srand((unsigned int)time(nullptr));

    std::unique_ptr<qlz::BQueue<qlz::Task>> bq(new qlz::BQueue<qlz::Task>(5, Cal));

    pthread_t prod, cons;
    pthread_create(&prod, nullptr, Producer, bq.get());
    pthread_create(&cons, nullptr, Consumer, bq.get());
    pthread_join(prod, nullptr);
    pthread_join(cons, nullptr);

    return 0;
}