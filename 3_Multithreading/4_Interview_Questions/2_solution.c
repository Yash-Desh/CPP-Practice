#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// This is an implementation of the writer-fair reader-writer lock to avoid writer starvation.

// pthread_mutex_* and pthread_cond_* are allowed to be used
// int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
// int pthread_mutex_destroy(pthread_mutex_t *mutex);
// int pthread_mutex_lock(pthread_mutex_t *mutex);
// int pthread_mutex_unlock(pthread_mutex_t *mutex);
// int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
// int pthread_cond_destroy(pthread_cond_t *cond);
// int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
// int pthread_cond_signal(pthread_cond_t *cond);
// int pthread_cond_broadcast(pthread_cond_t *cond);


typedef struct rw_lock_s 
{
    // TODO
    pthread_mutex_t mutex;
    pthread_cond_t  readers_cv;   // readers wait here
    pthread_cond_t  writers_cv;   // writers wait here
    int readers;                  // active readers
    int writer_active;            // 1 if a writer holds the lock
    int writers_waiting;          // number of writers waiting (for fairness)
} rw_lock_t;


// Initialize a rw_lock_t struct
int rw_lock_init(rw_lock_t * lck)
{
    // TODO
    lck->readers = 0;
    lck->writer_active = 0;
    lck->writers_waiting = 0;
    pthread_mutex_init(&lck->mutex, NULL);
    pthread_cond_init(&lck->readers_cv, NULL);
    pthread_cond_init(&lck->writers_cv, NULL);
    return 0;
}

// Reader lock
void rw_lock_rlock(rw_lock_t * lck)
{
    // TODO
    pthread_mutex_lock(&lck->mutex);
    while(lck->writer_active || lck->writers_waiting > 0) {
        pthread_cond_wait(&lck->readers_cv, &lck->mutex);
    }
    lck->readers++;
    pthread_mutex_unlock(&lck->mutex);
    return 0;
}

// Reader unlock
int rw_lock_runlock(rw_lock_t * lck)
{
    // TODO
    pthread_mutex_lock(&lck->mutex);
    lck->readers--;
    if(lck->readers == 0 && lck->writers_waiting > 0) {
        pthread_cond_signal(&lck->writers_cv);
    }
    pthread_mutex_unlock(&lck->mutex);
    return 0;
}

// Writer lock
void rw_lock_wlock(rw_lock_t * lck)
{
    // TODO
    pthread_mutex_lock(&lck->mutex);
    while(lck->writer_active || lck->writers_waiting > 0 || lck->readers > 0) {
        lck->writers_waiting++;
        pthread_cond_wait(&lck->writers_cv, &lck->mutex);
    }
    lck->writers_waiting--;
    lck->writer_active = 1;
    pthread_mutex_unlock(&lck->mutex);
    return 0;
}

// Writer unlock
int rw_lock_wunlock(rw_lock_t * lck)
{
    // TODO
    pthread_mutex_lock(&lck->mutex);
    lck->writer_active = 0;
    if(lck->writers_waiting > 0) {
        pthread_cond_signal(&lck->writers_cv);
    }
    else {
        pthread_cond_broadcast(&lck->readers_cv);
    }
    pthread_mutex_unlock(&lck->mutex);
    return 0;
}



// Uninitialize a rw_lock_t struct
int rw_lock_destroy(rw_lock_t * lck)
{
    // TODO
    pthread_mutex_destroy(&lck->mutex);
    pthread_cond_destroy(&lck->readers_cv);
    pthread_cond_destroy(&lck->writers_cv);
}

// allow as many readers as possible 
// only 1 writer 
// 