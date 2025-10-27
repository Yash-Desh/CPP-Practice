// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/l6zkaJFjUbM?si=PCfNHHDIZW3qKlb-)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

// 1Producer-1Consumer-10Buffer-Infinite Loop

#define THREAD_NUM 2

pthread_mutex_t mutex;

sem_t semFull;          // how many full slots do you have at the beginning ? 0
sem_t semEmpty;         // how many empty slots do you have at the beginning ? 10

// Buffer to read & write from
int buffer[10];
int count = 0;

void* producer(void* args) {
    while(1) {
        // Produce: generate a random number to store in the buffer
        int x = rand() % 100; 
        sleep(1);  
        
        // Add to the buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutex);
        buffer[count] = x;
        count++;
        pthread_mutex_unlock(&mutex);
        sem_post(&semFull);
    }
}

void* consumer(void* args) {
    while(1) {
        int y = -1;

        // Remove from the buffer : FIFO
        sem_wait(&semFull);
        pthread_mutex_lock(&mutex);
        y = buffer[count-1];
        count--;
        pthread_mutex_unlock(&mutex);
        sem_post(&semEmpty);

        // Consume the buffer data
        printf("Consumer got %d\n", y);
        sleep(1);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    sem_init(&semEmpty, 0, 10);
    sem_init(&semFull, 0, 0);
    pthread_t th[THREAD_NUM];

    for(int i=0; i<THREAD_NUM; i++) {
        if(i%2 != 0) {
            if(pthread_create(&th[i], NULL, &producer, NULL) != 0) {
                perror("Failed to create thread\n");
            }
        }
        else {
            if(pthread_create(&th[i], NULL, &consumer, NULL) != 0) {
                perror("Failed to create thread\n");
            }
        }
    }


    for(int i=0; i < THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL) != 0) {
            perror("Failed to join threads\n");
        }
    }

    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutex);

    return 0;
}
