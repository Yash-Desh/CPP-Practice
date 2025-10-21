#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <semaphore>
using namespace std;

class BoundedBlockingQueue {
private:
    queue<int> q;
    int capacity;
    mutex mtx;
    semaphore empty_slots; // available spaces
    semaphore filled_slots; // available items

public:
    BoundedBlockingQueue(int cap)
        : capacity(cap), empty_slots(cap), filled_slots(0) {}

    void enqueue(int element) {
        empty_slots.acquire(); // wait if no space
        {
            lock_guard<mutex> lock(mtx);
            q.push(element);
        }
        filled_slots.release(); // signal an available item
    }

    int dequeue() {
        filled_slots.acquire(); // wait if empty
        int val;
        {
            lock_guard<mutex> lock(mtx);
            val = q.front(); q.pop();
        }
        empty_slots.release(); // signal a free slot
        return val;
    }

    int size() {
        lock_guard<mutex> lock(mtx);
        return q.size();
    }
};
