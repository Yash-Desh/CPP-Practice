// Author : Yash Deshpande
// Date : 16-02-2023
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new int[q->size];
}

// function to insert at rear
void enqueue(Queue *q, int x)
{
    // if queue is full
    // To understand this condition , refer Abdul Bari course / notes
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "Queue is full" << endl;
    }

    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// function to delete at front
int dequeue(struct Queue *q)
{
    int x = -1;
    // if queue is empty
    if (q->front == q->rear)
    {
        cout << "Queue is empty" << endl;
    }

    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

// function to display queue elements
// void display(Queue q)
// {
//     // if queue is empty
//     // this condition prevents printing of erraneous 
//     // elements when the queue is empty
//     if (q.front == q.rear)
//         cout << "Queue is empty" << endl;

//     else
//     {
//         int i = q.front + 1;
//         while (i != (q.rear + 1) % q.size)
//         {
//             cout << q.Q[i] << " ";
//             i = (i + 1) % q.size;
//         }
//         cout << endl;
//     }
// }

void display(Queue q)
{
    int i = q.front + 1;
    do
    {
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    
}

int main()
{
    Queue q;
    create(&q, 5);
    enqueue(&q, 14);
    enqueue(&q, 24);
    enqueue(&q, 34);
    enqueue(&q, 44);
    display(q);
    // enqueue(&q,54);
    // display(q);
    // enqueue(&q,64);

    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    // display(q);
    cout << dequeue(&q) << endl;
    // cout<<dequeue(&q)<<endl;
    display(q);
    // cout<<dequeue(&q)<<endl;
    return 0;
}