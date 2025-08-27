// Date : 13-08-2024
// Author : Yash Deshpande
// Tutor : Love Babbar OS series

#include <iostream>
// thread library is used in cpp for multithreading
#include <thread>
#include <unistd.h>  // for POSIX compliance -> sleep()

using namespace std;

// Task 1 of the process
void taskA()
{
    for(int i=0; i<10; ++i)
    {
        sleep(1);
        printf("TaskA : %d\n", i);
        fflush(stdout);
    }
}


// Task 2 of the process
void taskB()
{
    for(int i=0; i<10; ++i)
    {
        sleep(1);
        printf("TaskB : %d\n", i);
        fflush(stdout);
    }
}

// main process
int main()
{
    // 2 threads created for 2 tasks 
    thread t1(taskA);
    thread t2(taskB);

    // Main thread waits for the worker thread to finish
    t1.join();
    t2.join();

    return 0;
}