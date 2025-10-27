// Author: Yash Deshpande
// Date  : 25-10-2025
// Tutor : CodeVault (https://youtu.be/Q79uEdKNVGY?si=K-895ZumaLT04rfQ)

// Q We are looking at an example of a login queue, where we have 12 concurrent
// logins at the same time. But we have a total of 16 threads & each waits for 
// a random amount of time between 1-5 seconds in the critical section
// Hence Semaphores will

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define THREAD_NUM 16

sem_t semaphore;

void* routine(void* args) {
    // Before Critical Section.
    printf("Thread %d waiting in the login queue\n", *(int*)args);

    sem_wait(&semaphore);
    printf("Thread %d Logged in\n", *(int*)args);
    sleep(rand() % 5 + 1);
    printf("Thread %d Logged out\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
    
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    pthread_t th[THREAD_NUM];

    sem_init(&semaphore, 0, 12);

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

    sem_destroy(&semaphore);

    return 0;
}