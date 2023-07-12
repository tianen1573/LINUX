#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>

#define NUM 1024

struct MyFILE_
{
    int fd;
    char buffer[1024];
    int end; //当前缓冲区的结尾
};
typedef struct MyFILE_ MyFILE;

MyFILE *fopen_(const char *pathname, const char *mode)
{
    assert(pathname);
    assert(mode);

    MyFILE *fp = NULL;

    if (strcmp(mode, "r") == 0)
    {
    }
    else if (strcmp(mode, "r+") == 0)
    {
    }
    else if (strcmp(mode, "w") == 0)
    {

        int fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0666);
        if (fd >= 0)
        {
            fp = (MyFILE *)malloc(sizeof(MyFILE));
            memset(fp, 0, sizeof(MyFILE));
            fp->fd = fd;
        }
    }
    else if (strcmp(mode, "w+") == 0)
    {
    }
    else if (strcmp(mode, "a") == 0)
    {
    }
    else if (strcmp(mode, "a+") == 0)
    {
    }
    else
    {
        ;
    }

    return fp;
}

//是不是应该是C标准库中的实现！
void fputs_(const char *message, MyFILE *fp)
{
    assert(message);
    assert(fp);

    strcpy(fp->buffer + fp->end, message); //abcde\0
    fp->end += strlen(message);

    //for debug
    printf("%s\n", fp->buffer);

    //暂时没有刷新, 刷新策略是谁来执行的呢？用户通过执行C标准库中的代码逻辑，来完成刷新动作
    //这里效率提高，体现在哪里呢？？因为C提供了缓冲区，那么我们就通过策略，减少了IO的执行次数(不是数据量)
    if (fp->fd == 0)
    {
        //标准输入
    }
    else if (fp->fd == 1)
    {
        //标准输出
        if (fp->buffer[fp->end - 1] == '\n')
        {
            //fprintf(stderr, "fflush: %s", fp->buffer); //2
            write(fp->fd, fp->buffer, fp->end);
            fp->end = 0;
        }
    }
    else if (fp->fd == 2)
    {
        //标准错误
    }
    else
    {
        //其他文件
    }
}

void fflush_(MyFILE *fp)
{
    assert(fp);

    if (fp->end != 0)
    {
        //暂且认为刷新了--其实是把数据写到了内核
        write(fp->fd, fp->buffer, fp->end);
        syncfs(fp->fd); //将数据写入到磁盘
        fp->end = 0;
    }
}

void fclose_(MyFILE *fp)
{
    assert(fp);
    fflush_(fp);
    close(fp->fd);
    free(fp);
}

int main()
{
    MyFILE *fp = fopen_("./log.txt", "w");
    if (fp == NULL)
    {
        printf("open file error");
        return 1;
    }

    fputs_("one: hello world", fp);

    fork();

    fclose_(fp);
}