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

    //2. 获取共享内存id
    int shm = shmget(key, SIZE, IPC_CREAT); //理想状态：获取的是已存在
    if (shm < 0)
    {
        perror("shmget");
        return 2;
    }

    //3. 关联共享内存
    char *mem = (char *)shmat(shm, NULL, 0);
    if (mem == (void *)-1)
    {
        perror("shmat");
        return 2;
    }

    //4. 操作
    int i = 0;
    while (true)
    {
        
        printf("client# %s\n", mem);
        sleep(1);
    }

    //5. 去关联
    shmdt(mem);

    return 0;
}