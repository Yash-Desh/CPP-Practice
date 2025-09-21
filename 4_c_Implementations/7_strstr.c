#include <stddef.h> // For NULL

char *my_strstr(const char *haystack, const char *needle) {
    // If the needle is an empty string, return the haystack
    if (*needle == '\0') {
        return (char *)haystack;
    }

    // Iterate through the haystack
    while (*haystack != '\0') {
        const char *h_ptr = haystack;
        const char *n_ptr = needle;

        // Check for a match between the current position in haystack and the needle
        while (*n_ptr != '\0' && *h_ptr == *n_ptr) {
            h_ptr++;
            n_ptr++;
        }

        // If the entire needle was matched, return a pointer to the start of the match
        if (*n_ptr == '\0') {
            return (char *)haystack;
        }

        // Move to the next character in the haystack
        haystack++;
    }

    // If the needle was not found, return NULL
    return NULL;
}