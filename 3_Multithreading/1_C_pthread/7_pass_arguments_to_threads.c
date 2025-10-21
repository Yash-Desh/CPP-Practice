// Author: Yash Deshpande
// Date  : 19-10-2025
// Tutor : CodeVault (https://youtu.be/HDohXvS6UIk?si=RMWxheNQaz0uzKPW)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Problem : Create 10 threads each taking a unique prime from the primes array
// & print it on screen.

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    // sleep(1);
    // 1 - typecast the void pointer to an int pointer
    // 2 - dereference the int pointer
    int index = *(int*)arg;
    printf("%dth prime number = %d\n", index, primes[index]);

    // Free the dynamically allocated memory
    free(arg);
}

int main(int argc, char* argv) {
    pthread_t th[10];

    for(int i=0; i<10; i++) {
        // malloc memory to store unique value of i for every thread
        // NOTE: If you pass in a static variable 'i', its value may change
        // by the time the thread actually gets to run.
        // i.e. the value of 'i' may change from thread creation to thread running time.
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, routine, a);
    }

    for(int i=0; i<10; i++) {
        pthread_join(th[i], NULL);
    }
    return 0;
}