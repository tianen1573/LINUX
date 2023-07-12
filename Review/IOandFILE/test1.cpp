#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    FILE *fp = fopen("io.txt", "w");
    if (nullptr == fp)
    {
        perror("fopen");
        return 1;
    }

    const char *msg = "Hello C++!\n";
    int cnt = 5;
    while (cnt--)
    {
        ssize_t s = fwrite((void *)msg, 1, strlen(msg), fp); // 从ptr读， 一个元素的字节为size，读n个元素，写到fp中
        //每次写的时候，文件指针都在移动
    }
    fclose(fp);

    fp = fopen("io.txt", "r");
    if (nullptr == fp)
    {
        perror("fopen");
        return 1;
    }
    char buff[1024];
    while (true)
    {
        ssize_t s = fread(buff, 1, strlen(msg), fp);
        if (s > 0)
        {
            buff[s] = '\0';
            printf("%s", buff);
        }

        if (feof(fp)) // 读到结尾
        {
            break;
        }
    }
    fclose(fp);

    return 0;
}