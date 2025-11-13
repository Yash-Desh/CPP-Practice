// Author: Yash Deshpande
// Date  : 02-11-2025
// Tutor : 

// Q. Synchronize three threads to print 1,2,3,1,2,3 respectively

// Source : This question was found on the hardware community on discord

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 3

#define REPEAT 2

sem_t semOne;
sem_t semTwo;
sem_t semThree;

void* routineOne() {
    for(int i=0; i<REPEAT; i++) {
        sem_wait(&semOne);
        printf("%d", 1);
        sem_post(&semTwo);
    }
}

void* routineTwo() {
    for(int i=0; i<REPEAT; i++) {
        sem_wait(&semTwo);
        printf("%d", 2);
        sem_post(&semThree);
    }
}

void* routineThree() {
    for(int i=0; i<REPEAT; i++) {
        sem_wait(&semThree);
        printf("%d", 3);
        sem_post(&semOne);
    }
}

int main(int argc, char* argv[]) {

    pthread_t th[THREAD_NUM];
    sem_init(&semOne, 0, 1);
    sem_init(&semTwo, 0, 0);
    sem_init(&semThree, 0, 0);

    pthread_create(&th[0], NULL, routineOne, NULL);
    pthread_create(&th[1], NULL, routineTwo, NULL);
    pthread_create(&th[2], NULL, routineThree, NULL);

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    sem_destroy(&semOne);
    sem_destroy(&semTwo);
    sem_destroy(&semThree);

    return 0;
}