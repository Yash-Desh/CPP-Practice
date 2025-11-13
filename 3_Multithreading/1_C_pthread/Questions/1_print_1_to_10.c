// Author: Yash Deshpande
// Date  : 02-11-2025
// Tutor : 

// Q. given pthread APIs , need to synchronize two threads to print odd and even numbers 
// respectively and only upto 10 and then exit.

// Source : This question was found on the hardware community on discord

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semEven;
sem_t semOdd;

int limit = 10;
int num = 1;

void* evenRoutine() {
    while(num < limit) {
        sem_wait(&semOdd);
        if(num <= limit) {
            printf("%d\n", num);
        }
        num++;
        sem_post(&semEven);
    }
}

void* oddRoutine() {
    while(num < limit) {
        sem_wait(&semEven);
        if(num <= limit) {
            printf("%d\n", num);
        }
        num++;
        sem_post(&semOdd);
    }
}

int main(int argc, char* argv[]) {
    sem_init(&semEven, 0, 0);
    sem_init(&semOdd, 0, 1);
    
    // create 2 threads
    pthread_t th[THREAD_NUM];

    for(int i=0; i<THREAD_NUM; i++) {
        if(i & 1) {
            // odd thread
            pthread_create(&th[i], NULL, oddRoutine, NULL);
        }
        else {
            // even thread
            pthread_create(&th[i], NULL, evenRoutine, NULL);
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    sem_destroy(&semEven);
    sem_destroy(&semOdd);

    return 0;
}