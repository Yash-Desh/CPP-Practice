#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int i;
    int turn;
    condition_variable cv;
    mutex m;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;
        turn = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i <= n)
        {
            unique_lock<mutex>lock(m);
            while((i<= n) && turn != 0)
                cv.wait(lock);
            if(i<= n)
            {
                printNumber(0);
                turn = (i%2) == 0 ?2:1;
            }
            cv.notify_all();
        }

    }

    void even(function<void(int)> printNumber) {
        while(i <= n)
        {
            unique_lock<mutex>lock(m);
            while((i<= n) && turn != 2)
                cv.wait(lock);
            if(i<= n)
            {
                printNumber(i);
                i++;
                turn = 0;
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i <= n)
        {
            unique_lock<mutex>lock(m);
            while((i<= n) && turn != 1)
                cv.wait(lock);
            if(i<= n)
            {
                printNumber(i);
                i++;
                turn = 0;
            }
            cv.notify_all();
        }
    }
};

int main()
{
    return 0;
}