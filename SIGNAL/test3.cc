#include<cstdio>
#include<unistd.h>
#include<signal.h>

void printPending(sigset_t *pending)
{
    int i = 1;
    for(int i = 1; i <= 31; ++ i)
    {
        if(sigismember(pending, i))
            printf("1 ");
        else
            printf("0 ");
    }

    printf("\n");
}
void handler(int sig)
{
    printf("handler signal : %d\n", sig);
}
int main()
{
    sigset_t set, oldset;//输入型，输出型
    sigemptyset(&set);//清空
    sigemptyset(&oldset);

    sigaddset(&set, 2);//添加一个阻塞位
    sigprocmask(SIG_SETMASK, &set, &oldset);//通过OS改变当前进程的信号屏蔽字

    sigset_t pending;//未决集
    sigemptyset(&pending);//置空

    signal(2, handler);//自定义2号信号处理函数

    int cnt = 0;
    while(true)
    {
        sigpending(&pending);//输出型
        printPending(&pending);//打印
        sleep(1);
        ++ cnt;

        if(20 == cnt)
        {
            sigprocmask(SIG_SETMASK, &oldset, NULL);
            printf("恢复信号屏蔽字为原状态\n");
        }

    }


    return 0;
}