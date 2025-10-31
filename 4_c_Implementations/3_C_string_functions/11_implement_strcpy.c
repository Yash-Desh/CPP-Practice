// Author : Yash Deshpande
// Date   : 17-09-2025
// Source : Gemini

#include <stdio.h> // Required for printf in main
#include <assert.h> // Required for assert

// Function to implement strcpy
char *my_strcpy(char *dest, const char *src) {
    if (!dest || !src) {        // Handle null pointers for safety
        return NULL;
    }
    char *temp = dest;          // Store the original destination pointer to return it
    // Copy characters from source to destination until the null terminator is reached
    while ((*dest++ = *src++) != '\0');
    return temp;                // Return the original destination pointer
}

int main() {
    char source[] = "Hello, World!";
    char destination[20]; // Ensure destination array is large enough

    printf("Source string: %s\n", source);

    my_strcpy(destination, source);

    printf("Destination string: %s\n", destination);

    // Example with another string
    char source2[] = "C Programming";
    char destination2[50];
    my_strcpy(destination2, source2);
    printf("Another copied string: %s\n", destination2);

    return 0;
}