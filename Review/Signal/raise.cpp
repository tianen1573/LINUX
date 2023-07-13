#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
	printf("get a signal:%d\n", signo);
}
int main()
{
	signal(2, handler);
	while (1){
		sleep(1);
		raise(2);
	}
	return 0;
}
