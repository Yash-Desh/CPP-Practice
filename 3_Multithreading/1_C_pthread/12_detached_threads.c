// Author: Yash Deshpande
// Date  : 25-10-2025
// Tutor : CodeVault (https://youtu.be/-i8Kzuwr4T4?si=vloQxH2Fxzr8DUX7)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 2

void* routine() {
    sleep(1);
    printf("Finished Execution\n");
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    // Here we create a non-detached thread, & then detach it later.
    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_create(&th[i], NULL, routine, NULL) != 0) {
            perror("Failed to create thread");
        }
        pthread_detach(th[i]);
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL) != 0) {
            perror("Failed to join threads");
        }
    }

    // Option-1 : Process won't terminate when parent exits.
    pthread_exit(0);

    // Option-2 : Process terminates when parent exits.
    return 0;
}


/*

1. Detached threads cannot be joined i.e. the parent thread does not wait for the detached threads
before exiting the program.

2. Detached threads clear their own resources.

3. What happens without the pthread_exit(0) ?
All the threads are sleep(1) when the parent exits with a return 0;


*/