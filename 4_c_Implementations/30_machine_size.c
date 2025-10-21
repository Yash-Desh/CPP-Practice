// Author: Yash Deshpande
// Date  : 16-10-2025
// Tutor : ChatGPT

// Q How to determine if your machine is 64-bit / 32-bit ?
/*
A pointer’s size equals the address width.
4 bytes → 32-bit
8 bytes → 64-bit
*/

#include <stdio.h>

int main() {
    if (sizeof(void*) == 8)
        printf("64-bit machine\n");
    else if (sizeof(void*) == 4)
        printf("32-bit machine\n");
    else
        printf("Unknown architecture\n");
    return 0;
}
