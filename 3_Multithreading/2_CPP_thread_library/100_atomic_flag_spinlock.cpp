// Author:
// Date  : 13-10-2025
// Tutor : Gemini

#include <atomic>
#include <thread>
#include <iostream>

class Spinlock {
    // Initialize to false (C++11/14/17)
    // No longer strictly needed in C++20+ as default constructor clears it.
    std::atomic_flag flag = ATOMIC_FLAG_INIT; 
                                            
public:
    void lock() {
        // Spin until successfully set
        while (flag.test_and_set(std::memory_order_acquire)); 
    }

    void unlock() {
        flag.clear(std::memory_order_release); // Clear the flag
    }
};

Spinlock my_spinlock;
int shared_data = 0;

void increment_data() {
    for (int i = 0; i < 100000; ++i) {
        my_spinlock.lock();
        shared_data++;
        my_spinlock.unlock();
    }
}

int main() {
    std::thread t1(increment_data);
    std::thread t2(increment_data);

    t1.join();
    t2.join();

    std::cout << "Shared data: " << shared_data << std::endl; // Expected: 200000
    return 0;
}