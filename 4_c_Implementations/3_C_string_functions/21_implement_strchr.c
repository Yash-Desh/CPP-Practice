// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : Gemini

#include <stdio.h>


char *my_strchr(const char *str, int c) {
    // Cast the integer to a character for comparison
    char search_char = (char)c;

    // Iterate through the string, including the null terminator
    do {
        if (*str == search_char) {
            // If the character is found, return a pointer to its location.
            // A cast to char* is performed to match the standard function signature,
            // which involves a potential constness mismatch (a well-known issue
            // in the C standard library).
            return (char *)str;
        }
    } while (*str++ != '\0'); // Move to the next character

    // If the loop finishes without finding the character (and it wasn't the null terminator itself), return NULL.
    return NULL;
}

int main()
{
    // define a string
    const char* str = "GeeksforGeeks";
    // define a char ch to be searched in str
    char ch = 's';

    // Use strchr to find the first occurrence of the
    // character 's'
    const char* result = my_strchr(str, ch);

    if (result != NULL) {
        // Calculate the position by subtracting the base
        // pointer from the result pointer
        printf("Character '%c' found at position: %ld\n",
               ch, result - str);
    }
    else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}
