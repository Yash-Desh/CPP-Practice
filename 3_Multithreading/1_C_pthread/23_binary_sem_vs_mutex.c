// Author: Yash Deshpande
// Date  : 26-10-2025
// Tutor : CodeVault (https://youtu.be/ZpRN3XQY4AA?si=bA6gVg-5eCuncPrB)

// This file is for a comparison between binary semaphores & mutexes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

pthread_mutex_t mutexFuel;
sem_t semFuel;
int fuel = 50;


// Function where binary semaphore can directly replace mutex
// void* routine(void* args) {
//     pthread_mutex_lock(&mutexFuel);
//     fuel += 50;
//     printf("Current Value of Fuel = %d\n", fuel);
//     pthread_mutex_unlock(&mutexFuel);
// }

void* routine1(void* args) {
    sem_wait(&semFuel);
    fuel += 50;
    printf("Current Value of Fuel = %d\n", fuel);
}

void* routine2(void* arg) {
    sem_post(&semFuel);
}

// Note : This example showing routine1 & routine2 is NOT free of race conditions
// But it was shown here as a good example to understand that binary semaphores
// need not be sem_post() by the same thread called the sem_wait()
// But mutexes have the concept of ownership, lock & unlock need to be called by the 
// same threa.

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    pthread_mutex_init(&mutexFuel, NULL);
    sem_init(&semFuel, 0, 1);                   // --> Binary Semaphore.

    for(int i=0; i<THREAD_NUM; i++) {
        if(i%2 == 0) {
            if(pthread_create(&th[i], NULL, routine1, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
        else {
            if(pthread_create(&th[i], NULL, routine2, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL)) {
            perror("Failed to join thread");
        }
    }

    sem_destroy(&semFuel);
    pthread_mutex_destroy(&mutexFuel);

    return 0;
}