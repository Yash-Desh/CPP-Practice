// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : inpyjama YouTube

/*
Q Memory Aligned Malloc -> provided you have the malloc api
You need to write 2 functions malloc() & free()

What is memory alignment ?
-> library malloc can return a starting address without alignment
-> if alignment = 5, then the starting address of your malloc should
be a multiple of 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// This has to be some hashing mechanism
// here I am taking a variable for simplicity
// Basically given an address, my hash_map should
// correctly provide the start of the real malloc
// we provide the user with the aligned address but
// store the real malloc address in the hash.
uint64_t hash = 0;

void * my_malloc(int size, int alignment) {

    // allocate extra memory, could start at any address
    void *ptr = malloc(size+alignment);

    // typecast to uint64
    uint64_t address = (uint64_t)ptr;

    // hash the original address
    hash = address;

    // clear out the bits required for alignment
    address = address & (~(alignment-1));

    // add alignment to the cleared address
    address += alignment;

    return (void *)address;
    
}

void my_free(void *ptr) {
    // hash is stored as a key-value pair
    // for the given pointer i.e. key, determine the value
    // if the value is not correct then return -1

    // else {
    free((void *)hash);
    // return 0;
    // }

}


int main() {
    
    return 0;
}