// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : Gemini

#include <stddef.h> // for size_t
#include <stdio.h>

size_t custom_strlen(const char* str) {
    size_t length = 0;
    // Loop until the null character ('\0' is equivalent to 0 in C) is found
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char my_string[] = "Hello, world!";
    printf("The length of the string is: %zu\\n", custom_strlen(my_string));
    return 0;
}