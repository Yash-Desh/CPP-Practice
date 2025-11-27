#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* Assume P2-style mutex/cond interfaces are available. */
typedef struct sem {
    pthread_mutex_t m;     /* protects all fields below */
    pthread_cond_t  cv;    /* condition variable for waiters */
    int     avail; /* number of resources currently available */
} sem_t;

/* Optional: no aux structure needed for this simple solution. */
typedef struct aux {
    int unused;
} aux_t;

/* Initialize the super semaphore with 'initial' resources. */
int sem_init(sem_t *sem, int initial)
{
    pthread_mutex_init(&sem->m, NULL);    /* exam: assume can’t fail */
    pthread_cond_init(&sem->cv, NULL);    /* exam: assume can’t fail */
    sem->avail = initial;
    return 0;
}

/* Acquire 'request' resources from the semaphore. */
void sem_wait(sem_t *sem, int request)
{
    pthread_mutex_lock(&sem->m);

    /* Wait until there are enough resources for this entire request. */
    while (sem->avail < request) {
        pthread_cond_wait(&sem->cv, &sem->m);
    }

    /* Now there are enough resources; take them. */
    sem->avail -= request;

    pthread_mutex_unlock(&sem->m);
}

/* Release 'release' resources back to the semaphore. */
void sem_signal(sem_t *sem, int release)
{
    mutex_lock(&sem->m);

    sem->avail += release;

    /* Some waiting threads may now be able to proceed. */
    cond_broadcast(&sem->cv);

    mutex_unlock(&sem->m);
}
