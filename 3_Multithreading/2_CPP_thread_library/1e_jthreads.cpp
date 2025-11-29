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

/*

- Compile with C++20
- Uses the concept of RAII (Resource Acquisition is Initialization)
- Checkup the destructor on cppreference.com
- During the destruction of a jthread, it will be joined with the parent. 
- A jthread will join right at the end of the scope in which it is running.
- Basically it means, you don't have to call the join if you wished to do
  it in the standard way, i.e. in the parent thread.  


*/

