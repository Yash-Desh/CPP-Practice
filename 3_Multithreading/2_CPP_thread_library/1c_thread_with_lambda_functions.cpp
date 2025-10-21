// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/Q7gqDzOFO7E?si=eNkfmN4eHe8o4OGM)

#include <iostream>
#include <thread>
using namespace std;

int main() {
    // Define the lambda function
    auto lambda = [](int x) {
        cout<<"Hello from the 2nd thread\n";
        cout<<"Argument Passed in "<<x<<endl;
    };

    std::thread t1(lambda, 100);
    t1.join();

    cout<<"Hello from my main thread\n";
    return 0;
}