#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class FooBar {
private:
    int n;
    int state;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        this->state = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            while(state != 0)
                cv.wait(lock);
        	// printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            state = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            while(state == 0)
                cv.wait(lock);
        	// printBar() outputs "bar". Do not change or remove this line.
            printBar();
            state = 0;
            cv.notify_all();
        }
    }
};

int main()
{
    return 0;
}