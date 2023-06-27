#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <assert.h>

#define NUM 1024
#define SIZE 32
#define SEP " "
#define INPUT_REDIR 1
#define OUTPUT_REDIR 2
#define APPEND_REDIR 3
#define NONE_REDIR 0

char cmd_line[NUM];
char *g_argv[SIZE];
char g_myval[64];
int redir_status = NONE_REDIR;

char *CheckRedir(char *start)
{
    assert(start);
    char *end = start + strlen(start) - 1;

    //确定命令输出状态
    while (end >= start)
    {
        //输出重定向
        if ('>' == *end)
        {
            //追加重定向
            if ('>' == *(end - 1))
            {
                redir_status = APPEND_REDIR;
                *(end - 1) = '\0';
                end ++;
                break;
            }
            redir_status = OUTPUT_REDIR;
            *end = '\0';
            end ++;
            break;
        }
        //输入重定向
        else if ('<' == *end)
        {
            redir_status = INPUT_REDIR;
            *end = '\0';
            end ++;
            break;
        }
        else
        {
            --end;
        }
    }

    //返回文件路径
    if (end >= start)
    {
        return end;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    //常驻进程
    while (1)
    {
        printf("[root@myShell]# ");
        fflush(stdout);//行刷新策略，上一个printf语句不会被立即刷新，所以需要手动
        memset(cmd_line, 0, sizeof cmd_line);//重置数组

        if (fgets(cmd_line, sizeof cmd_line, stdin) == NULL)//获取一行命令
        {
            continue;
        }
        cmd_line[strlen(cmd_line) - 1] = '\0';//添加'\0'

        char *sep = CheckRedir(cmd_line);//检查命令
        g_argv[0] = strtok(cmd_line, SEP);//提取指令
        int index = 1;
        //判断命令的类型
        if(strcmp(g_argv[0], "ls") == 0)
        {
            g_argv[index ++ ] = "--color=auto";
        }
        if(strcmp(g_argv[0], "ll") == 0)
        {
            g_argv[0] = "ls";
            g_argv[index ++ ] = "-l";
            g_argv[index ++ ] = "--color=auto";
        }

        while(g_argv[index ++ ] = strtok(NULL, SEP));
        
        if(strcmp(g_argv[0], "export") == 0 && g_argv[1] != NULL)
        {
            strcpy(g_myval, g_argv[1]);
            int ret = putenv(g_myval);
            if(ret == 0)
                printf("%s export success\n", g_argv[1]);
            continue;
        }
        if(strcmp(g_argv[0], "rm") == 0 || strcmp(g_argv[0], "rmdir") == 0)//特判rm and rmdir
        {
            printf("sorry, cant support rm and rmdir\n");
            continue;
        }
        if(strcmp(g_argv[0], "cd") == 0)
        {
            if(g_argv[1] != NULL)
                chdir(g_argv[1]);
            printf("workdir is %s, now.\n", g_argv[1]);

            continue;
        }


        pid_t id = fork();
        if(id == 0)
        {
            //重定向
            if (sep != NULL)
            {
                int fd = -1;

                switch (redir_status)
                {
                case INPUT_REDIR://<
                    fd = open(sep, O_RDONLY);
                    dup2(fd, 0);
                    break;
                case OUTPUT_REDIR://>
                    fd = open(sep, O_WRONLY | O_TRUNC | O_CREAT, 0666);
                    dup2(fd, 1);
                    break;
                case APPEND_REDIR:
                    fd = open(sep, O_WRONLY | O_APPEND | O_CREAT, 0666);
                    dup2(fd, 1);
                    break;
                default:
                    printf("bug?\n");
                    break;
                }
            }
            //进程替换
            execvp(g_argv[0], g_argv);
            exit(1);
        }

        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        if(ret > 0)
            printf("exit code: %d\n", WEXITSTATUS(status));

    }

    return 0;
}