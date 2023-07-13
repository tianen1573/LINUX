#include "comm.hpp"

int main()
{
    int fd = open(FILE_NAME, O_WRONLY); // 写打开
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    char buff[1024];
    while(true)
    {
        buff[0] = '\0';

        // 显示器刷新策略默认为行刷新，下面的输出语句正常清空下是在进程退出和满的是啥才会刷新(因为没有换行标识符出现)
        // 所以，需要fflush强制刷新，以满足程序需求
        cout << "Please Enter# ";
        fflush(stdout);

        ssize_t s = read(0, buff, sizeof(buff) - 1); // 从显示器读数据
        if(s > 0)
        {
            // buff[s] = '\0'; // 保存换行符
            buff[s - 1] = '\0'; // 不保存

            write(fd, buff, strlen(buff)); // 写到管道
        }
    }

    return 0;
}