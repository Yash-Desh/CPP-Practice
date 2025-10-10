// Author : Yash Deshpande
// Date   : 08-10-2025
// Tutor  : CodeVault YT (https://youtu.be/oq29KUy29iQ?si=nMiOPYwU0EsPoLiO)

// ----------------------------------------------------------------------
// Compilation command: gcc -lpthread <file_name.c> -o <executable_name>
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Shared variable
int mail = 0;

// Declare a single mutex
pthread_mutex_t mutex;

void* routine() {
    for(int i=0; i<1000000; i++) {
        pthread_mutex_lock(&mutex);
        mail++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[]) {
    pthread_t t1, t2, t3, t4;

    // Initialize the mutex.
    // Arguments: Address of the mutex, some arguments
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, routine, NULL);
    pthread_create(&t2, NULL, routine, NULL);
    pthread_create(&t3, NULL, routine, NULL);
    pthread_create(&t4, NULL, routine, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    // Destroy the mutex.
    pthread_mutex_destroy(&mutex);

    // Printing in the parent.
    printf("Number of mails = %d\n", mail);
    return 0;
}