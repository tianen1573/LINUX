#include<cstdio>

#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define PATHNAME "/home/qlz/LINUX/IPC/systemV/test1.cc"//指定一个文件路径，并且是，存在且可以获取的文件的路径

#define PROJ_ID 0x666//id
#define SIZE 4096//共享内存大小

int main()
{
    key_t key = ftok(PATHNAME, PROJ_ID);//1. 生成key
    if(key < 0)
    {
        perror("ftok\n");
        return 2;
    }

    int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666);//2. 创建共享内存，设置权限， 并且只接受 新创建的共享内存
    if(shm < 0)
    {
        perror("shmget");
        return 2;
    }

    printf("key: %x\n", key);
    printf("shm: %x\n", shm);

    printf("attach begin!\n");
    sleep(2);

    char *memory = (char*)shmat(shm, NULL, 0);//3. 进程关联共享内存，返回的是 在mmap中的映射地址
    if(memory == (void*)-1)
    {
        shmctl(shm, IPC_RMID, NULL);//释放， 且不关心共享内存状态

        perror("shmat error\n");
        return 1;
    }

    printf("attach end!\n");
    sleep(2);



    printf("detach begin!\n");
    sleep(2);

    shmdt(memory);//4. 去关联

    printf("detach end!\n");
    sleep(2);

    shmctl(shm, IPC_RMID, NULL);//5. 释放， 且不关心共享内存状态
    sleep(2);

    return 0;
}