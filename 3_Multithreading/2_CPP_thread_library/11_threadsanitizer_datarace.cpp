// Author : Yash Deshpande
// Date   : 27-11-2025
// Tutor  : Mike Shah (https://youtu.be/ZJKBwQ71LN4?si=9IlI47UdmTsH8hsY)

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

// ###############################################################
// Compile : g++ -fsanitize=thread 11_threadsanitizer_datarace.cpp
// ###############################################################

static int shared_value = 0;

void shared_value_increment() {
    shared_value = shared_value + 1;
}

int main() {
    vector<std::thread> threads;
    for(int i=0; i<1000; i++) {
        threads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i<1000; i++) {
        threads[i].join();
    }

    cout<<"Shared Value : "<<shared_value<< endl;
    return 0;
}

