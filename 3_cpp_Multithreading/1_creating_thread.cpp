// Author : Yash Deshpande
// Date   : 14-08-2025
// Tutor  : The Cherno

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono_literals;

static bool s_Finished = false;

void DoWork(){
    cout<<"Started thread id = "<< this_thread::get_id() << endl;

    while(!s_Finished){
        cout<<"Working...\n";
        this_thread::sleep_for(1s);
    }
}

int main(){
    cout<<"Started thread id = "<< this_thread::get_id() << endl;
    thread worker(DoWork);

    cin.get();
    s_Finished = true;

    worker.join();
    cout<<"Worker finished\n";
    
    return 0;
}