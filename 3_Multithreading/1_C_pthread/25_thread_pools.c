// Author: Yash Deshpande
// Date  : 26-10-2025
// Tutor : CodeVault (https://youtu.be/_n2hE2gyPxU?si=TdPnSsAn6_2T8YZo)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define THREAD_NUM 4

typedef struct Task {
    int a, b;
} Task;

Task taskQueue[256];
int taskCount = 0;

pthread_mutex_t mutexQueue;
pthread_cond_t condQueue;

void executeTask(Task* task) {
    int result = task->a + task->b;
    printf("Sum of %d & %d = %d\n", task->a, task->b, result);
}

void submitTask(Task task) {
    pthread_mutex_lock(&mutexQueue);
    taskQueue[taskCount] = task;
    taskCount++;
    pthread_mutex_unlock(&mutexQueue);
    pthread_cond_signal(&condQueue);
}


void* startThread(void* args) {
    while(1) {
        Task task;
        
        pthread_mutex_lock(&mutexQueue);
        // Check if there are any pending tasks
        while(taskCount <= 0) {
            pthread_cond_wait(&condQueue, &mutexQueue);
        }
        task = taskQueue[0];

        // Shift the remaining elements
        for(int i=0; i<taskCount-1; i++) {
            taskQueue[i] = taskQueue[i+1];
        }
        taskCount--;
        pthread_mutex_unlock(&mutexQueue);

        // Execution of task should happen outside of the critical section
        executeTask(&task);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    pthread_t th[THREAD_NUM];

    pthread_mutex_init(&mutexQueue, NULL);
    pthread_cond_init(&condQueue, NULL);

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_create(&th[i], NULL, startThread, NULL) != 0) {
            perror("Failed to create thread\n");
        }
    }

    // Main Thread submits tasks
    for(int i=0; i<100; i++) {
        Task t = {
            .a = rand() % 100, 
            .b = rand() % 100
        };
        submitTask(t);
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread\n");
        }
    }

    pthread_mutex_destroy(&mutexQueue);

    return 0;
}