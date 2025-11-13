#include <stddef.h>

// Call once at the start of main() to initialise the empty heap.
// This is the equivalent of what your C library is doing before main() for the
// system heap.
void simple_heap_init();

void *simple_malloc(size_t size);

void simple_free(void *ptr);