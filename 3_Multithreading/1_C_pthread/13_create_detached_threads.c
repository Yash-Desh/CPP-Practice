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
    
    // Declare & Initialize the attribute for declaring a detached thread.
    pthread_attr_t detachedThread;
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread, PTHREAD_CREATE_DETACHED);

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_create(&th[i], &detachedThread, routine, NULL) != 0) {
            perror("Failed to create thread");
        }
        pthread_detach(th[i]);
    }

    pthread_attr_destroy(&detachedThread);

    pthread_exit(0);
    return 0;
}

/*

Why do you need a thread that is detached from the time of creation ?
- Detached threads free their own resources automatically.
- Suppose we create a non-detached thread & then detach it later after its creation.
  then in one possible case the thread might finish execution right in the middle of 
  creation & detaching. 
- And in this case the resources will not be freed until the detach is called as the thread
  is created non-detached.
- So a thread that is detached from the creation will avoid such situations.


*/