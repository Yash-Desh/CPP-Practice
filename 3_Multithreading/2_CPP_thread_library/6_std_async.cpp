// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Mike Shah (https://youtu.be/4twJD5ezkag?si=CwdNYPRpLZ5t5CFL)

#include <iostream>
#include <thread>
#include <future>
using namespace std;

int square(int x) { 
    return x*x; 
}

int main() {
    // async operation will be executed on a different thread
    std::future<int> asyncFunction = std::async(square, 12);

    for(int i=0; i<10; i++) {
        cout << square(i) << endl;
    }

    // We are blocked at the .get() line until our result is computed
    int result = asyncFunction.get();
     
    cout << "result = " << result << endl;
    return 0;
}