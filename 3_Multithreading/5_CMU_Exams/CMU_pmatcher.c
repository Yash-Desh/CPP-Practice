#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>



typedef struct {
    pthread_mutex_t mtx;
    pthread_cond_t cv1;
    pthread_cond_t cv2;
    int threads;
    int buf;
    int done;   // wait for partner
} pmatch_t;

int pmatch_match(pmatch_t* pm) {
    pthread_mutex_lock(&pm->mtx);

    while(pm->threads >= 2) {
        // All other threads wait here
        pthread_cond_wait(&pm->cv1, &pm->mtx);
    }
    pm->threads++;

    if(pm->threads == 1) {
        // 1st thread
        pm->buf = get_tid();
        while(pm->done == 0) {
            pthread_cond_wait(&pm->cv2, &pm->mtx);
        }
        pm->done = 0;
        int partner = pm->buf;
        pm->threads = 0;
        pthread_cond_broadcast(&pm->cv1);
        pthread_mutex_unlock(&pm->mtx);
        return partner;
    }
    else {
        // 2nd thread
        int partner2 = pm->buf;
        pm->buf = get_tid();
        pm->done = 1;
        pthread_cond_signal(&pm->cv2);
        pthread_mutex_unlock(&pm->mtx);
        return partner2;
    }   

}