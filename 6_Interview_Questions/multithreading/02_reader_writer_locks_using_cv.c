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
    // TODO
    
} rw_lock_t;

// Reader lock
void rw_lock_rlock(rw_lock_t * lck)
{
    // TODO
}

// Reader unlock
int rw_lock_runlock(rw_lock_t * lck)
{
    // TODO
}

// Writer lock
void rw_lock_wlock(rw_lock_t * lck)
{
    // TODO
}

// Writer unlock
int rw_lock_wunlock(rw_lock_t * lck)
{
    // TODO
    
}

// Initialize a rw_lock_t struct
int rw_lock_init(rw_lock_t * lck)
{
    // TODO
}

// Uninitialize a rw_lock_t struct
int rw_lock_destroy(rw_lock_t * lck)
{
    // TODO
}

// allow as many readers as possible 
// only 1 writer 
// 