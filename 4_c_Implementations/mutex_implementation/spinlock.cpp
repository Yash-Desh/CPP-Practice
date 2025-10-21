// Date : 19-10-2025
// Tutor : ChatGPT

#include <atomic>
#include <thread>   // for std::this_thread::yield

class SpinLock {
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;  // false = unlocked, true = locked

public:
    // Constructor (optional)
    SpinLock() noexcept {
        flag.clear(std::memory_order_release);
    }

    // Delete copy/assign to avoid accidental copies
    SpinLock(const SpinLock&) = delete;
    SpinLock& operator=(const SpinLock&) = delete;

    // Lock: spin until we successfully acquire
    void lock() noexcept {
        while (flag.test_and_set(std::memory_order_acquire)) {
            // Busy-wait: yield CPU to let others run
            std::this_thread::yield();
        }
    }

    // Try lock once — returns true if acquired, false otherwise
    bool try_lock() noexcept {
        return !flag.test_and_set(std::memory_order_acquire);
    }

    // Unlock: clear flag
    void unlock() noexcept {
        flag.clear(std::memory_order_release);
    }
};
