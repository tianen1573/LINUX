#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
	printf("get a signal:%d\n", sig);
}

int main()
{
	signal(2, handler); //注册2号信号
	while (1){
		printf("hello signal!\n");
		sleep(1);
	}
	return 0;
}
