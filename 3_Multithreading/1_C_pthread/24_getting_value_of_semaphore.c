// Author: Yash Deshpande
// Date  : 26-10-2025
// Tutor : CodeVault (https://youtu.be/0ZlrB6rrUhA?si=Z9ym7T7F-ZNhFraU)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t sem;

void* routine(void* args) {
    int index = *(int *)args;
    int semVal;
    sem_wait(&sem);
    sleep(index + 1);
    // Get the value of semaphore, though it may be modified by the time we print
    sem_getvalue(&sem, &semVal);
    printf("Thread id = %d, Current Semaphore value after wait is %d\n", index, semVal);
    sem_post(&sem);
    printf("Thread id = %d, Current Semaphore value after post is %d\n", index, semVal);
    free(args);
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    sem_init(&sem, 0, 4);

    for(int i=0; i<THREAD_NUM; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, routine, a) != 0) {
            perror("Failed to create thread\n");
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread\n");
        }
    }

    sem_destroy(&sem);

    return 0;
}