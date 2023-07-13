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