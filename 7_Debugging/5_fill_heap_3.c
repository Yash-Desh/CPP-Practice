// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/Fq9chEBQMFE?si=MW4ZIrzXbmXfN2Hb)

// Part-3
// This program mallocs a large amount of memory (greater than 
// machine's physical limit) without accessing it.
// And then starts accessing it.

// QUIZ: When will program fail ? i.e. stop giving you memory
// 1. Machine has a physical limit of 32GB
// 2. OS may have some in-built limit which is less than 32 GB
// 3. We use virtual memory & we can perform swapping to the disk 
//    so maybe it could let it go beyond 32GB
// 4. Something Else. 

// Answer: Physicall Limit of the Machine's Memory / RAM
// This program allocates & then accesses the memory. The OS can't lie here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONEGB (1<<30)
#define N 10000L

int main() {
    int count = 0;
    int* blocks[N];

    for(int i=0; i<N; i++) {
        blocks[i] = malloc(ONEGB);
        if(blocks[i] == NULL) {
            printf("done at %d \n", i);
            return 0;
        }
    }

    printf("Allocated %i blocks\n", N);

    for(int i=0; i<N; i++) {
        memset(blocks[i], 2, ONEGB);
        printf("Wrote to %i Gigs\n", i);
    }

    return 0;
}