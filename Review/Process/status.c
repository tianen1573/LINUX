#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

// int main()
// {

//     pid_t pid;
//     if((pid = fork()) == -1)
//     {
//         perror("fork");
//         exit(1);
//     }

//     if(pid == 0)
//     {
//         sleep(20);
//         exit(10);
//     }
//     else
//     {
//         int st, ret;
//         if((ret = wait(&st)) == -1)
//         {
//             perror("wait");
//             exit(2);
//         }

//         //wait正常返回
//         if(ret > 0 && (st & 0x7f) == 0)
//         {
//             //子进程正常退出
//             printf("child exit code: %d\n", (st >> 8) & 0xff);//高八位
//         }
//         else if(ret > 0)
//         {
//             //异常退出
//             printf("sig code: %d\n", st & 0x7f);
//         }
//     }

//     return 0;
// }

// int main()
// {
//     pid_t pid;
//     pid = fork();
//     if (pid < 0)
//     {
//         printf("%s fork error\n", __FUNCTION__);
//         return 1;
//     }
//     else if (pid == 0)
//     { //child
//         printf("child is run, pid is : %d\n", getpid());
//         sleep(5);
//         exit(257);
//     }
//     else
//     {
//         int status = 0;
//         pid_t ret = waitpid(-1, &status, 0); //阻塞式等待，等待5S
//         printf("this is test for wait\n");
//         if (WIFEXITED(status) && ret == pid)
//         {
//             printf("wait child 5s success, child return code is :%d.\n", WEXITSTATUS(status));
//         }
//         else
//         {
//             printf("wait child failed, return.\n");
//             return 1;
//         }
//     }
//     return 0;
// }

int main()
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        printf("%s fork error\n", __FUNCTION__);
        return 1;
    }
    else if (pid == 0)
    { //child
        printf("child is run, pid is : %d\n", getpid());
        sleep(5);
        exit(1);
    }
    else
    {
        int status = 0;
        pid_t ret = 0;
        do
        {
            ret = waitpid(-1, &status, WNOHANG); //非阻塞式等待
            if (ret == 0)
            {
                printf("child is running\n");
            }
            sleep(1);
        } while (ret == 0);

        if (WIFEXITED(status) && ret == pid)
        {
            printf("wait child 5s success, child return code is :%d.\n", WEXITSTATUS(status));
        }
        else
        {
            printf("wait child failed, return.\n");
            return 1;
        }
    }
    return 0;
}