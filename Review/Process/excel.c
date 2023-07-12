#include <unistd.h>
int main()
{
    char *const argv[] = {"ps", "-ef", NULL};
    char *const envp[] = {"PATH=/bin:/usr/bin:/bin/ps", NULL};

    // // base版，需要带全路径，命令以链表形式出现
    // execl("/bin/ps", "ps", "-ef", NULL);
    // // 带p的，可以使用环境变量PATH，无需写全路径
    // execlp("ps", "ps", "-ef", NULL);
    // 带e的，需要自己组装环境变量
    execle("ps", "ps", "-ef", NULL, envp);

    // // base版，需要带全路径， 命令以数组形式出现
    // execv("/bin/ps", argv);
    // // 带p的，可以使用环境变量PATH，无需写全路径
    // execvp("ps", argv);
    // // 带e的，需要自己组装环境变量
    // execve("/bin/ps", argv, envp);

    exit(0);

    return 0;
}