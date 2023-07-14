#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void* Routine(void *arg)
{
    char *msg = (char*)arg;

    while(true)
    {
        cout << "I am " << msg << endl;
        sleep(1);
    }
}

int main()
{

    pthread_t id;
    pthread_create(&id, nullptr, Routine, (void*)"thread-1");

    while(true)
    {
        cout << "I am main thread and child: " << id << endl;
        sleep(1);
    }

    return 0;
}