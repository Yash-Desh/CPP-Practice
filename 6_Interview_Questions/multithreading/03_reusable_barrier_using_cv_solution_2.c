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
    pthread_mutex_t m;      // guards at_barrier
    pthread_cond_t cv;      // threads park here until the last one arrives
    int at_barrier;         // how many have arrived so far
    int total;              // how many we are waiting for
    int generation;         // which round we are on

} barrier_t;

// Initialize a barrier_t struct for n participating threads
int barrier_init(barrier_t * bar, unsigned int n)
{
    bar->total = n;
    bar->at_barrier = 0;
    bar->generation = 0;

    pthread_mutex_init(&bar->m, NULL);
    pthread_cond_init(&bar->cv, NULL);

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
    pthread_mutex_lock(&bar->m);
    bar->at_barrier++;

    int my_generation = bar->generation;

    int returnVal = (bar->at_barrier == bar->total);

    if (bar->at_barrier == bar->total) {
        bar->generation++;
        bar->at_barrier = 0;
    }

    while (my_generation >= bar->generation) {
        pthread_cond_wait(&bar->cv, &bar->m);
    }

    pthread_cond_broadcast(&bar->cv);
    pthread_mutex_unlock(&bar->m);

    return returnVal;
}

// Uninitialize a barrier_t struct
int barrier_destroy(barrier_t * bar)
{
    pthread_mutex_destroy(&bar->m);
    pthread_cond_destroy(&bar->cv);

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
