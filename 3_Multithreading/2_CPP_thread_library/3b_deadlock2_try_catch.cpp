// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/Zp17-UDKM90?si=2_3QtKyDoR0SiUZ7)

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// This is the part-2 on lock_guard, 
// We know that a deadlock will occur if we forget to unlock.
// This is real situation, where such a case could occur.
// We grab a lock but an exception occurs, & you don't unlock in the
// exception handling code.

// DEADLOCK: uncomment the unlock in the catch block to solve the deadlock.

// We should call the unlock inside & outside the catch block in case 
// whether the exception occurs or not.

static int shared_value = 0;
std::mutex gLock;

void shared_value_increment() {
    // Critical Section
    gLock.lock();
    
    try
    {
        shared_value = shared_value + 1;
        throw "dangerous...abort";
    }
    catch(...)
    {
        cout<<"handle exception";
        // gLock.unlock();                 // DEADLOCK!! unlock if exception occurs
        return;
    }
    gLock.unlock();                     // unlock if exception doesn't occur
}

int main() {
    vector<std::thread> threads;
    for(int i=0; i<100; i++) {
        threads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i<100; i++) {
        threads[i].join();
    }

    cout<<"Shared Value : "<<shared_value<< endl;
    return 0;
}

