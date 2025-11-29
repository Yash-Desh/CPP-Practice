// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/Fq9chEBQMFE?si=MW4ZIrzXbmXfN2Hb)

// Part-1
// This program mallocs a 1GB, of memory in an infinite loop.

// QUIZ: When will malloc fail ? i.e. stop giving you memory
// 1. Machine has a physical limit of 32GB
// 2. OS may have some in-built limit which is less than 32 GB
// 3. We use virtual memory & we can perform swapping to the disk 
//    so maybe it could let it go beyond 32GB
// 4. Something Else. 

// Answer: Lazy Allocation -> This program just mallocs memory but doesn't 
// access it, so OS doesn't allocate any physicall memory which can give 
// crazy results like "malloc refused after 131060 GB". But none of this memory
// is physically available nor allocated. OS lied to you!

#include <stdio.h>
#include <stdlib.h>

#define ONEGB (1<<30)

int main() {
    int count = 0;

    while(1) {
        if(malloc(ONEGB) == NULL) {
            printf("malloc refused after %d GB\n", count);
            return 0;
        }
        printf("Got %d GB\n", ++count);
    }
    return 0;
}