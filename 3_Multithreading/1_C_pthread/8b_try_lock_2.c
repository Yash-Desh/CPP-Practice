// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/UrTU7ss3LDc?si=dqe5WyhLSURLE9dc)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// Q You have 4 stoves each has a starting fuel amount of 100. If the stoves run out of 
// fuel needed by the chefs to cook then the chefs go home. Make sure all the chefs cook.
// Watch the video if you don't really understand the code, as it is a made-up situation.
// chefs = threads
// stove = shared data (+mutex)

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = {100, 100, 100, 100};

void* routine() {

    // Choose your stove
    for(int i=0; i<4; i++) {
        if(pthread_mutex_trylock(&stoveMutex[i]) == 0) {
            // Got lock the ith stove, cook once & leave.
            int fuelNeeded = rand() % 30;
            if(stoveFuel[i] < fuelNeeded) {
                printf("Insufficient Fuel...going home\n");
            }
            else {
                stoveFuel[i] -= fuelNeeded;
                usleep(500000);
                printf("Got Fuel. Fuel left = %d\n", stoveFuel[i]);
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            break;
        }
        else {
            // None of the stoves is vacant
            // Make the thread sleep till one of the stoves is vacant,
            // set the thread to rerun the loop.
            if(i == 3) {
                printf("No stove available for cooking, Waiting...\n");
                usleep(3000000);
                i = 0;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    pthread_t th[10];
    
    // Initialize 4 mutexes, 1 per each stove.
    for(int i=0; i<4; i++) {
        pthread_mutex_init(&stoveMutex[i], NULL);
    }

    for(int i=0; i<10; i++) {
        pthread_create(&th[i], NULL, routine, NULL);
    }

    for(int i=0; i<10; i++) {
        pthread_join(th[i], NULL);
    }

    // Destroy the 4 mutexes, 1 per each stove.
    for(int i=0; i<4; i++) {
        pthread_mutex_destroy(&stoveMutex[i]);
    }

    return 0;
}