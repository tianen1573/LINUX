#include<cstdio>

#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define PATHNAME "/home/qlz/LINUX/IPC/systemV/server.cc"//指定一个文件路径，并且是，存在且可以获取的文件的路径

#define PROJ_ID 0x6666 //整数标识符
#define SIZE 4096 //共享内存的大小