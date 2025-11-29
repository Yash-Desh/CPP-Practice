// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/tEbV21aPSKw?si=bWeLXZRKXdLItddI)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Here we use AddressSanitizer to detect a buffer overflow.

// Compilation Command: gcc -fsanitize=address ./6_tool_address_sanitizer.c

#define NUMLETTERS 26

int main() {
    
    // Static Allocation. 
    char somechars[NUMLETTERS];
    for(int i=0; i<NUMLETTERS; i++) {
        somechars[i] = 'a' + i;
    }

    // Compilers like clang will warn you about the buffer overflow.
    printf("An element: %c\n", somechars[50]);

    // Even clang will not detect this.
    int idx = 50;
    printf("An element: %c\n", somechars[idx]);

    return 0;
}