// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/0sVGnxg6Z3k?si=-8QFiDCy6zcurm_S)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Q You have fuelers that fill fuel. And you have cars that consume the fuel. 
// You want the fuellers to fill enough fuel before the cars try to consume it.
// This questions has a single car & single fueller.

// NOTE: Mutex-based code shows how mutexes alone cannot provide ordering.

int fuel = 0;
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;

void* fuel_filling(void* arg) {
    for(int i=0; i<5; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled Fuel. You have %d\n", fuel);
        pthread_cond_signal(&condFuel);
        pthread_mutex_unlock(&mutexFuel);
        sleep(1);
    }
}


// Failed Approach-1
// void* car(void* arg) {
//     pthread_mutex_lock(&mutexFuel);
//     fuel -= 40;
//     printf("Consumed fuel. You have %d\n", fuel);
//     pthread_mutex_unlock(&mutexFuel);
// }


// Failed Approach-2
// void* car(void* arg) {
//     pthread_mutex_lock(&mutexFuel);
//     if(fuel >= 40) {
//         fuel -= 40;
//         printf("Consumed fuel. You have %d\n", fuel);
//     }
//     else {
//         printf("No fuel. Can't drive car\n");
//     }
//     pthread_mutex_unlock(&mutexFuel);
// }

// // Failed Approach-3 : Deadlock
// void* car(void* arg) {
//     pthread_mutex_lock(&mutexFuel);
//     while(fuel < 40) {
//         printf("Waiting for fuel to be filled...\n");
//         sleep(1);
//     }
//     fuel -= 40;
//     printf("Consumed fuel. You have %d\n", fuel);
//     pthread_mutex_unlock(&mutexFuel);
// }

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
    pthread_t th[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for(int i=0; i<2; i++) {
        if(i == 1) {
            pthread_create(&th[i], NULL, &fuel_filling, NULL);
        }
        else {
            pthread_create(&th[i], NULL, &car, NULL);
        }
    }

    for(int i=0; i<2; i++) {
        pthread_join(th[i], NULL);
    }

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);

    return 0;
}