// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor :

// This is an experimental code to see what happens when we don't call pthread_join()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

#define THREAD_NUM 2

int handle = 0;

pthread_mutex_t mtx;

void* routine(void* arg) {
    for(int i=0; i<100; i++) {
        pthread_mutex_lock(&mtx);
        handle++;
        pthread_mutex_unlock(&mtx);
    }
    printf("Value of handle after thread run = %d\n", handle);
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    pthread_mutex_init(&mtx, NULL);

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_create(&th[i], NULL, &routine, NULL);
    }

    // for(int i=0; i<THREAD_NUM; i++) {
    //     pthread_join(th[i], NULL);
    // }

    printf("Value of handle after parent run = %d\n", handle);

    pthread_mutex_destroy(&mtx);

    return 0;
}