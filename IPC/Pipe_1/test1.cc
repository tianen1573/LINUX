#include<cstdio>
#include<unistd.h>
#include<cstring>
#include<cstdlib>

#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fd[2] = {0};

    // if(pipe(fd) < 0)
    if(pipe2(fd, O_NONBLOCK) < 0)
    {
        perror("pipe");
        return 1;
    }

    pid_t id = fork();

    if(id == 0)//子进程
    {
        close(fd[0]);//子进程关闭读端

        const char* msg = "I am child, hello father...";
        int cnt = 10;

        while(cnt --)
        {
            write(fd[1], msg, sizeof(msg));

        }

        //关闭文件并退出
        close(fd[1]);
        exit(0);

    }

    //父进程
    close(fd[1]);

    char buffer[1024];
    while(1)
    {
                    sleep(1);
        ssize_t s = read(fd[0], buffer, sizeof(buffer) - 1);

        if(s > 0)//正常读
        {
            buffer[s] == '\0';//按字符串方式输出
            printf("child send to father : %s\n", buffer);
        }
        else if(s == 0)//写端关闭
        {
            printf("read file end\n");
            break;
        }
        else//失败
        {
            printf("read error\n");
            break;
        }
    }
    
    close(fd[0]);//关闭文件
    waitpid(id, NULL, 0);//等待进程
    return 0;
}