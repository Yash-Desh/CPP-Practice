// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/Fq9chEBQMFE?si=MW4ZIrzXbmXfN2Hb)

// Part-2
// This program mallocs a 1GB, of memory in an infinite loop.

// QUIZ: When will malloc fail ? i.e. stop giving you memory
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

int main() {
    int count = 0;

    while(1) {
        int *p = malloc(ONEGB);
        if(p == NULL) {
            printf("malloc refused after %d GB\n", count);
            return 0;
        }
        memset(p, 1, ONEGB);
        printf("Got %d GB\n", ++count);
    }
    return 0;
}