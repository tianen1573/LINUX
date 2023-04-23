#include "comm.hpp"

int main()
{

    //1. 获取key值

    key_t key = ftok(PATHNAME, PROJ_ID);
    if (key < 0)
    {
        perror("ftok");
        return 1;
    }

    //2. 服务端创建共享内存
    int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (shm < 0)
    {
        perror("shmget");
        return 2;
    }

    //3. 关联内存
    char *mem = (char *)shmat(shm, NULL, 0);
    if (mem == (void *)-1)
    {

        shmctl(shm, IPC_RMID, NULL);

        perror("shmat");
        return 2;
    }

    //4. 操作
    int i = 0;
    while (true)
    {
        mem[i] = 'A' + i;
        i++;
        mem[i] = '\0';
        sleep(1);
    }

    //5. 去关联
    shmdt(mem);

    //6. 释放内存
    shmctl(shm, IPC_RMID, NULL);

    return 0;
}