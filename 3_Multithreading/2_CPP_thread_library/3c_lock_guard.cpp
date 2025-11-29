// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/Zp17-UDKM90?si=2_3QtKyDoR0SiUZ7)

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// This file is the part-3 for the series on lock_guard
// lock_guard follows the RAII (Resource Acquisition is Initialization) principle
// It's destructor will call the unlock whenever it goes out of scope. 
// So it protects you from deadlocks when you forget to unlock. 

static int shared_value = 0;
std::mutex gLock;

// Both examples of shared_value_increment() are working & demonstrate the use of lock_guard
// Use either to study its behaviour. 

// void shared_value_increment() {
//     // Critical Section
//     std::lock_guard<std::mutex> lockGuard(gLock);
    
//     try
//     {
//         shared_value = shared_value + 1;
//         throw "dangerous...abort";
//     }
//     catch(...)
//     {
//         cout<<"handle exception";
//         return;
//     }
// }

void shared_value_increment() {
    // Critical Section
    std::lock_guard<std::mutex> lockGuard(gLock);
    shared_value = shared_value + 1;
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

