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
    int fd;
    FILE *fp;
    close(fd);

    const char *msg = "Hello IO\n";

    //等价
    fp = fopen("myfile", "w");
    fd = open("myfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    fclose(fp);
    close(fd); 
    
    fp = fopen("myfile", "w+");
    fd = open("myfile", O_WRONLY | O_CREAT | O_APPEND, 0644);
    fclose(fp);
    close(fd); 

    
    return 0;
}