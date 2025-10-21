// Date : 19-10-2025
// Tutor : ChatGPT

// spin_mutex.h
#include <stdatomic.h>
#include <sched.h>   // sched_yield()

typedef struct {
    atomic_flag f;   // false = unlocked, true = locked
} spin_mutex_t;

static inline void spin_mutex_init(spin_mutex_t *m) {
    atomic_flag_clear(&m->f);
}

static inline int spin_mutex_try_lock(spin_mutex_t *m) {
    // Test-and-set returns the previous value. Acquire barrier on success.
    return !atomic_flag_test_and_set_explicit(&m->f, memory_order_acquire);
}

static inline void spin_mutex_lock(spin_mutex_t *m) {
    // Busy-wait with polite backoff to reduce cache-coherence traffic.
    for (int spins = 0;; ++spins) {
        if (spin_mutex_try_lock(m)) return;
        // Pause/backoff: yield occasionally to reduce contention.
        if ((spins & 0xFF) == 0) sched_yield();
        // Optional: __builtin_ia32_pause(); on x86, or asm("yield") on ARM.
    }
}

static inline void spin_mutex_unlock(spin_mutex_t *m) {
    // Release barrier before making lock visible as free.
    atomic_flag_clear_explicit(&m->f, memory_order_release);
}
