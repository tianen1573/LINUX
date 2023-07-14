#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void handler(int signo)
{
    printf("get a signal: %d\n", signo);
    int ret = 0;
    while ((ret = waitpid(-1, NULL, WNOHANG)) > 0) // 一次未决到递达期间， 可能多个子进程退出
    {
        printf("wait child %d success\n", ret);
    }
}
int main()
{
    signal(SIGCHLD, handler);
    if (fork() == 0)
    {
        //child
        printf("child is running, begin dead: %d\n", getpid());
        sleep(3);
        exit(1);
    }
    //father
    while (1)
        ;
    return 0;
}
