// Author: Yash Deshpande
// Date  : 16-05-2026
// Tutor : OSTEP Concurrent Data Structures
// Link  : https://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks-usage.pdf


#include <bits/stdc++.h> 

class QueueNode {
public: 
    int data; 
    QueueNode* next;

    QueueNode(int val): data(val), next(nullptr) {}
};


class Queue {
    QueueNode* head;
    QueueNode* tail;
public:
    Queue() {
        // Implement the Constructor
        head = new QueueNode(-1);
        tail = head;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(head == tail) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        QueueNode* temp = new QueueNode(data);
        tail->next = temp;
        tail = temp;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) {
            return -1;
        }
        else {
            int dataToBeDeleted = head->next->data;
            QueueNode* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
            return dataToBeDeleted;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) {
            return -1;
        }
        return head->next->data;
    }
};