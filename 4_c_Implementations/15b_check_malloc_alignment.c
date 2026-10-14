// This program is check the memory allocation alignment given 
// by the default malloc

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main() {
    // Allocate a single integer on the heap. 
    int *num = (int*) malloc(sizeof(int));


    if((uintptr_t)num % 32 == 0) {
        printf("malloc is 32-bytes aligned on this machine\n");
    }
    else if((uintptr_t)num % 16 == 0) {
        printf("malloc is 16-bytes aligned on this machine\n");
    }
    else if((uintptr_t)num % 8 == 0) {
        printf("malloc is 8-bytes aligned on this machine\n");
    }
    else if((uintptr_t)num % 4 == 0) {
        printf("malloc is 4-bytes aligned on this machine\n");
    }

    free(num);

    return 0;
}