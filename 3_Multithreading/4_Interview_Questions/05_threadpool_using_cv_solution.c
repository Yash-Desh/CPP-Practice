// Build: gcc -Wall -pthread 05_threadpool_using_cv_solution.c -o threadpool && ./threadpool

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// used only by the tests at the bottom of the file
#include <signal.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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

// Do NOT spin-wait. Idle workers must sleep.


typedef void (*task_fn)(void * arg);

// One entry in the task queue.
// Generic version of Task from 26_thread_pool_2.c: instead of a fixed
// void (*)(int, int) plus two ints, any function with any argument.
typedef struct task_s
{
    task_fn taskFunction;
    void *  arg;

} task_t;

typedef struct threadpool_s
{
    // Bounded circular buffer of tasks.
    // Replaces taskQueue[256] + shifting every element on each pop.
    int MAX;            // capacity
    int fill_ptr;       // next slot submit() writes to
    int use_ptr;        // next slot a worker reads from
    int size;           // number of tasks currently queued (was taskCount)
    task_t *buf;

    int numThreads;
    pthread_t *threads;

    int shutdown;       // set by destroy(): the missing exit condition

    pthread_mutex_t mutexQueue;
    pthread_cond_t  condNotEmpty;   // workers wait here (was condQueue)
    pthread_cond_t  condNotFull;    // submit() waits here when the queue is full

} threadpool_t;

int threadpool_destroy(threadpool_t * pool);   // used by create() on failure

static void executeTask(task_t * task)
{
    task->taskFunction(task->arg);
}

// Worker thread body: repeatedly take a task off the queue and run it.
static void * worker(void * arg)
{
    threadpool_t * pool = arg;

    while (1)
    {
        task_t task;

        pthread_mutex_lock(&pool->mutexQueue);

        // Sleep while there is nothing to do and nobody asked us to stop.
        while (pool->size == 0 && !pool->shutdown)
        {
            pthread_cond_wait(&pool->condNotEmpty, &pool->mutexQueue);
        }

        // Exit only once the queue is drained, so destroy() never drops
        // tasks that were already submitted.
        if (pool->size == 0 && pool->shutdown)
        {
            pthread_mutex_unlock(&pool->mutexQueue);
            return NULL;
        }

        task = pool->buf[pool->use_ptr];
        pool->use_ptr = (pool->use_ptr + 1) % pool->MAX;
        pool->size--;

        // A slot just freed up: wake one producer blocked in submit().
        pthread_cond_signal(&pool->condNotFull);
        pthread_mutex_unlock(&pool->mutexQueue);

        // Execution of task should happen outside of the critical section
        executeTask(&task);
    }
}

// Create a pool with n worker threads and a task queue of capacity cap.
threadpool_t * threadpool_create(unsigned int n, unsigned int cap)
{
    if (n == 0 || cap == 0)
        return NULL;

    // Must be on the heap: the workers keep using it after we return.
    threadpool_t * pool = malloc(sizeof *pool);
    if (pool == NULL)
        return NULL;

    pool->MAX        = cap;
    pool->fill_ptr   = 0;
    pool->use_ptr    = 0;
    pool->size       = 0;
    pool->shutdown   = 0;
    pool->numThreads = 0;
    pool->buf        = malloc(cap * sizeof(task_t));
    pool->threads    = malloc(n * sizeof(pthread_t));

    if (pool->buf == NULL || pool->threads == NULL)
    {
        free(pool->buf);
        free(pool->threads);
        free(pool);
        return NULL;
    }

    pthread_mutex_init(&pool->mutexQueue, NULL);
    pthread_cond_init(&pool->condNotEmpty, NULL);
    pthread_cond_init(&pool->condNotFull, NULL);

    for (unsigned int i = 0; i < n; i++)
    {
        if (pthread_create(&pool->threads[i], NULL, worker, pool) != 0)
        {
            // Shut down the workers that did start, then report failure.
            perror("Failed to create thread");
            threadpool_destroy(pool);
            return NULL;
        }
        pool->numThreads++;
    }

    return pool;
}

// Enqueue a task. Blocks if the queue is full.
// Returns 0 on success, -1 if the pool is shutting down.
int threadpool_submit(threadpool_t * pool, task_fn fn, void * arg)
{
    pthread_mutex_lock(&pool->mutexQueue);

    // Bounded queue: wait for a free slot instead of overflowing.
    while (pool->size == pool->MAX && !pool->shutdown)
    {
        pthread_cond_wait(&pool->condNotFull, &pool->mutexQueue);
    }

    if (pool->shutdown)
    {
        pthread_mutex_unlock(&pool->mutexQueue);
        return -1;
    }

    pool->buf[pool->fill_ptr].taskFunction = fn;
    pool->buf[pool->fill_ptr].arg          = arg;
    pool->fill_ptr = (pool->fill_ptr + 1) % pool->MAX;
    pool->size++;

    pthread_cond_signal(&pool->condNotEmpty);
    pthread_mutex_unlock(&pool->mutexQueue);

    return 0;
}

