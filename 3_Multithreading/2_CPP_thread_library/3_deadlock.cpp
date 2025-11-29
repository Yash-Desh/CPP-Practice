// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/Zp17-UDKM90?si=2_3QtKyDoR0SiUZ7)

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// This code demonstrates that a deadlock will occur if we forget to unlock.
// This file is the part-1 on lock_guard i.e. to introduce you to the problem.

static int shared_value = 0;

// Declare a global mutex
std::mutex gLock;

void shared_value_increment() {
    // Critical Section
    gLock.lock();
    shared_value = shared_value + 1;
    // gLock.unlock();          --> What if you forgot to unlock ? Deadlock!
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

