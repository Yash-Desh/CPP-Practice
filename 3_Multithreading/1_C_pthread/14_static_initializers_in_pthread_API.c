// Author: Yash Deshpande
// Date  : 25-10-2025
// Tutor : CodeVault (https://youtu.be/Xo6e6RsWoBk?si=T8-i_-ieqm3775cH)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 2

pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condFuel = PTHREAD_COND_INITIALIZER;


void* routine() {

}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    // Static Initializer is an alternative method to the following
    // The attribute section has to be NULL
    // pthread_mutex_init(&mutexFuel, NULL);

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_create(&th[i], NULL, routine, NULL) != 0) {
            perror("Failed to create thread");
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL) != 0) {
            perror("Failed to join threads");
        }
    }


    pthread_mutex_destroy(&mutexFuel);

 return 0;
}