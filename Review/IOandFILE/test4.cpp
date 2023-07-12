#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main()
{
    umask(0);

    // close(1);
    // int fd = open("stdout.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    // if(fd < 0)
    // {
    //     perror("open");
    //     return 1;
    // }
    // cerr << fd << std::endl;

    // cout << "I am stdout!\n";
    // cerr << "I am stderr!\n";


    // close(0);
    // int fd = open("OSio.txt", O_RDONLY);
    // if(fd < 0)
    // {
    //     perror("open");
    //     return 1;
    // }
    // cout << fd << std::endl;

    // char buff[1024];
    // fgets(buff, sizeof buff, stdin);
    // cout << buff;

    // close(1);
    // int fd = open("stdout.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    // if(fd < 0)
    // {
    //     perror("open");
    //     return 1;
    // }
    // cout << "I want cin to stdout(monitor).\n";

    int fd = open("dup2.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }
    if(dup2(3, 1) == -1) // oldfd copy to newfl, 即 fd:1指向的文件 变更为 fd:3指向的文件
    {
        perror("dup2");
        return 1;
    }

    cout << "I want cout to stdout(monitor).\n";

    return 0;
}