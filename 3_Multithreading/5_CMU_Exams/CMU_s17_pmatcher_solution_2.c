// Author: Yash Deshpande
// Date  : 03-10-2026
// Tutor : Claude Opus 5.5
// Paper : Operating-Systems-Practice/9_CMU_15-410/papers/s17-midterm-examA.pdf
// Link  : 

// CMU 15-410 Spring 2017 Midterm, Question 3 (15 points): Pair matching.
//
// In lecture we talked about two fundamental operations in concurrent programming: brief mutual
// exclusion for atomic sequences (provided in P2 by mutexes) and long-term voluntary descheduling
// (provided by condition variables). As you know, these can be combined to produce higher-level
// objects such as semaphores or readers/writers locks.
//
// In this question you will implement a synchronization object called a "pair matcher." The idea
// is that some parallel tasks must be worked on by pairs of threads, and the threads need some
// (dynamic) way to pick a partner to work with. After a pair matcher is initialized, an even number
// of threads will invoke the match operation. The match operation involves some amount of thread
// synchronization, potentially including blocking, and then returns to each thread, in a reasonably
// timely fashion, the thread identification number of the thread it has been matched with. A match
// object does not know how many threads will invoke it, though it can depend on the number being
// even. Once a program is sure that no more threads will invoke the match operation on a particular
// object, the destroy operation can and should be invoked.
//
// A small example program using a pair matcher is displayed at the end of the file.
//
// Your task is to implement pair matchers with the following interface:
//
//   • int pmatch_init(pmatch_t *pmp) — initializes a pair matcher.
//   • int pmatch_match(pmatch_t *pmp) — "Reasonably promptly" returns the thread i.d. of
//     another thread invoking pmatch_match() on the same pair-matcher object. Note that
//     pmatch_match(), as specified for this exam, does not return error codes.
//   • void pmatch_destroy(pmatch_t *pmp) — Deactivates a pair-matcher object. It is illegal
//     for a program to invoke pmatch_destroy() if any threads are operating on it.
//
// Assumptions:
//
//   1. You may use regular Project 2 thread-library primitives: mutexes, condition variables,
//      semaphores, readers/writer locks, etc.
//   2. You may assume that callers of your routines will obey the rules. But you must be
//      careful that you obey the rules as well!
//   3. You may not use other atomic or thread-synchronization synchronization operations, such
//      as, but not limited to: deschedule()/make_runnable(), or any atomic instructions (XCHG,
//      LL/SC).
//   4. You must comply with the published interfaces of synchronization primitives, i.e., you
//      cannot inspect or modify the internals of any thread-library data objects.
//   5. You may not use assembly code, inline or otherwise.
//   6. For the purposes of the exam, you may assume that library routines and system
//      calls don't "fail" (unless you indicate in your comments that you have arranged, and
//      are expecting, a particular failure).
//   7. You may not rely on any data-structure libraries such as splay trees, red-black trees,
//      queues, stacks, or skip lists, lock-free or otherwise, that you do not implement as part of
//      your solution.
//   8. You may use non-synchronization-related thread-library routines in the "thr_xxx() family,"
//      e.g., thr_getid(). You may wish to refer to the "cheat sheets" at the end of the
//      exam. If you wish, you may assume that thr_getid() is "very efficient" (for example, it
//      invokes no system calls). You may also assume that condition variables are strictly FIFO
//      if you wish.
//
// It is strongly recommended that you rough out an implementation on the scrap paper provided at
// the end of the exam, or on the back of some other page, before you write anything on the next page.
// If we cannot understand the solution you provide, your grade will suffer!
//
// (a) 3 points Please declare your pmatch_t here. If you need one (or more) auxilary struc-
//     tures, you may declare it/them here as well.
//
// (b) 12 points Now please implement int pmatch_init(), int pmatch_match(), and
//     void pmatch_destroy().
//

//
// Build: gcc -O2 -pthread CMU_s17_pmatcher_solution.c

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

// Stand-in for the Pebbles thr_getid(): a small integer id per thread.
static __thread int my_tid;
int thr_getid(void) { return my_tid; }


// (a) Declare your pmatch_t here.
//
// Per-pair record: the first thread of a pair puts one of these on its own
// stack and publishes its address. The second thread swaps ids through it.
// Because each pair has private state, a later pair can never overwrite it.
typedef struct pmatch_rec {
    int            partner;   // waiter's own id, then replaced by its partner's
    int            done;      // set to 1 once the partner has filled it in
    pthread_cond_t cv;        // only this record's owner waits on it
} pmatch_rec_t;

typedef struct {
    pthread_mutex_t mtx;
    pmatch_rec_t   *waiting;  // the one unpaired thread's record, or NULL
} pmatch_t;

// (b) Implement these.
int pmatch_init(pmatch_t *pmp)
{
    pthread_mutex_init(&pmp->mtx, NULL);
    pmp->waiting = NULL;
    return 0;
}

int pmatch_match(pmatch_t *pmp)
{
    int me = thr_getid();

    pthread_mutex_lock(&pmp->mtx);

    if (pmp->waiting != NULL) {
        // 2nd thread of a pair: take the waiter's record off the table so the
        // next arrival starts a fresh pair, swap ids through it, wake its owner.
        pmatch_rec_t *rec = pmp->waiting;
        pmp->waiting = NULL;

        int partner = rec->partner;
        rec->partner = me;
        rec->done = 1;
        pthread_cond_signal(&rec->cv);

        // Never touch rec after unlocking: its owner may return and free it.
        pthread_mutex_unlock(&pmp->mtx);
        return partner;
    }

    // 1st thread of a pair: publish a record on my own stack and wait.
    // The stack frame stays alive because I cannot return until done == 1.
    pmatch_rec_t rec;
    rec.partner = me;
    rec.done = 0;
    pthread_cond_init(&rec.cv, NULL);
    pmp->waiting = &rec;

    while (!rec.done) {
        pthread_cond_wait(&rec.cv, &pmp->mtx);
    }

    int partner = rec.partner;
    pthread_mutex_unlock(&pmp->mtx);
    pthread_cond_destroy(&rec.cv);
    return partner;
}

// Illegal to call while any thread is still inside pmatch_match(). Since the
// number of match calls is even, waiting is NULL by then.
void pmatch_destroy(pmatch_t *pmp)
{
    pthread_mutex_destroy(&pmp->mtx);
}


// ---------------------------------------------------------------------------
// Example program from the exam (thr_* calls mapped onto pthreads).
// ---------------------------------------------------------------------------

#define NTHREADS 410
pthread_t tids[NTHREADS];
pmatch_t matcher;

void *threadbody(void *arg)
{
    my_tid = (int)(long)arg;

    int me = thr_getid();
    int partner;
    int done = 0, rounds = 0;

    while (!done) {
        int coolpartner;

        partner = pmatch_match(&matcher);

        printf("I am %d, my partner is %d\n", me, partner);

        coolpartner = (me & 1) == (partner & 1);

        if (coolpartner) {
            printf("Whee! That was so much fun I might do it again.\n");
        }
        if ((++rounds == 10) || !coolpartner) {
            done = 1;
        }
    }
    return 0;
}

int main(void)
{
    pmatch_init(&matcher);

    for (long t = 0; t < NTHREADS; t++) {
        pthread_create(&tids[t], NULL, threadbody, (void *)t);
    }
    for (int t = 0; t < NTHREADS; t++) {
        pthread_join(tids[t], NULL);
    }
    printf("Done\n");
    pmatch_destroy(&matcher);
    return 0;
}
