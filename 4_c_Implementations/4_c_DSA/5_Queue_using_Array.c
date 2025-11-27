// Author: Yash Deshpande
// Date  : 31-10-2025
// Tutor : Love Babbar(in C)

// 2 types of Linear Queue
// 1. wastes space but all operations O(1)
// 2. space optimal but dequeue O(N)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue {
    int* arr;
    int size;
    int front;
    int rear;
};

void createQueue(struct Queue* q, int size) {
    q->size = size;
    q->arr = (int*)malloc(sizeof(int)*size);
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(struct Queue* q) {
    if(q->front == q->rear) {
        return true;
    }
    else {
        return false;
    }
}

void enqueue(struct Queue* q, int val) {
    // Check if full.
    if(q->rear == q->size) {
        printf("Queue is Full\n");
    }
    else {
        q->arr[q->rear] = val;
        q->rear++;
    }
}

void dequeue(struct Queue* q) {
    // Check if empty
    if(q->front == q->rear) {
        printf("Queue is Empty\n");
    }
    else {
        q->front++;

        // // Optimization-1: Rearrange the elements
        // for(int i=0; i<q->rear; i++) {
        //     q->arr[i] = q->arr[i+1]; 
        // }
        // q->rear--;

        // // Optimization-2: Reset front & rear
        // if(q->front == q->rear) {
        //     q->front = q->rear = 0;
        // }
    }
}

int front(struct Queue* q) {
    // Check if empty
    if(q->front == q->rear) {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    else {
        return q->arr[q->front];
    }
}

void printQueue(struct Queue* q) {
    for(int i=q->front; i< q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {

    struct Queue q;
    createQueue(&q, 100);

    // Enqueue elements
    enqueue(&q, 10);
    printQueue(&q);

    enqueue(&q, 20);
    printQueue(&q);

    enqueue(&q, 30);
    printQueue(&q);

    // Peek front element
    printf("Front element: %d\n", front(&q));

    // Dequeue an element
    dequeue(&q);
    printQueue(&q);

    // Peek front element after dequeue
    printf("Front element after dequeue: %d\n", front(&q));
    return 0;
}
