// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/RtTlIvnBw10?si=ceS751cwoenl2M2K)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Q You have fuelers that fill fuel. And you have cars that consume the fuel. 
// You want the fuellers to fill enough fuel before the cars try to consume it.
// This questions has a multiple car & single fueller.
// You can also have multiple cars & multiple fuellers.

int fuel = 0;
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;

void* fuel_filling(void* arg) {
    for(int i=0; i<5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 60;
        printf("Filled Fuel. You have %d\n", fuel);
        pthread_cond_broadcast(&condFuel);
        pthread_mutex_unlock(&mutexFuel);
        sleep(1);
    }
}

void* car(void* arg) {
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40) {
        printf("Waiting for fuel to be filled...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
        // Equivalent to -----------------------
        // pthread_mutex_unlock(&mutexFuel);
        // wait for signal on condFuel
        // pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;
    printf("Consumed fuel. You have %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}



int main(int argc, char* argv[]) {
    pthread_t th[5];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for(int i=0; i<5; i++) {
        // if(i == 4 && i == 5) {       --> solution remains the same if you have multiple fuellers.
        if(i == 4) {
            pthread_create(&th[i], NULL, &fuel_filling, NULL);
        }
        else {
            pthread_create(&th[i], NULL, &car, NULL);
        }
    }

    for(int i=0; i<5; i++) {
        pthread_join(th[i], NULL);
    }

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);

    return 0;
}