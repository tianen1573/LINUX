#include "RingQueue.hpp"

void* Producer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		// sleep(1);
		int data = rand() % 100 + 1;
		rq->Push(data);
		std::cout << "Producer: " << data << std::endl;
	}
}
void* Consumer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		// sleep(1);
		int data = 0;
		rq->Pop(data);
		std::cout << "Consumer: " << data << std::endl;
	}
}
int main()
{
	srand((unsigned int)time(nullptr));
	pthread_t producer1, consumer1, producer2, consumer2;
	RingQueue<int>* rq = new RingQueue<int>;
	// pthread_create(&producer1, nullptr, Producer, rq);
	pthread_create(&consumer1, nullptr, Consumer, rq);
    pthread_create(&producer2, nullptr, Producer, rq);
	pthread_create(&consumer2, nullptr, Consumer, rq);
	
	// pthread_join(producer1, nullptr);
	pthread_join(consumer1, nullptr);
    pthread_join(producer2, nullptr);
	pthread_join(consumer2, nullptr);
	delete rq;
	return 0;
}