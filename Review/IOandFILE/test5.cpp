#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    //C
    printf("hello printf\n");
    fprintf(stdout, "hello fprintf\n");
    const char *s = "hello fputs\n";
    fputs(s, stdout);
    
    //OS
    const char *ss = "hello write\n";
    write(1, ss, strlen(ss));
    
    fork();
    
    return 0;
}