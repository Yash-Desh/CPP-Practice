// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/f_C4eYxBWdQ?si=jMRMfQVGr8EN1eh8)

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
using namespace std;

// With std::atomic variables you have to careful with what operators you use,
// as some cases can trigger race condition.  

static std::atomic<int> shared_value = 0;

void shared_value_increment() {
    // ATOMIC: ++ operator is overloaded to perform atomic add
    shared_value++;

    // This will give a data race. -> NOT ATOMIC
    // shared_value = shared_value + 1;

    // ATOMIC: += operator is also overloaded
    // shared_value += 1;
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

