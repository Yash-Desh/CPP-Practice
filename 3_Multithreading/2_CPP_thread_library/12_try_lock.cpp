// Author : Yash Deshpande
// Date   : 27-11-2025
// Tutor  : Mike Shah (https://youtu.be/ZJKBwQ71LN4?si=9IlI47UdmTsH8hsY)

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// 2 threads are running, they both print their names if given a chance.
// But we want only one thread to print its name, using try_lock.

// Note that try_lock does not guarantee that only one thread will run,
// in the case that the 2nd thread tries to get the lock after the 1st thread
// has released, it will allow both threads to print

std::mutex g_lock;

void job1() {
    if(g_lock.try_lock()) {
        cout << "job1 executed" << endl;
        g_lock.unlock();
    }
    else {
        cout << "job1 failed" << endl;
    }
}

void job2() {
    if(g_lock.try_lock()) {
        cout << "job2 executed" << endl;
        g_lock.unlock();
    }
    else {
        cout << "job2 failed" << endl;
    }
}

int main() {
    std::thread thread1(job1);
    std::thread thread2(job2);

    thread1.join();
    thread2.join();

    return 0;
}