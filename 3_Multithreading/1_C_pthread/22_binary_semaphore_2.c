// Author: Yash Deshpande
// Date  : 25-10-2025
// Tutor : CodeVault (https://youtu.be/YpD-vsj5Jbk?si=5p7Y2n_WCD76rdv0)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 1

pthread_mutex_t mutexFuel;
sem_t semFuel;

int* fuel;

void* routine(void* args) {
    // Fuel is already allocated memory by the main thread
    // Hence we do not need to sem_wait 
    *fuel += 50;
    printf("Current Value of Fuel = %d\n", *fuel);
    sem_post(&semFuel);
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    // pthread_mutex_init(&mutexFuel, NULL);
    sem_init(&semFuel, 0, 0);

    fuel = malloc(sizeof(int));
    *fuel = 50;

    for(int i=0; i<THREAD_NUM; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, routine, a) != 0) {
            perror("Failed to create thread");
        }
    }

    // Unless the other thread calls sem_post() the parent thread will not 
    // proceed beyond this point.
    // This is similar to the join scenario taught in ECE537 course
    sem_wait(&semFuel);
    printf("Deallocating Fuel\n");
    free(fuel);

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL)) {
            perror("Failed to join thread");
        }
    }

    sem_destroy(&semFuel);

    return 0;
}