// Author : Yash Deshpande
// Date   : 10-10-2025
// Tutor  : Mike Shah (https://youtu.be/tGfG3u0CB7s?si=6kcQaxDs42hh29jH)

#include <iostream>
#include <thread>
using namespace std;

// Worker function for the thread
void test(int x) {
    cout<<"Hello from the 2nd thread\n";
    cout<<"Argument Passed in "<<x<<endl;
}

int main() {
    // Method-1
    // std::thread t1(&test, 100);

    // Method-2
    std::thread t1(test, 100);

    // Make the Parent wait.
    t1.join();

    cout<<"Hello from my main thread\n";
    return 0;
}