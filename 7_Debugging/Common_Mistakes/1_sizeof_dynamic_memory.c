// Author: Yash Deshpande
// Date  : 17-11-2025
// Tutor : Jack Sorber (https://youtu.be/P0k1C3F61xY?si=lPZm2t8M2xTbObcn)

#include <stdio.h>
#include <stdlib.h>

int main() {
    // int* p = malloc(200);
    // int sizep = sizeof(p);
    // printf("sizeof(p) = %d\n", sizep);      // 8

    // // Commmon Error
    // int* p2 = malloc(100);
    // memcpy(p, p2, sizeof(p2));              // --> only going to copy 8 bytes


    // -------------------------------------------------------
    // Solution is to remember/store the size of the block

    // // Solution-1: Store size in a variable
    // int* p = malloc(200);
    // int* p2 = malloc(100);
    // int sizep = 100;
    // memcpy(p, p2, sizep);


    // Solution-2: Record the size in the block itself
    int* p = malloc(200);
    int* p2 = malloc(100);
    int sizep = 100;
    memcpy(p, &sizep, sizeof(int));

    
    return 0;
}