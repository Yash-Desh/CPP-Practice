// Date : 15-08-2025
// Author : Yash Deshpande
// Tutor : Love Babbar OS series

#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore
{
public:
    Semaphore() {}
    Semaphore(int c) : count(c){};

    void setCount(int a)
    {
        count = a;
    }

    inline void signal()
    {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        if(count <= 0)
            cv.notify_one();
    }

    inline void wait()
    {
        std::unique_lock<std::mutex> lock(mtx);
        count--;
        if(count < 0)
            cv.wait(lock);
    }


private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

int main()
{
    return 0;
}