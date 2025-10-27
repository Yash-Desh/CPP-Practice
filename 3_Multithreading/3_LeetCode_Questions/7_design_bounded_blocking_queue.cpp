#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
using namespace std;


class BoundedBlockingQueue {
private:
    queue<int> q;
    int capacity;
    mutex mtx;
    condition_variable not_full, not_empty;

public:
    BoundedBlockingQueue(int cap) : capacity(cap) {}

    void enqueue(int element) {
        unique_lock<mutex> lock(mtx);
        not_full.wait(lock, [&] { return q.size() < capacity; });
        q.push(element);
        not_empty.notify_one(); // signal one waiting consumer
    }

    int dequeue() {
        unique_lock<mutex> lock(mtx);
        not_empty.wait(lock, [&] { return !q.empty(); });
        int val = q.front(); 
        q.pop();
        not_full.notify_one(); // signal one waiting producer
        return val;
    }

    int size() {
        unique_lock<mutex> lock(mtx);
        return q.size();
    }
};