// Stop accepting new work, let queued tasks drain, join all workers, free.
int threadpool_destroy(threadpool_t * pool)
{
    pthread_mutex_lock(&pool->mutexQueue);
    pool->shutdown = 1;
    // broadcast, not signal: EVERY sleeping worker has to wake up and exit,
    // and any producer blocked in submit() has to wake up and return -1.
    pthread_cond_broadcast(&pool->condNotEmpty);
    pthread_cond_broadcast(&pool->condNotFull);
    pthread_mutex_unlock(&pool->mutexQueue);

    for (int i = 0; i < pool->numThreads; i++)
    {
        if (pthread_join(pool->threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }

    pthread_mutex_destroy(&pool->mutexQueue);
    pthread_cond_destroy(&pool->condNotEmpty);
    pthread_cond_destroy(&pool->condNotFull);

    free(pool->buf);
    free(pool->threads);
    free(pool);

    return 0;
}

// n worker threads, created once
// queue holds at most cap tasks
// every submitted task runs exactly once
// destroy must not lose queued tasks and must not leave a worker asleep
//


// ===========================================================================
// Tests. Do not modify below this line.
//
// Each test has a 5 second timeout: a hang (deadlock, lost wakeup, worker
// never exiting) is reported as a failure instead of freezing the terminal.
// ===========================================================================

#define CHECK(cond)                                                         \
    do {                                                                    \
        if (!(cond)) {                                                      \
            fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
            exit(1);                                                        \
        }                                                                   \
    } while (0)

static const char * current_test = "";

static void on_timeout(int sig)
{
    (void)sig;
    // only async-signal-safe calls in here
    const char msg[] = "FAIL: timed out (deadlock, lost wakeup, or worker never exited)\n";
    write(STDERR_FILENO, msg, sizeof msg - 1);
    _exit(1);
}

static void test_begin(const char * name)
{
    current_test = name;
    printf("RUN  %s\n", name);
    fflush(stdout);
    alarm(5);
}

static void test_end(void)
{
    alarm(0);
    printf("PASS %s\n", current_test);
}

static void sleep_ms(long ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000000L };
    nanosleep(&ts, NULL);
}

// Test-side bookkeeping. Protected by its own lock, independent of the pool.
static pthread_mutex_t t_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  t_cond = PTHREAD_COND_INITIALIZER;


// ---------------------------------------------------------------------------
// Each task records its own id, so we can check every task ran exactly once
// and that it received the right argument.
// ---------------------------------------------------------------------------

#define MAX_TASKS 1000
static int runs[MAX_TASKS];

static void count_task(void * arg)
{
    long id = (long)arg;
    pthread_mutex_lock(&t_lock);
    runs[id]++;
    pthread_mutex_unlock(&t_lock);
}

static void check_each_ran_once(int num_tasks)
{
    for (int i = 0; i < num_tasks; i++)
    {
        if (runs[i] != 1)
        {
            fprintf(stderr, "FAIL: task %d ran %d times (expected 1)\n", i, runs[i]);
            exit(1);
        }
    }
}


// 1. Creating and destroying a pool that never got any work must not hang:
//    every worker is asleep on an empty queue and must be woken to exit.
static void test_idle_destroy(void)
{
    test_begin("idle pool can be destroyed");

    threadpool_t * pool = threadpool_create(4, 4);
    CHECK(pool != NULL);
    threadpool_destroy(pool);

    // smallest possible pool
    pool = threadpool_create(1, 1);
    CHECK(pool != NULL);
    threadpool_destroy(pool);

    test_end();
}


// 2. Every task runs exactly once, with the argument it was submitted with.
//    destroy() is called right after the last submit, so tasks are still
//    queued: destroy must drain them, not drop them.
static void test_every_task_runs_once(void)
{
    test_begin("every task runs exactly once, destroy drains the queue");

    memset(runs, 0, sizeof runs);

    threadpool_t * pool = threadpool_create(4, 8);
    CHECK(pool != NULL);

    for (long i = 0; i < MAX_TASKS; i++)
    {
        CHECK(threadpool_submit(pool, count_task, (void *)i) == 0);
    }

    threadpool_destroy(pool);

    check_each_ran_once(MAX_TASKS);

    test_end();
}


// 3. Several threads submit at the same time.
#define NUM_PRODUCERS      4
#define TASKS_PER_PRODUCER (MAX_TASKS / NUM_PRODUCERS)

typedef struct
{
    threadpool_t * pool;
    long           first_id;
} producer_arg_t;

static void * producer(void * arg)
{
    producer_arg_t * p = arg;
    for (long i = 0; i < TASKS_PER_PRODUCER; i++)
    {
        CHECK(threadpool_submit(p->pool, count_task, (void *)(p->first_id + i)) == 0);
    }
    return NULL;
}

static void test_multiple_producers(void)
{
    test_begin("multiple producers submitting concurrently");

    memset(runs, 0, sizeof runs);

    threadpool_t * pool = threadpool_create(3, 5);
    CHECK(pool != NULL);

    pthread_t      th[NUM_PRODUCERS];
    producer_arg_t args[NUM_PRODUCERS];

    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        args[i].pool     = pool;
        args[i].first_id = (long)i * TASKS_PER_PRODUCER;
        pthread_create(&th[i], NULL, producer, &args[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        pthread_join(th[i], NULL);
    }

    threadpool_destroy(pool);

    check_each_ran_once(NUM_PRODUCERS * TASKS_PER_PRODUCER);

    test_end();
}


// 4. Workers run tasks in parallel, and submit() blocks when the queue is full.
//
//    Every task blocks on a gate. With n workers and capacity cap:
//      - n tasks are taken off the queue and are running (stuck at the gate)
//      - cap more tasks fill the queue
//      - the next submit() has nowhere to go and must block
//    So while the gate is closed, exactly n + cap submits may have returned.
#define GATE_WORKERS 3
#define GATE_CAP     4
#define GATE_TASKS   (GATE_WORKERS + GATE_CAP + 1)

static int gate_open;
static int running;
static int max_running;
static int completed;
static int submitted;

static void gate_task(void * arg)
{
    (void)arg;
    pthread_mutex_lock(&t_lock);

    running++;
    if (running > max_running)
        max_running = running;
    pthread_cond_broadcast(&t_cond);

    while (!gate_open)
        pthread_cond_wait(&t_cond, &t_lock);

    running--;
    completed++;

    pthread_mutex_unlock(&t_lock);
}

static void * gate_producer(void * arg)
{
    threadpool_t * pool = arg;
    for (int i = 0; i < GATE_TASKS; i++)
    {
        CHECK(threadpool_submit(pool, gate_task, NULL) == 0);

        pthread_mutex_lock(&t_lock);
        submitted++;
        pthread_mutex_unlock(&t_lock);
    }
    return NULL;
}

static void test_parallel_and_bounded(void)
{
    test_begin("workers run in parallel, submit blocks when queue is full");

    gate_open = running = max_running = completed = submitted = 0;

    threadpool_t * pool = threadpool_create(GATE_WORKERS, GATE_CAP);
    CHECK(pool != NULL);

    pthread_t prod;
    pthread_create(&prod, NULL, gate_producer, pool);

    // Wait until every worker is busy at the gate. If workers don't run in
    // parallel, this never happens and the timeout fires.
    pthread_mutex_lock(&t_lock);
    while (running < GATE_WORKERS)
        pthread_cond_wait(&t_cond, &t_lock);
    pthread_mutex_unlock(&t_lock);

    // Give the producer time to fill the queue and get stuck on the next one.
    sleep_ms(200);

    pthread_mutex_lock(&t_lock);
    int submitted_while_full = submitted;
    pthread_mutex_unlock(&t_lock);

    if (submitted_while_full != GATE_WORKERS + GATE_CAP)
    {
        fprintf(stderr, "FAIL: %d submits returned while the queue was full (expected %d)\n",
                submitted_while_full, GATE_WORKERS + GATE_CAP);
        if (submitted_while_full > GATE_WORKERS + GATE_CAP)
            fprintf(stderr, "      submit() did not block: queue is not bounded\n");
        exit(1);
    }

    // Release everything; the blocked submit must now get through.
    pthread_mutex_lock(&t_lock);
    gate_open = 1;
    pthread_cond_broadcast(&t_cond);
    pthread_mutex_unlock(&t_lock);

    pthread_join(prod, NULL);
    threadpool_destroy(pool);

    CHECK(completed == GATE_TASKS);
    CHECK(max_running == GATE_WORKERS);   // never more tasks in flight than workers

    test_end();
}


int main(void)
{
    signal(SIGALRM, on_timeout);

    test_idle_destroy();
    test_every_task_runs_once();
    test_multiple_producers();
    test_parallel_and_bounded();

    printf("\nAll tests passed.\n");
    return 0;
}
