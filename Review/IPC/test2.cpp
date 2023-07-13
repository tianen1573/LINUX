#include <cstdlib>
#include <cstdio>

#include <unistd.h>

#include <cstring>

#include <sys/wait.h> //
#include <sys/types.h>

int main()
{

    int fd[2] = {0};
    if (pipe(fd) < 0)
    {
        perror("pipe\n");
        return 1;
    }

    pid_t id = fork();

    if (id == 0) //子进程
    {
        close(fd[0]);

        const char *msg = "I am child, hello father\n";
        int cnt = 5;

        while (cnt--)
        {
            write(fd[1], msg, sizeof(msg));
            sleep(1);
        }

        close(fd[1]);
        exit(0);
    }

    //直接关闭文件
    close(fd[0]);
    close(fd[1]);

    int status = 0;
    waitpid(id, &status, 0);                           //关心子进程退出状态， 并阻塞等待
    printf("chile get signal : %d \n", status & 0x7f); //输出信号 -- 获取子进程status

    return 0;
}