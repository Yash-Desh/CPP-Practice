// Author : Yash Deshpande
// Date   : 12-10-2025
// Tutor  : Mike Shah (https://youtu.be/kfLE57ljoEE?si=nItNEWEFX7MCbnrS)

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

    // ################### Vector of Threads ###################
    // Run both case-1 & case-2 individually & notice the difference in results
    // Case-1 is serially launching 10 threads as the main thread waits till the 
    // thread exits to launch the next thread. Hence thread with the same thread_id
    // gets created.
    
    // // Case-1: Serially Launching 10 Threads: FAIL
    // vector<std::thread> threads;
    // for(int i=0; i<10; i++) {
    //     threads.push_back(std::thread(lambda, i));
    //     threads[i].join();
    // }


    // Case-2: Parallely Launching 10 Threads: SUCCESS
    vector<std::thread> threads;
    for(int i=0; i<10; i++) {
        threads.push_back(std::thread(lambda, i));
    }

    for(int i=0; i<10; i++) {
        threads[i].join();
    }


    cout<<"Hello from my main thread\n";
    return 0;
}

