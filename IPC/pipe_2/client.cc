#include"comm.hpp"

using namespace std;

int main()
{
    int fd = open(FILE_NAME, O_WRONLY);//写打开

    if(fd < 0)
    {
        perror("OPEN\n");

        return 1;
    }

    char msg[128];

    while(1)
    {
        msg[0] = '\0';//清空

        printf("请输入##：");

        fflush(stdout);

        ssize_t s = read(0, msg, sizeof(msg) - 1);
        if(s > 0)
        {
            msg[s] = '\0';
            write(fd, msg, strlen(msg));
        }
    }

    close(fd);//关闭文件

    return 0;
}