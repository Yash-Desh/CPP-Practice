// Author: Yash Deshpande
// Date  : 30-09-2026
// Tutor : Claude Opus 5

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

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
    int active_readers;
    int active_writers;
    pthread_cond_t cv;
    pthread_mutex_t mtx;

} rw_lock_t;

// Reader lock
void rw_lock_rlock(rw_lock_t * lck)
{
    pthread_mutex_lock(&lck->mtx);
    while(lck->active_writers > 0) {
        pthread_cond_wait(&lck->cv, &lck->mtx);
    }
    lck->active_readers++;
    pthread_mutex_unlock(&lck->mtx);
}

// Reader unlock
int rw_lock_runlock(rw_lock_t * lck)
{
    pthread_mutex_lock(&lck->mtx);
    lck->active_readers--;
    if(lck->active_readers == 0) {
        pthread_cond_broadcast(&lck->cv);
    }
    pthread_mutex_unlock(&lck->mtx);
    return 0;
}

// Writer lock
void rw_lock_wlock(rw_lock_t * lck)
{
    pthread_mutex_lock(&lck->mtx);
    while(lck->active_writers > 0 || lck->active_readers > 0) {
        pthread_cond_wait(&lck->cv, &lck->mtx);
    }
    lck->active_writers++;
    pthread_mutex_unlock(&lck->mtx);
}

// Writer unlock
int rw_lock_wunlock(rw_lock_t * lck)
{
    pthread_mutex_lock(&lck->mtx);
    lck->active_writers--;
    pthread_cond_broadcast(&lck->cv);
    pthread_mutex_unlock(&lck->mtx);
    return 0;
}

// Initialize a rw_lock_t struct
int rw_lock_init(rw_lock_t * lck)
{
    int rc = 0;

    lck->active_readers = 0;
    lck->active_writers = 0;

    rc = pthread_mutex_init(&lck->mtx, NULL);
    if(rc != 0) {
        return rc;
    }

    rc = pthread_cond_init(&lck->cv, NULL);
    if(rc != 0) {
        pthread_mutex_destroy(&lck->mtx);
        return rc;
    }

    return 0;
}

// Uninitialize a rw_lock_t struct
int rw_lock_destroy(rw_lock_t * lck)
{
    int rc = pthread_cond_destroy(&lck->cv);
    int rc2 = pthread_mutex_destroy(&lck->mtx);

    return (rc != 0) ? rc : rc2;
}

// allow as many readers as possible 
// only 1 writer 
// 