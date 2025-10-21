// spsc_mutex_cond.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NITEMS 100000
#define CAP    1024

typedef int item_t;
static item_t buf[CAP];
static size_t head = 0, tail = 0, count = 0;

static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  not_full  = PTHREAD_COND_INITIALIZER;
static pthread_cond_t  not_empty = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    for (int i = 0; i < NITEMS; i++) {
        pthread_mutex_lock(&m);
        while (count == CAP) pthread_cond_wait(&not_full, &m);

        buf[head] = i;
        head = (head + 1) % CAP;
        count++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&m);
    }
    return NULL;
}

void *consumer(void *arg) {
    long long sum = 0;
    for (int i = 0; i < NITEMS; i++) {
        pthread_mutex_lock(&m);
        while (count == 0) pthread_cond_wait(&not_empty, &m);

        int v = buf[tail];
        tail = (tail + 1) % CAP;
        count--;

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&m);

        sum += v;
    }
    printf("sum=%lld\n", sum);
    return NULL;
}

int main(void) {
    pthread_t tp, tc;
    pthread_create(&tp, NULL, producer, NULL);
    pthread_create(&tc, NULL, consumer, NULL);
    
    
    pthread_join(tp, NULL);
    pthread_join(tc, NULL);
    return 0;
}
