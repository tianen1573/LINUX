#include "comm.hpp"

int main()
{
    umask(0);//设置局部文件权限默认掩码
    if(mkfifo(FILE_NAME, 0666) < 0)//创建命名管道
    {
        perror("mkfifio\n");
        return 1;
    }

    int fd = open(FILE_NAME, O_RDONLY);//读打开
    if(fd < 0)
    {
        perror("open\n");
        return 2;
    }

    int fdout = open("file-bat.txt", O_CREAT | O_WRONLY, 0666);//创建一个文件，将读到的数据，写到该文件里
    if(fdout < 0)
    {
        perror("open\n");
        return 3;
    }

    char msg[128];
    while(true)
    {
        msg[0] = '\0';

        ssize_t s = read(fd, msg, sizeof(msg) - 1);

        if(s > 0)
        {
            write(fdout, msg, s);
        }
        else if(s == 0)
        {
            printf("client quit! wtite end!\n");
            break;
        }
        else
        {
            printf("read error!\n");
            break;
        }
    }

    //进程结束时，会自动关闭文件
    close(fd);
    close(fdout);

    return 0;
}