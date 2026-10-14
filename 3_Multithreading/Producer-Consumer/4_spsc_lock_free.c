// Author: Yash Deshpande
// Date  : 13-10-2026
// Tutor : Claude Opus 5.5

// ############################################################################
// THIS CODE IS AI-GENERATED & NEEDS TO BE VALIDATED. THIS COULD BE INCORRECT!
// ############################################################################



// Lock-free SPSC (single producer, single consumer) ring buffer.
//
// Simplest correct version:
//   - wrapped indices, one slot sacrificed to tell empty from full
//   - no power-of-two capacity, no monotonic counters, no overflow reasoning
//   - no cache-line padding (that is a performance tweak, not correctness)
//
// What is NOT optional: each index has exactly one writer, and the
// release/acquire pair is what makes the data visible to the other thread.
//
// Build: gcc -std=c11 -O2 -pthread 4_spsc_lock_free.c

#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

#define RB_CAPACITY 1024u          /* usable capacity is RB_CAPACITY - 1 */

typedef int rb_elem_t;

typedef struct {
    rb_elem_t     buf[RB_CAPACITY];
    atomic_size_t tail;            /* written only by the producer */
    atomic_size_t head;            /* written only by the consumer */
} ringbuf_t;

void rb_init(ringbuf_t *rb)
{
    atomic_init(&rb->head, 0);
    atomic_init(&rb->tail, 0);
}

/* producer thread only */
bool rb_push(ringbuf_t *rb, rb_elem_t v)
{
    size_t t    = atomic_load_explicit(&rb->tail, memory_order_relaxed);
    size_t next = (t + 1) % RB_CAPACITY;
    size_t h    = atomic_load_explicit(&rb->head, memory_order_acquire);

    if (next == h)
        return false;                                              /* full */

    rb->buf[t] = v;
    atomic_store_explicit(&rb->tail, next, memory_order_release);  /* publish */
    return true;
}

/* consumer thread only */
bool rb_pop(ringbuf_t *rb, rb_elem_t *out)
{
    size_t h = atomic_load_explicit(&rb->head, memory_order_relaxed);
    size_t t = atomic_load_explicit(&rb->tail, memory_order_acquire);

    if (h == t)
        return false;                                              /* empty */

    *out = rb->buf[h];
    atomic_store_explicit(&rb->head, (h + 1) % RB_CAPACITY,
                          memory_order_release);                   /* free slot */
    return true;
}
