// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/hXKtYRleQd8?si=sUA_0p4QXmRDxWwJ)

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

static int shared_value = 0;

// Declare a global mutex
std::mutex gLock;

void shared_value_increment() {
    // Non-critical section
    cout<< "This is thread " << shared_value << endl;

    // Critical Section
    gLock.lock();
    shared_value = shared_value + 1;
    gLock.unlock();
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

