#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>

int main()
{

    pid_t pid;

    printf("Before: pid is %d\n", getpid());

    if((pid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    printf("After: pid is %d, fork return %d\n", getpid(), pid);
    
    // sleep(1);
    fflush(stdout);
    return 0;
}