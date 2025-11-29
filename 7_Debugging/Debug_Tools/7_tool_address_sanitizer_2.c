// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/_Al7Y7BI-ds?si=35mSs0L2xvP1Ru8D)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// In this file we use AddressSanitizer to detect memory leak & use-after-free error.

#define STRSIZE 256

int main() {
    char* str = malloc(STRSIZE);

    strcpy(str, "Hello, My name is Inigo Montoya.");
    printf("%s\n", str);

    // Memory Leak
    free(str);

    // Use after free -> This is not a seg fault, AddressSanitizer can detect it.
    strcat(str, "you sent a signal #9 to my father.");

    return 0;
}