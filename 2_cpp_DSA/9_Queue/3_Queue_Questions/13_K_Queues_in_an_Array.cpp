// Author : Yash Deshpande
// Date : 12-04-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// ########################
// Approach - 1 : Brute Force
// Babbar Approach
// TC : O(N)
// SC : O(N)
// Divide the array of size n into k parts each of size n/k
// Each queue can only contain n/k elements
// Space is NOT used optimally.
// ########################

// ########################
// Approach - 2 :
// Optimal Approach
// TC :
// SC :
// ########################

class kQueue
{
private:
    int n;
    int k;
    int *front;
    int *rear;
    int *next;
    int *arr;
    int freeSpot;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;

        // Initialize front & rear
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }

    // qn represents the queue number into which you wish
    // to enter a new element
    void enqueue(int data, int qn)
    {
        // overflow : Array is fully occupied
        if (freeSpot == -1)
        {
            cout << "No empty space is present" << endl;
            return;
        }

        // find 1st free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // check whether it is the 1st element of that queue
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // link new element to the previous element
            next[rear[qn - 1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    // returns the popped element
    int dequeue(int qn)
    {
        // check if queue    empty
        // underflow condition
        if (front[qn-1] == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        // determine index to pop
        int index = front[qn-1];

        // update front
        front[qn-1] = next[index];

        // update next of new freeSpot
        next[index] = freeSpot;

        // update freeSpot
        freeSpot = index; 

        return arr[index];
    }
};

int main()
{
    kQueue q(10,3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    return 0;
}