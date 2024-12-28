// Author : Yash Deshpande
// Date : 13-02-2023
// Tutor : Abdul Bari

#include <iostream>
using namespace std;


// struct for a LL node
// 2 global pointers pointing to null
struct Node 
{
    int data;
    Node* next;
} *front = NULL, *rear = NULL;
 


// Function to insert new element in a Queue
// insertion is done at the rear
void enqueue (int x)
{
    // create a new Node
    Node *t = new Node;

    // check if heap is full
    if(t == NULL)
    {
        cout<<"Queue is full"<<endl;
    }

    else
    {
        // initialize the newly created Node
        t->data = x;
        t->next = NULL;

        // if Queue is empty, inserting 1st node
        if(front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
} 


// function to delete an element from a queue & return it
// deletion is done at the front
int dequeue ()
{
    // variable to return deleted value , else -1
    int x = -1;

    // if Queue is empty
    if(front == NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        Node *t = front;
        x = t->data;
        front = front->next;

        // if queue contains only single element
        // above condition not handled wrt "rear" pointer

        delete t;
    }
    return x;
}


// function to display the contents of Queue
void display()
{
    if(front == NULL)
        cout<<"Queue is empty"<<endl;

    else
    {
        Node *t = front;
        while(t)
        {
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<endl;
    }
}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    cout<<dequeue()<<endl;

    display();

    return 0;
}