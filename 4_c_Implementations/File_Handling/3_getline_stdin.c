// Author: Yash Deshpande
// Date  : 04-11-2025
// Tutor : Gemini

// This is a POSIX-only function, it is not portable across systems.

#include <stdio.h>
#include <stdlib.h> // For free()
#include <sys/types.h>

int main() {
    char *line = NULL; // Pointer to store the line
    size_t len = 0;    // Size of the allocated buffer
    ssize_t read;      // Number of characters read

    printf("Type something: ");

    // Read a line from standard input
    read = getline(&line, &len, stdin);

    if (read != -1) {
        printf("You typed: '%s'\n", line);
        printf("Number of characters read: %zd\n", read);
    } else {
        perror("Error reading line");
    }

    free(line); // Free the dynamically allocated memory
    return 0;
}