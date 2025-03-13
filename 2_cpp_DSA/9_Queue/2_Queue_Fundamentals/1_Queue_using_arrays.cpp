// Author : Yash Deshpande
// Date : 10-02-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


class Queue {
    
    int* arr;
    int qfront;
    int rear; 
    int size;

    // Since the constructor provided is a default constructor
    // The size of the array will be decided arbitrarily by 
    // the coder
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {	
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            // // Shift all the elements
            // // to the left.
            // for (int i = 1; i < rear; i++) {
            //     arr[i - 1] = arr[i];
            // }

            // if the queue becomes empty after deletion
            // then reset the values of front & rear pointers
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    
    return 0;
}