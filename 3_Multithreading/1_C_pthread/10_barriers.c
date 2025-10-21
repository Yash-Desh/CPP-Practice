// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/_P-HYxHsVPc?si=T4cj_wSwu8hKesQ4)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_barrier_t barrier;

void* routine(void *args) {
    while(1) {
        printf("Waiting at the barrier...\n");
        sleep(1);
        pthread_barrier_wait(&barrier);
        printf("Exiting the barrier\n");
        sleep(1);
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[10];

    // Arguments
    // reference to the barrier object
    // Attributes for the barrier
    // Number of threads at the barrier.
    pthread_barrier_init(&barrier, NULL, 7);

    for(int i=0; i<10; i++) {
        pthread_create(&th[i], NULL, routine, NULL);
    }

    for(int i=0; i<10; i++) {
        pthread_join(th[i], NULL);
    }

    pthread_barrier_destroy(&barrier);
    return 0;
}