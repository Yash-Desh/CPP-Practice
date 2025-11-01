// Author: Yash Deshpande
// Date  : 31-10-2025
// Tutor : 

// Circular Buffer == Circular Queue == Ring Buffer

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct CircularBuffer {
    int* arr;
    int front;
    int rear;
    int size;
    int count;
};

void createCircularBuffer(struct CircularBuffer* buf, int size) {
    buf->size = size;
    buf->front = 0;
    buf->rear = 0;
    buf->count = 0;
    buf->arr = (int*)malloc(sizeof(int)*size);
}

bool isEmpty(struct CircularBuffer* buf) {
    if(buf->count == 0) {
        return true;
    }
    else {
        return false;
    }
}

void enqueue(struct CircularBuffer* buf, int val) {
    // Check if full.
    if(buf->count == buf->size) {
        printf("Circular Buffer is Full\n");
        return;
    }

    buf->arr[buf->rear] = val;
    buf->count++;
    buf->rear = (buf->rear+1) % buf->size;
}

void dequeue(struct CircularBuffer* buf) {
    // Check if empty.
    if(isEmpty(buf)) {
        printf("Circular Buffer is Empty\n");
        return;
    }

    buf->front = (buf->front+1) % buf->size;
    buf->count--;
}

int front(struct CircularBuffer* buf) {
    // Check if empty.
    if(isEmpty(buf)) {
        printf("Circular Buffer is Empty\n");
        return INT_MIN;
    }
    return buf->arr[buf->front];
}

void printBuffer(struct CircularBuffer* buf) {
    // Check if empty.
    if(isEmpty(buf)) {
        printf("Circular Buffer is Empty\n");
        return;
    }
    for(int i=0; i < buf->count; i++) {
        int num = buf->arr[(buf->front+i)%buf->size];
        printf("%d ", num);
    }
    printf("\n");
}

int main() {
    struct CircularBuffer ringBuf;
    createCircularBuffer(&ringBuf, 5);

    enqueue(&ringBuf, 10);
    enqueue(&ringBuf, 20);
    enqueue(&ringBuf, 30);
    enqueue(&ringBuf, 40);
    enqueue(&ringBuf, 50);
    printBuffer(&ringBuf);      // Queue full

    dequeue(&ringBuf);
    enqueue(&ringBuf, 60);
    printBuffer(&ringBuf);

    printf("Front Element of Circular Buffer is %d\n", front(&ringBuf));
    return 0;
}