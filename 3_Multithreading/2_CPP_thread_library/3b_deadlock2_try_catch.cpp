// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/Zp17-UDKM90?si=2_3QtKyDoR0SiUZ7)

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// The concept to take is call the unlock inside & outside the catch block
// in case the exception occurs or not.

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
        gLock.unlock();                 // unlock if exception occurs
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

