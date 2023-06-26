#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{

    int sta;
    pid_t pid;
    if ((pid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)
    {
        sleep(1);

        pid_t wpid = waitpid(pid, &sta, 0);
        // pid_t wpid = wait(&sta);
        printf("pid: %d, fork return: %d, wpid: %d, sta: %d\n", getpid(), pid, wpid, sta);
        sleep(1);
        return 0;
    }
    else
    {
        sleep(1);

        printf("pid: %d, fork return: %d\n", getpid(), pid);
        sleep(1);
        exit(1);
    }
}