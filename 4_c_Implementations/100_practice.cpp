// Author: Yash Deshpande
// Date  : 02-11-2025
// Tutor : 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void* aligned_malloc(size_t size, size_t alignment) {
    void* ptr1;
    void** ptr2;

    // Step-1: Calculate the offset.
    int offset = alignment + sizeof(void *) - 1;

    // Step-2: Allocate Memory
    ptr1 = malloc(sizeof(char) * (offset+size));

    // Step-3: Access the aligned location
    ptr2 = (void**) (((size_t)ptr1 + offset) & ~(alignment-1));
    ptr2[-1] = ptr1;
    return ptr2;
}

void aligned_free(void* ptr) {
    free(((void**)ptr)[-1]);
}

int main(int argc, char* argv[]) {
    char **endptr;
    int *p = (int *)aligned_malloc (100, strtol(argv[1], endptr, 10));

    printf ("%s: %p\n", argv[1], p);
    aligned_free (p);
    return 0;
}