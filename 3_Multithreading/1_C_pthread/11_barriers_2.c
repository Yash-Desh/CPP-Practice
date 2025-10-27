// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/MDgVJVIRBnM?si=M_ltTBoK84wHIAhL)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// Problem : Every thread rolls the dice & saves its result to the array
// The main thread calculates the winner
// Each thread prints a message, whether it won or not.

// Q Why do we need 2 barriers ?

#define THREAD_NUM 8

pthread_barrier_t barrierRollDice;
pthread_barrier_t barrierCalculated;

int diceValues[8];
int status[8] = {0};        // --> shows whether a thread won or lost

void* rollDice(void* args) {
    int index = *(int *)args;
    diceValues[index] = rand() % 6 + 1;
    pthread_barrier_wait(&barrierRollDice);  
    pthread_barrier_wait(&barrierCalculated);
    if(status[index] == 1) {
        printf("%d rolled a dice value = %d. WON\n", index, diceValues[index]);
    }
    else {
        printf("%d rolled a dice value = %d. LOST\n", index, diceValues[index]);
    }
    free(args);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    // Barrier should wait for all 8 threads + the main thread
    pthread_barrier_init(&barrierRollDice, NULL, THREAD_NUM+1);
    pthread_barrier_init(&barrierCalculated, NULL, THREAD_NUM+1);
    pthread_t th[THREAD_NUM];

    for(int i=0; i<THREAD_NUM; i++) {
        int *temp = (int *)malloc(sizeof(int));
        *temp = i;
        pthread_create(&th[i], NULL, rollDice, temp);
    }

    pthread_barrier_wait(&barrierRollDice);

    // Calculate the winner.
    int max = 0;
    for(int i=0; i<THREAD_NUM; i++) {
        if(diceValues[i] > max) {
            max = diceValues[i];
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(diceValues[i] == max) {
            status[i] = 1;  
        }
        else { status[i] = 0; }
    }

    pthread_barrier_wait(&barrierCalculated);

    for(int i=0; i<THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }

    pthread_barrier_destroy(&barrierRollDice);
    pthread_barrier_destroy(&barrierCalculated);
    return 0;
}