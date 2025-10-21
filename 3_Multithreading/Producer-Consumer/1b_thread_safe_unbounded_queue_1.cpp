// Author : Yash Deshpande
// Date   : 10-10-2025
// Tutor  : Gemini, GFG (https://www.geeksforgeeks.org/dsa/implement-thread-safe-queue-in-c/)

// -------------------------------
// Thread-safe Queue Implementation
//  1. Lock-based (mutex + condition variables).    --> This file 
//  2. Lock-free (using atomics).
// -------------------------------

// Unbounded - Blocking - MPMC

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

// Thread-safe queue
template <typename T>
class TSQueue {
private:
    // Underlying queue
    std::queue<T> m_queue;

    // mutex for thread synchronization
    std::mutex m_mutex;

    // Condition variable for signaling
    std::condition_variable m_cond;

public:
    // Pushes an element to the queue
    void push(T item) {
        // Acquire lock
        std::unique_lock<std::mutex> lock(m_mutex);

        // Add item
        m_queue.push(item);

        // Notify one thread that is waiting
        m_cond.notify_one();
    }

    // Blocking pop: waits until an element is available
    T pop() {
        // acquire lock
        std::unique_lock<std::mutex> lock(m_mutex);

        // wait until queue is not empty
        m_cond.wait(lock, [this]() { return !m_queue.empty(); });

        // retrieve item
        T item = m_queue.front();
        m_queue.pop();

        // return item
        return item;
    }

    // Non-blocking try_pop: returns true if an element was popped, false otherwise
    bool try_pop(T& value) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_queue.empty()) {
            return false;
        }
        value = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.size();
    }
};

int main() {
    // TSQueue<int> q;

    // // Push some data
    // q.push(1);
    // q.push(2);
    // q.push(3);

    // // Pop some data
    // std::cout << q.pop() << std::endl;
    // std::cout << q.pop() << std::endl;
    // std::cout << q.pop() << std::endl;

    TSQueue<int> q;

    // Producer: send 0..9, then a sentinel -1 to say "done"
    std::thread producer([&]{
        for (int i = 0; i < 10; ++i) q.push(i);
        q.push(-1); // stop signal
    });

    // Consumer: read until sentinel
    std::thread consumer([&]{
        for (;;) {
            int x = q.pop();
            if (x == -1) break;     // done
            std::cout << "got " << x << "\n";
        }
    });

    producer.join();
    consumer.join();
    return 0;
}