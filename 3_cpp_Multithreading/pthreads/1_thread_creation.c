// Author : Yash Deshpande
// Date   : 08-10-2025
// Tutor  : CodeVault YT (https://youtu.be/d9s_d28yJq0?si=iZkjWwVYW6VnRNLe)

// ----------------------------------------------------------------------
// Compilation command: gcc -lpthread <file_name.c> -o <executable_name>
// ----------------------------------------------------------------------


// This program demonstrates the creation of threads using pthreads, 
// their parallel execution & error handling in threads.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Threads execute functions
void* routine() {
    printf("Test from threads\n");
    sleep(3);                           // sleep for 3s 
    printf("Ending test\n");
}


int main(int argc, char *argv[]) {
    
    // Declare a thread.
    pthread_t t1, t2;

    // Initialize the thread
    // Parameters passed to the thread:
    // 1. Address of the thread, 
    // 2. attributes of threads, 
    // 3. function(routine) that the thread will execute, 
    // 4. arguments to be passed to routine
    pthread_create(&t1, NULL, &routine, NULL);

    // Checking for errors when creating threads
    if(pthread_create(&t2, NULL, &routine, NULL) != 0) {
        printf("Error in creating thread\n");
        return 1;                           // return error code.
    }

    // Make the parent wait
    // arguments: child thread to wait on, pointer that gets the result of the thread
    pthread_join(t1, NULL);

    // Error handling for thread-join
    if(pthread_join(t2, NULL) != 0) {
        printf("Error in joining thread\n");
        return 2;                           // return error code.
    }

    // Notice that the output is interleaved
    // Test from threads
    // Test from threads
    // Ending test
    // Ending test

    return 0;
}