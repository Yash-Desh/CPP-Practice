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
        printf("Main thread created pthread_t = %lu\n", th[i]);     // -> this number is assigned by the pthread api
    }

    for(int i=0; i<2; i++) {
        pthread_join(th[i], NULL);
    }


    return 0;
}