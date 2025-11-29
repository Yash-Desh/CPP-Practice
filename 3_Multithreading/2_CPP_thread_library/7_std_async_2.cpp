// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Mike Shah (https://youtu.be/2eJm6tA4y2U?si=FRELyfrs1mXMXt5x)

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

// In this lesson I show you an example with std::async 
// and how you can use it to load data in a background thread. 
// We also discuss the policies that exist for how to launch 
// a std::async, and look at the futures library to get the status of our future.

// Think about this example like YouTube buffering/loading the video in the background. 

bool bufferedFileLoader() {
    size_t loadedBytes = 0;
    while(loadedBytes < 20000) {
        cout << "thread: Loading file..." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        loadedBytes += 1000;
    }
    return true;
}

int main() {

    std::future<bool> backgroundThread  = std::async(std::launch::async, bufferedFileLoader);

    std::future_status status;

    // Our main program loop
    while(true) {
        cout << "Main thread is running\n";
        // sleep to simulate some processing in a real program
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status = backgroundThread.wait_for(std::chrono::milliseconds(1));

        // if our data is ready, i.e. our background thread has completed.
        if(status == std::future_status::ready) {
            cout << "Our data is ready..." << endl;
            break;
        }
    }

    cout << "Program is Complete" << endl;
    return 0;
}
