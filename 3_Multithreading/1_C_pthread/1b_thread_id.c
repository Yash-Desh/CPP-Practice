// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/4VQmuj1RrCk?si=7i19VVeUkkb1DhuA)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

void* routine() {
    pthread_t th = pthread_self();
    printf("I am pthread_t = %lu\n", th);

    // Get the Linux assigned thread id
    printf("My Linux assigned tid = %d\n", (pid_t)syscall(SYS_gettid));
}

int main(int argc, char* argv[]) {
    pthread_t th[2];

    for(int i; i<2; i++) {
        pthread_create(&th[i], NULL, routine, NULL);
        // pthread_t is an unsigned long number 
        // this number is assigned by the pthread API, not the linux kernel
        printf("Main thread created pthread_t = %lu\n", th[i]);     
    }

    for(int i=0; i<2; i++) {
        pthread_join(th[i], NULL);
    }


    return 0;
}

/*

The POSIX API recommends that you should never print out the pthread_t number.
That is because the pthread_t is supposed to be an opaque data type.
That means it is not guaranteed to be unsigned long on every system. 

*/