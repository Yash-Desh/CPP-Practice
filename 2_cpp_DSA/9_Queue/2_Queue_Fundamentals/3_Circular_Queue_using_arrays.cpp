// Author : Yash Deshpande
// Date : 10-02-2023
// Tutor : Love Babbar


// ########### Follow Queue code by Abdul Bari for better logic ###########


#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;
    public:
    
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int [size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed 
    // into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.

        // case - 1 : if the queue is full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
        // if((front == 0 && rear == size-1) || (rear == (front-1)))  --> also works
        {
            // cout<<"Queue is full"<<endl;
            return false;
        }

        // case - 2 : if queue is empty
        else if(front == -1)
        {
            front = rear = 0;       
        }

        // case - 3 : if there is empty space in the array
        // before the head
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
        }

        // case-4 : 
        else
        {
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack
    // is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.

        // case-1 : if queue is empty
        if(front == -1)
        {
            // cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        // case-2 : if queue contains only a single element
        if(front == rear)
        {
            front = rear = -1;
        }


        // case-3 : if front is at the last position of the array
        else if(front == size-1)
        {
            front = 0;
        }


        // case-4 : general / default case
        else
        {
            front++;
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}