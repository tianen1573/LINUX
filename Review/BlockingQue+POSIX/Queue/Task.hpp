namespace qlz
{
    typedef void(*CallBack)(int, int, char); 
    class Task
    {
    private:
        int _l;
        int _r;
        char _op;
        CallBack _cb;
    public:
        Task()
        {}
        Task(int l, int r, char op, CallBack cb) :_l(l), _r(r), _op(op), _cb(cb)
        {}
        void Run()
        {
            _cb(_l, _r, _op);
        }
    };
}