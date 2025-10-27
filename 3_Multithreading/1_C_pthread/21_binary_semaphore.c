// Author: Yash Deshpande
// Date  : 25-10-2025
// Tutor : CodeVault (https://youtu.be/YpD-vsj5Jbk?si=5p7Y2n_WCD76rdv0)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

pthread_mutex_t mutexFuel;
sem_t semFuel;

int fuel = 50;

void* routine(void* args) {
    // pthread_mutex_lock(&mutexFuel);
    sem_wait(&semFuel);
    fuel += 50;
    printf("Current Value of Fuel = %d\n", fuel);
    sem_post(&semFuel);
    // pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    // pthread_mutex_init(&mutexFuel, NULL);
    sem_init(&semFuel, 0, 1);

    for(int i=0; i<THREAD_NUM; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, routine, a) != 0) {
            perror("Failed to create thread");
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL)) {
            perror("Failed to join thread");
        }
    }

    sem_destroy(&semFuel);
    // pthread_mutex_destroy(&mutexFuel);

    return 0;
}