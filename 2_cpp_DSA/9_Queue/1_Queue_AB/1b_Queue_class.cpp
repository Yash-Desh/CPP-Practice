// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

class Queue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;

    public:
        // Default Constructor
        Queue()
        {
            front = rear = -1;
            size = 10;    // default size
            Q = new int [size];
        }

        // Parameterized Constructor
        Queue (int size)
        {
            front = rear = -1;
            this->size = size; 
            Q = new int [this->size];
        }

        void enqueue (int x);
        int dequeue ();
        void display();
};


// function to insert into a queue
void Queue :: enqueue(int x)
{
    // check if queue is full
    if (rear == size - 1)
        cout << "Queue is Full" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

// function to delete in a queue
int Queue :: dequeue()
{
    int x = -1;
    // check if the queue is empty
    if (rear == front)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

// function to display queue elements
void Queue :: display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(40);

    q.display();
    return 0;
}