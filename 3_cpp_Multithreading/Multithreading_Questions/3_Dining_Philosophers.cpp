#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>

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



class DiningPhilosophers {
    Semaphore fork[5];
    mutex m;
public:
    DiningPhilosophers() {
        for(int i=0; i<5; i++)
        {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        // pick both forks atomically
		{
            std::lock_guard<std::mutex> lock(m);
            fork[philosopher].wait();
            fork[(philosopher+1)%5].wait();
        }

        pickLeftFork();
        pickRightFork();
        eat();

        // release forks
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();
    }
};


int main()
{
    return 0;
}