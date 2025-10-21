// Author: Yash Deshpande
// Date  : 19-10-2025
// Tutor : CodeVault (https://youtu.be/xoXzp4B8aQk?si=I2oH4ndz-P-3vMUl)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine() {
    for(int i=0; i<10000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[4];

    // for-loop to create threads.
    for(int i=0; i<4; i++) {
        pthread_create(&th[i], NULL, routine, NULL);
        printf("thread %d has started\n", i);
    }

    // for-loop to join all threads
    for(int i=0; i<4; i++) {
        pthread_join(th[i], NULL);
        printf("thread %d has finished\n", i);
    }

    // Note that this finish statement doesn't represent the order in which threads
    // finish execution but rather the order in which the for loop increments the 
    // the 'i' variable.
    // For e.g. we could have thread-4 finishing earliest but will not print the 
    // finish statement till the for-loop reaches i=4 

    pthread_mutex_destroy(&mutex);
    printf("number of mails = %d\n", mails);

    return 0;
}