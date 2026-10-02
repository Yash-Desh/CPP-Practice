// Author: Yash Deshpande
// Date  : 01-10-2026
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

// Do NOT use pthread_barrier_t. Implement it yourself.


typedef struct barrier_s
{
    sem_t mutex;        // guards at_barrier, initial value 1
    sem_t sem1;         // gate 1, starts closed (0)
    sem_t sem2;         // gate 2, starts open   (1)
    int at_barrier;     // how many have arrived so far
    int total;          // how many we are waiting for

} barrier_t;

// Initialize a barrier_t struct for n participating threads
int barrier_init(barrier_t * bar, unsigned int n)
{
    bar->total = n;
    bar->at_barrier = 0;

    sem_init(&bar->mutex, 0, 1);
    sem_init(&bar->sem1, 0, 0);
    sem_init(&bar->sem2, 0, 1);

    return 0;
}

// Block until all n threads have called barrier_wait().
// Once the n-th thread arrives, all n are released and the barrier
// is immediately usable again for the next round.
//
// Returns 1 in exactly one of the n threads (the "serial" thread),
// 0 in all the others.
int barrier_wait(barrier_t * bar)
{
    sem_wait(&bar->mutex);
    bar->at_barrier++;

    if (bar->at_barrier < bar->total) {
        sem_post(&bar->mutex);

        sem_wait(&bar->sem1);    // park until the last thread arrives
        sem_post(&bar->sem1);    // cascade the wakeup to the next waiter
        
    }
    else {
        // Last thread of a generation close the 2nd gate
        sem_post(&bar->mutex);
        sem_wait(&bar->sem2);
        sem_post(&bar->sem1);    // last thread in: open the gate
        
    }

    // cleared first gate
    sem_wait(&bar->mutex);
    bar->at_barrier--;

    if (bar->at_barrier > 0) {
        sem_post(&bar->mutex);

        sem_wait(&bar->sem2);    // park until the last thread arrives
        sem_post(&bar->sem2);    // cascade the wakeup to the next waiter
        return 0;
    }
    else {
        // Last thread of a generation close the 2nd gate
        sem_post(&bar->mutex);
        sem_wait(&bar->sem1);
        sem_post(&bar->sem2);    // last thread in: open the gate
        return 1;
    }
}

// Uninitialize a barrier_t struct
int barrier_destroy(barrier_t * bar)
{
    sem_destroy(&bar->mutex);
    sem_destroy(&bar->sem1);
    sem_destroy(&bar->sem2);

    return 0;
}


// ---------------------------------------------------------------------------
// Example usage: each thread does some work, syncs up, then repeats.
// Every thread must finish round i before any thread starts round i+1.
// ---------------------------------------------------------------------------

#define NUM_THREADS 4
#define NUM_ROUNDS  3

barrier_t bar;

void * worker(void * arg)
{
    long id = (long)arg;

    for (int round = 0; round < NUM_ROUNDS; round++)
    {
        printf("thread %ld working on round %d\n", id, round);

        int is_serial = barrier_wait(&bar);

        if (is_serial)
        {
            printf("---- round %d complete ----\n", round);
        }
    }

    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];

    barrier_init(&bar, NUM_THREADS);

    for (long i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], NULL, worker, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    barrier_destroy(&bar);

    return 0;
}

// barrier must release exactly n threads at a time
// barrier must be reusable: round i+1 must not let a fast thread
//   slip through while a slow thread is still being released from round i
// no thread may return from barrier_wait() before all n have arrived
//
