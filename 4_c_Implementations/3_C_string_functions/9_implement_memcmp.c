// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : Gemini

#include <stdio.h>
#include <string.h>
#include <stddef.h> // For size_t

int my_memcmp(const void *ptr1, const void *ptr2, size_t n) {
    const unsigned char *p1 = ptr1;
    const unsigned char *p2 = ptr2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] < p2[i]) {
            return -1; // First block is less than the second
        } else if (p1[i] > p2[i]) {
            return 1;  // First block is greater than the second
        }
    }
    return 0; // Blocks are equal
}

int main() {
    int res = 0;
    char s1[10] = "geeks";
    char s2[10] = "greeks";

    // Use memcmp() to compare s1 and s2 up to
  	// length of s1
    res = memcmp(s1, s2, strlen(s1));

    // Check the result of memcmp
    if (res > 0)
        printf("s1 is greater");
    else if (res < 0)
        printf("s2 is greater");
    else
        printf("both are equal");

    return 0;
}