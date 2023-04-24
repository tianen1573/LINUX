#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
// int main( void )
// {
//      pid_t pid;
//      if ( (pid=fork()) == -1 )
//      perror("fork"),exit(1);
//      if ( pid == 0 )
//      {
//          printf("%d\n", getpid());
//          sleep(20);
//          exit(10);
//      } 
//      else 
//      {
//          int st;
//          int ret = wait(&st);

//          if ( ret > 0 && ( st & 0X7F ) == 0 )
//          { // 正常退出
//          	printf("child exit code:%d\n", (st>>8) & 0XFF);
//          }
//          else if( ret > 0 ) 
//          { // 异常退出
//          	printf("sig code : %d\n", st & 0XFF );
//          }
//      }
// }

int main()
{
	if (fork() == 0){
		//child
		printf("I am running...\n");
		int *p = NULL;
		*p = 100;
		exit(0);
	}
	//father
	int status = 0;
	waitpid(-1, &status, 0);
	printf("exitCode:%d, coreDump:%d, signal:%d\n",
		(status >> 8) & 0xff, (status >> 7) & 1, status & 0x7f); //0x7f: 去掉core dump标志
	return 0;
}