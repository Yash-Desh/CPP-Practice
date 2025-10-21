// Author: Yash Deshpande
// Date  : 15-08-2025
// Tutor : Love Babbar OS Series

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class Foo {
    std::mutex m;
    std::condition_variable cv;
    int turn;
public:
    Foo() {
        turn = 0;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex>lock(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex>lock(m);
        while(turn != 1)
            cv.wait(lock);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m);
        while(turn != 2)
            cv.wait(lock);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

int main()
{
    return 0;
}

// ################################ NOTES ################################

/*

Lock acquisition:
    When a unique_lock is constructed with m, it locks the mutex immediately.
    From now until the lock is destroyed, this thread has exclusive access to 
    any data protected by m (such as turn).

Wait until it’s this thread’s turn:
    If turn is not 1, we wait.
    cv.wait(lock):
        Atomically unlocks the mutex m and puts the thread into a waiting state.
        When another thread calls cv.notify_all() or cv.notify_one(), the thread 
        wakes up and locks the mutex again before returning from wait().
    The while loop handles spurious wakeups — if turn still isn’t 1 after waking, 
    it goes back to waiting.

Do the work
    At this point, we know turn == 1 and we hold the mutex.
    We execute the critical section (printSecond()).

Update the state & notify others
    Still holding the lock, we update turn to 2 so the next thread knows it’s their turn.
    We call cv.notify_all() to wake all waiting threads (could also be notify_one() 
    if only one needs to wake).

Lock release
    When the function ends (or the unique_lock goes out of scope), its destructor 
    automatically unlocks the mutex.

*/