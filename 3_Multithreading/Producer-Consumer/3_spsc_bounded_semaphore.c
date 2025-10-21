// spsc_semaphore.c
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITEMS 100000
#define CAP    1024

typedef int item_t;
static item_t buf[CAP];
static size_t head = 0, tail = 0;

static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; // protects head/tail
static sem_t empty_slots;  // counts free slots
static sem_t filled_slots; // counts items available

void *producer(void *arg) {
    for (int i = 0; i < NITEMS; i++) {
        sem_wait(&empty_slots);
        pthread_mutex_lock(&m);

        buf[head] = i;
        head = (head + 1) % CAP;

        pthread_mutex_unlock(&m);
        sem_post(&filled_slots);
    }
    return NULL;
}

void *consumer(void *arg) {
    long long sum = 0;
    for (int i = 0; i < NITEMS; i++) {
        sem_wait(&filled_slots);
        pthread_mutex_lock(&m);

        int v = buf[tail];
        tail = (tail + 1) % CAP;

        pthread_mutex_unlock(&m);
        sem_post(&empty_slots);

        sum += v;
    }
    printf("sum=%lld\n", sum);
    return NULL;
}

int main(void) {
    pthread_t tp, tc;
    sem_init(&empty_slots, 0, CAP);
    sem_init(&filled_slots, 0, 0);

    pthread_create(&tp, NULL, producer, NULL);
    pthread_create(&tc, NULL, consumer, NULL);
    pthread_join(tp, NULL);
    pthread_join(tc, NULL);

    sem_destroy(&empty_slots);
    sem_destroy(&filled_slots);
    return 0;
}
