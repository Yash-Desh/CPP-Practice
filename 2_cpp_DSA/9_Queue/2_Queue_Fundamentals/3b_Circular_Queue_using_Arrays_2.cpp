// Author : Yash Deshpande
// Date   : 17-10-2025
// Tutor  : ChatGPT


#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size, count; // count helps track # of elements
public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }

    // Enqueue operation
    bool enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return false;
        }

        arr[rear] = value;
        rear = (rear + 1) % size;
        count++;
        return true;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int result = arr[front];
        front = (front + 1) % size;
        count--;
        return result;
    }

    // Peek front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Display queue contents
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();      // Queue full

    cout << "Dequeued: " << q.dequeue() << endl;
    q.enqueue(60);
    q.display();

    cout << "Front element: " << q.peek() << endl;
}
