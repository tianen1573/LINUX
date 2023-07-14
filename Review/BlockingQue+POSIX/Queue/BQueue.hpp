#include <queue>
#include <unistd.h>
#include <pthread.h>

namespace qlz
{
    typedef void(*CallBack)(int, int, char); 

    template<class T>
    class BQueue
    {
    private:
        int _cap;
        CallBack _cp;
        pthread_mutex_t _mtx;
        pthread_cond_t _cond_full;
        pthread_cond_t _cond_empty;
        std::queue<T> _que;
    public:
        BQueue(int cap, CallBack cp) : _cap(cap), _cp(cp)
        {
            pthread_mutex_init(&_mtx, nullptr);
            pthread_cond_init(&_cond_full, nullptr);
            pthread_cond_init(&_cond_empty, nullptr);
        }
        void Push(const T &data)
        {
            pthread_mutex_lock(&_mtx);

            while(_que.size() == _cap)
            {
                pthread_cond_wait(&_cond_full, &_mtx);
            }
            _que.push(data);

            pthread_mutex_unlock(&_mtx);

            pthread_cond_signal(&_cond_empty);
        }
        void Pop(T &t)
        {
            pthread_mutex_lock(&_mtx);

            while(_que.empty())
            {
                pthread_cond_wait(&_cond_empty, &_mtx);
            }
            t = _que.front();
            _que.pop();

            pthread_mutex_unlock(&_mtx);

            pthread_cond_signal(&_cond_full);
        }
        ~BQueue()
        {
            pthread_mutex_destroy(&_mtx);
            pthread_cond_destroy(&_cond_full);
            pthread_cond_destroy(&_cond_empty);
        }
    };
    
}