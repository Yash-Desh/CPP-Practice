// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : Gemini

#include <stdio.h>
#include <stddef.h> // For size_t

char *my_strncpy(char *dest, const char *src, size_t n) {
    char *original_dest = dest; // Store the original destination pointer to return

    // Copy characters from src to dest, up to n characters or until a null terminator is encountered in src
    while (n > 0 && *src != '\0') {
        *dest++ = *src++;
        n--;
    }

    // If n is still greater than 0, pad the rest of the destination with null terminators
    while (n > 0) {
        *dest++ = '\0';
        n--;
    }

    return original_dest; // Return the original destination pointer
}

int main()
{
    // Source string
    char src[] = "Hello, World!";
    // Destination string
    char dest[20];

    // Copy the first 5 characters from src to dest
    my_strncpy(dest, src, 5);

    // Null-terminate the destination string
    dest[5] = '\0';

    // Print the destination string
    printf("Destination string: %s\n", dest);

    return 0;
}