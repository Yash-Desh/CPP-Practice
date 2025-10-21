// Tutor : ChatGPT
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <vector>
#include <iostream>

class BoundedQueue {
    std::mutex m;
    std::condition_variable cv_not_full, cv_not_empty;
    std::queue<int> q;
    const size_t cap;

public:
    explicit BoundedQueue(size_t capacity) : cap(capacity) {}

    void push(int x) {
        std::unique_lock<std::mutex> lock(m);
        
        // Wait if the buffer is full.
        cv_not_full.wait(lock, [&]{ return q.size() < cap; });
        q.push(x);
        
        // lock.unlock();
        cv_not_empty.notify_one();
    }

    int pop() {
        std::unique_lock<std::mutex> lock(m);

        // Wait if the buffer is empty
        cv_not_empty.wait(lock, [&]{ return !q.empty(); });
        int x = q.front(); 
        q.pop();
        
        // lock.unlock();
        cv_not_full.notify_one();
        return x;
    }
};
