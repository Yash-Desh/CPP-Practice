// Author : Yash Deshpande
// Date : 10-02-2023
// Tutor : Love Babbar

#include <bits/stdc++.h> 
using namespace std;

// Implementation of dequeue is similar to circular queue, just 
// with extra functionality

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int [size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it 
    // gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.

        // case-1 : if dq is full
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)))
        {
            return false;
        }

        // case-2 : if dq is empty
        else if(front == -1)
        {
            front = rear = 0;
        }

        // case-3 : if front is at the 0th index
        else if(front == 0 && rear != size-1)
        {
            front = size-1;
        }

        // case-4 : default case
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it 
    // gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.

        // case - 1 : if the queue is full
        if(isFull())
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

        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if 
    // the deque is empty, otherwise returns the popped element.
    int popFront()
    {
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

    // Pops an element from the back of the deque. Returns -1 if 
    // the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
         // Write your code here.

        // case-1 : if queue is empty
        if(front == -1)
        {
            // cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;
        // case-2 : if queue contains only a single element
        if(front == rear)
        {
            front = rear = -1;
        }


        // case-3 : if front is at the last position of the array
        else if(rear == 0)
        {
            rear = size-1;
        }


        // case-4 : general / default case
        else
        {
            rear--;
        }
        return ans;

    }

    // Returns the first element of the deque. If the deque is empty, 
    // it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty())
            return -1;

        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it 
    // returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty())
            return -1;

        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1)
            return true;

        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)))
        {
            // cout<<"Queue is full"<<endl;
            return true;
        }
        else 
            return false;
    }
};

int main()
{
    cout<<"hello world"<<endl;
    return 0;
}
