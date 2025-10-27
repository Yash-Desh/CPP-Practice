// Author: Yash Deshpande
// Date  : 25-10-2025
// Tutor : CodeVault (https://youtu.be/YSn8_XdGH7c?si=EufwVo-gro3kdtkl)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

void* routine(void* args) {
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread %d\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
    
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];


    // Parameters to initialize a semaphore.
    // 1. Reference to the semaphore
    // 2. Check to confirm if you have multiple processes.
    // 0 = single process, 1 = multiple processes
    // 3. Initial Value of the semaphore
    sem_init(&semaphore, 0, 2);

    // Semaphores differ from recursive mutexes in the sense that
    // multiple threads can lock & unlock the semaphore at the same time.

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