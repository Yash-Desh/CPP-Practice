// Author: Yash Deshpande
// Date  : 20-10-2025
// Tutor : CodeVault (https://youtu.be/OIKr2ll2Nd8?si=Dx_mGCi6XjmNvU4T)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

// void* routine() {
//     pthread_mutex_lock(&mutex);
//     printf("Got Lock\n");
//     sleep(1);
//     pthread_mutex_unlock(&mutex);
// }

// trylock returns 0 if it grabs the lock
// trylock returns non-zero value if it fails to lock

void* routine() {
    if(pthread_mutex_trylock(&mutex) == 0) {
        printf("Got Lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else {
        printf("Didn't get Lock\n");
    }
}

int main(int argc, char* argv[]) {

    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);

    for(int i=0; i<4; i++) {
        pthread_create(&th[i], NULL, routine, NULL);
    }

    for(int i=0; i<4; i++) {
        pthread_join(th[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}