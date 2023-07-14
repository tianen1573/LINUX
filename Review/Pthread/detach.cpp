#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	pthread_detach(pthread_self());
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
	}
	pthread_exit((void*)6666);
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	while (1){
		printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
		sleep(1);
	}
	return 0;
}