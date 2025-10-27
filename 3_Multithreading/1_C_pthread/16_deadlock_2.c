// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/LjWug2tvSBU?si=vWcn_Rd6d5R8U---)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Acquiring locks in different orders can lead to deadlocks.

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
pthread_mutex_t mutexWater;
int fuel = 50;
int water = 10;

void* routine1(void* args) {
    pthread_mutex_lock(&mutexFuel);
    sleep(1);
    pthread_mutex_lock(&mutexWater);
    
    fuel += 50;
    water = fuel;

    printf("Incremented fuel to %d & set water to %d\n", fuel, water);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexWater);

}

void* routine2(void* args) {
    pthread_mutex_lock(&mutexWater);
    sleep(1);
    pthread_mutex_lock(&mutexFuel);
    
    fuel += 50;
    water = fuel;

    printf("Incremented fuel to %d & set water to %d\n", fuel, water);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexWater);

}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_mutex_init(&mutexWater, NULL);

    for(int i=0; i<THREAD_NUM; i++) {
        if(i == 0) {
            pthread_create(&th[i], NULL, routine1, NULL);
        }
        else {
            pthread_create(&th[i], NULL, routine2, NULL);
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    printf("Fuel = %d\n", fuel);
    pthread_mutex_destroy(&mutexFuel);
    pthread_mutex_destroy(&mutexWater);
    

    return 0;
}