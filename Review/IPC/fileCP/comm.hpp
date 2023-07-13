#pragma once

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <cstring>
#include <fcntl.h>

using namespace std;

#define FILE_NAME "myfifo"