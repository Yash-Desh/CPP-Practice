// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Mike Shah (https://youtu.be/XZDx41woDoI?si=pKJcDaWpniCJPq9L)

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

// This question is a "join" condition.
// The parent spawns 2 threads -> a worker & a reporter
// worker must signal & reporter must wait.
// Work being done here is setting the variable "result".
// State is maintained using variable "notified"

// A global lock
std::mutex gLock;
std::condition_variable gConditionVariable;

int main() {
    int result = 0;
    bool notified = false;

    // Reporting thread -> Consumer
    // must wait on the work done by the working thread.
    std::thread reporter([&]{
        std::unique_lock<std::mutex> lock(gLock);
        if(!notified) {
            gConditionVariable.wait(lock);
        }
        cout << "Reporter, result = " << result << endl;
    });

    // Working thread -> Producer
    std::thread worker([&]{
        std::unique_lock<std::mutex> lock(gLock);
        // Do our work, as we have the lock
        result = 42 + 7;

        // Work is done.
        notified = true;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Worker, Work Complete\n";

        // Wake-up a thread that is waiting for some condition to be true.
        gConditionVariable.notify_one();
    });

    reporter.join();
    worker.join();

    cout << "Parent Thread, Program Complete\n";

    return 0;
}