// Author : Yash Deshpande
// Date : 06-02-2025
// Tutor : GeeksforGeeks

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int new_data)
    {
        this->data = new_data;
        this->next = NULL;
    }
};

class Queue
{
    private:
    Node *front, *rear;

    public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        if(front == NULL) {
            return true;
        }
        else
        {
            return false;
        }
    }


    void enqueue(int data)
    {
        Node *temp = new Node(data);

        if(front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }
        else 
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout<<"Queue underflow"<<endl;
            return;
        }

        else
        {
            Node *temp = front;
            front = front->next;
            if(front == NULL)
            {
                rear = NULL;
            }
            temp->next = NULL;
            delete temp;

            
        }
    }

    int get_front() {
        if(front == NULL) {
            return -1;
        }
        else
        {
            return front->data;
        }
    }

};

int main()
{
    Queue q;

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);

    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.get_front() << endl;
    // cout << "Queue Rear: " << q.getRear() << endl;

    // Dequeue elements from the queue
    q.dequeue();
    q.dequeue();

    // Enqueue more elements into the queue
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Dequeue an element from the queue
    q.dequeue();

    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.get_front() << endl;
    // cout << "Queue Rear: " << q.getRear() << endl << endl;

    return 0;
}