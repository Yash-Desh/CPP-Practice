// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : inpyjama YouTube, https://stackoverflow.com/questions/38088732/explanation-to-aligned-malloc-implementation

#include <stdlib.h>
#include <stdio.h>

// Note: This method is able to align only powers of 2
// C11 introduced a portable method to do this -> void* aligned_alloc(size_t alignment, size_t size);

void* aligned_malloc(size_t required_bytes, size_t alignment)
{
    void* p1; // original block
    void** p2; // aligned block
    int offset = alignment - 1 + sizeof(void*);
    if ((p1 = (void*)malloc(required_bytes + offset)) == NULL)
    {
       return NULL;
    }

    // We move offset bytes forward from the start.
    // Now, even if p1 was misaligned, this guarantees that somewhere in 
    // [p1, p1+offset) there exists an aligned address.
    // This bitwise AND rounds down to the nearest multiple of alignment.
    // why convert the pointer to size_t ?
    // You can't directly do bit manipulation on pointers, hence we convert 
    // it to size_t, now you can do arithmetic on the address stored in p1
    p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *p)
{
    free(((void**)p)[-1]);
}

void main (int argc, char *argv[])
{
    char **endptr;
    int *p = aligned_malloc (100, strtol(argv[1], endptr, 10));

    printf ("%s: %p\n", argv[1], p);
    aligned_free (p);
}



// /*
// Q Memory Aligned Malloc -> provided you have the malloc api
// You need to write 2 functions malloc() & free()

// What is memory alignment ?
// -> library malloc can return a starting address without alignment
// -> if alignment = 5, then the starting address of your malloc should
// be a multiple of 5
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// // This has to be some hashing mechanism
// // here I am taking a variable for simplicity
// // Basically given an address, my hash_map should
// // correctly provide the start of the real malloc
// // we provide the user with the aligned address but
// // store the real malloc address in the hash.
// uint64_t hash = 0;

// void * my_malloc(int size, int alignment) {

//     // allocate extra memory, could start at any address
//     void *ptr = malloc(size+alignment);

//     // typecast to uint64
//     uint64_t address = (uint64_t)ptr;

//     // hash the original address
//     hash = address;

//     // clear out the bits required for alignment
//     address = address & (~(alignment-1));

//     // add alignment to the cleared address
//     address += alignment;

//     return (void *)address;
    
// }

// void my_free(void *ptr) {
//     // hash is stored as a key-value pair
//     // for the given pointer i.e. key, determine the value
//     // if the value is not correct then return -1

//     // else {
//     free((void *)hash);
//     // return 0;
//     // }

// }


// int main() {
    
//     return 0;
// }