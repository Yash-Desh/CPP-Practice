// Author : Yash Deshpande
// Date   : 26-09-2025
// Tutor  : The Cherno

#include <iostream>
// #include <chrono>
#include <string>
#include <thread>
using namespace std;

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    // struct constructor
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        cout<<"Timer took "<<ms<<"ms"<<endl;
    }
};

void Function() {
    Timer timer;

    for(int i=0; i<100; i++) {
        cout<<"Hello"<<endl;
    }
}

int main() {

    // ##############
    // Method-1
    // ##############
    // using namespace std::literals::chrono_literals;

    // // Make the thread sleep for 1s
    // auto start = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s);
    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<float> duration = end-start;
    // cout<<duration.count()<<"s\n";


    // ##############
    // Method-2
    // ##############
    Function();

    
    return 0;
}