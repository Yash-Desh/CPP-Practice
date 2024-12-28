// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// function to initialize a queue
void create(struct Queue *q, int s) // s = size of the queue-array
{
    q->size = s;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

// function to insert into a queue
void enqueue(struct Queue *q, int x)
{
    // check if queue is full
    if (q->rear == q->size - 1)
        cout << "Queue is Full" << endl;
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// function to delete in a queue
int dequeue(struct Queue *q)
{
    int x = -1;
    // check if the queue is empty
    if (q->rear == q->front)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// function to display queue elements
void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q);

    cout<<dequeue(&q)<<endl;

    return 0;
}