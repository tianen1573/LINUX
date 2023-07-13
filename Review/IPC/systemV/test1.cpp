#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

using namespace std;

#define PATHNAME "/home/qlz/LINUX/Review/IPC/systemV/test1.cpp" //路径名 -- 必须是存在的合法路径
#define PROJ_ID 0x6666                                          //整数标识符
#define SIZE 4096                                               //共享内存的大小

int main()
{
    key_t key = ftok(PATHNAME, PROJ_ID); //获取key值
    if (key < 0)
    {
        perror("ftok");
        return 1;
    }
    int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666); //创建新的共享内存
    if (shm < 0)
    {
        perror("shmget");
        return 2;
    }
    printf("key: %x\n", key); //打印key值
    printf("shm: %d\n", shm); //打印句柄

    cout << "attch begin" << endl;
    sleep(2);
    void *mem = shmat(shm, nullptr, 0);
    if (mem == (void *)-1)
    {
        shmctl(shm, IPC_RMID, nullptr);

        perror("shmat");
        return 3;
    }
    cout << "attch end" << endl;

    cout << "detach begin" << endl;
    sleep(2);
    if (shmdt(mem) == -1)
    {
        perror("shmdt");
        return 4;
    }
    cout << "detach end" << endl;

    sleep(2);
    shmctl(shm, IPC_RMID, nullptr);

    return 0;
}
