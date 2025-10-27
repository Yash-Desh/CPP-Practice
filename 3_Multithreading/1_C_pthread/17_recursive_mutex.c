// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/Ot-VR3jzQMY?si=9wB5OE4eWRQWet3V)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;

int fuel = 50;

void* routine(void* args) {
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel);     // locking a mutex twice leads to a deadlock.
    fuel += 50;
    printf("Incremented fuel to %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexFuel);

    // In a recursive mutex, the number of lock & unlock on a particular mutex should be the same
    // in a particular thread. 
    // This feature is useful in recursive functions.
    // Note that recursive mutexes are not semaphores.
    // Semaphores can be unlocked by other threads, recursive mutexec cannot.
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];

    // Declare & Initialize the recursive mutex attribute.
    pthread_mutexattr_t recursiveMutexAttributes;
    pthread_mutexattr_init(&recursiveMutexAttributes);
    pthread_mutexattr_settype(&recursiveMutexAttributes, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutexFuel, &recursiveMutexAttributes);

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_create(&th[i], NULL, routine, NULL);
    }

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    printf("Fuel = %d\n", fuel);

    pthread_mutexattr_destroy(&recursiveMutexAttributes);
    pthread_mutex_destroy(&mutexFuel);

    return 0;
}