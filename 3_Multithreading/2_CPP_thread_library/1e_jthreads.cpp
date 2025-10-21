// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/AhPhYvFphBA?si=_FLuh1La5zKhY5eX)

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

int main() {
    // Define the lambda function
    auto lambda = [](int x) {
        cout<<"Hello from the thread "<<std::this_thread::get_id()<<endl;
        cout<<"Argument Passed in "<<x<<endl;
    };

    vector<std::jthread> jthreads;
    for(int i=0; i<10; i++) {
        jthreads.push_back(std::jthread(lambda, i));
    }

    cout<<"Hello from my main thread\n";
    return 0;
}

