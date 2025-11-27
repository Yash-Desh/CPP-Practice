#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

typedef struct {
    pthread_mutex_t mtx;
    pthread_cond_t cv;
    bool lock;
} condlock_t;

void condlock_lock_when(condlock_t *clp, int (*predicate)(void *), void *arg) {
    pthread_mutex_lock(&clp->mtx);
    while(clp->lock == true || predicate(arg) == 0) {
        cond_wait(&clp->cv, &clp->mtx);
    }
    clp->lock = true;
    pthread_mutex_unlock(&clp->mtx);
}

void condlock_unlock(condlock_t* clp) {
    pthread_mutex_lock(&clp->mtx);
    clp->lock = false;
    pthread_cond_broadcast(&clp->cv);
    pthread_mutex_unlock(&clp->mtx);
}
