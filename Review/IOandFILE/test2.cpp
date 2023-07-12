#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main()
{
    umask(0);                                            // 设置该进程的临时umask
    int fd = open("OSio.txt", O_WRONLY | O_CREAT, 0644); // 文件路径， 打开方式， umask
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    const char *msg = "Hello OSio\n";
    char buff[1024];

    int cnt = 5;
    while (cnt--)
    {
        ssize_t s = write(fd, msg, strlen(msg)); // 写到fd中， 从msg中读， 读strlen()个大小为1字节的元素
    }
    close(fd);

    fd = open("OSio.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    while (true)
    {
        ssize_t s = read(fd, buff, strlen(msg));
        if (s > 0)
        {
            buff[s] = '\0';
            printf("%s", buff);
        }
        else
        {
            break;
        }
    }

    close(fd);
    return 0;
}