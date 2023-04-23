#include<cstdio>
#include<sys/types.h>
#include<sys/stat.h>

#define FILE_NAME "myfifo"

int main()
{
    umask(0);//临时变量
    if(mkfifo(FILE_NAME, 0666) < 0)
    {
        perror("mkfifo\n");
        return 1;
    }

    return 0;
}