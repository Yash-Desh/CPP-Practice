// Author: Yash Deshpande
// Date  : 19-10-2025
// Tutor : CodeVault (https://youtu.be/HDohXvS6UIk?si=RMWxheNQaz0uzKPW)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Problem : Create 2 threads each taking a 5 primes from the primes array
// & adding them up.

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    // sleep(1);
    // 1 - typecast the void pointer to an int pointer
    // 2 - dereference the int pointer
    int index = *(int*)arg;

    int sum = 0;
    for(int j=0; j<5; j++) {
        sum += primes[j + index];
    }
    printf("local sum = %d\n", sum);

    *(int*)arg = sum;
    return arg; 
}

int main(int argc, char* argv) {
    pthread_t th[2];

    for(int i=0; i<2; i++) {
        // malloc memory to store unique value of i for every thread
        int *a = malloc(sizeof(int));
        *a = i * 5;
        pthread_create(&th[i], NULL, routine, a);
    }

    int global_sum = 0;
    for(int i=0; i<2; i++) {
        int *r;
        pthread_join(th[i], (void **)&r);

        global_sum += *r;
        free(r);
    }
    printf("global sum of prime number = %d\n", global_sum);
    return 0;
}