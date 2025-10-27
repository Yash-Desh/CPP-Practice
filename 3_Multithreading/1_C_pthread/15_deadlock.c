// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/LjWug2tvSBU?si=vWcn_Rd6d5R8U---)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

void* routine(void* args) {
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel);     
    fuel += 50;
    printf("Incremented fuel to %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    // locking a mutex twice leads to a deadlock.
    // Thread already has the lock but tries to get the lock again.
    // 2nd time, the thread doesn't get the lock & as per rules of the
    // mutex, the thread sleeps.
    // Thus thread sleeps while holding the lock -> deadlock.
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_create(&th[i], NULL, routine, NULL);
    }

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    printf("Fuel = %d\n", fuel);
    pthread_mutex_destroy(&mutexFuel);

    return 0;
}