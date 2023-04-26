#pragma once

#include<iostream>

class Task
{
private:

    int _left;
    int _rig;
    int _op;
    
public:

    Task()
    {}

    Task(int l, int r, int op)
    : _left(l)
    , _rig(r)
    , _op(op)
    {}

    ~Task()
    {}

    void Run()
    {
        int res = 0;
        switch(_op)
        {
            case '+':
                res = _left + _rig;
                break;
            case '-':
                res = _left - _rig;
                break;
            case '*':
                res = _left * _rig;
                break;
            case '/':
                if(_rig == 0)
                {
                    std::cout << "warning : div zero!" <<std::endl;
                    res = -1;
                }
                else
                {
                    res = _left /_rig;
                }
                break;
            case '%':
                if(_rig == 0)
                {
                    std::cout << "warning : div zero!" <<std::endl;
                    res = -1;
                }
                else
                {
                    res = _left %_rig;
                }
                break;
            default:
                std::cout << "error op!" << std::endl;
        }

        std::cout << _left << (char)_op << _rig << "=" << res << std::endl;
    }
};

