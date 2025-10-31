// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : Gemini

#include <stdio.h>
#include <string.h>
#include <stddef.h> // For size_t

void *my_memset(void *s, int c, size_t n) {
    // Cast the void pointer to an unsigned char pointer to allow byte-level access.
    unsigned char *ptr = (unsigned char *)s;

    // Loop through each byte of the memory block.
    while (n > 0) {
        *ptr = (unsigned char)c;    // Assign the value 'c' (cast to unsigned char) to the current byte.
        ptr++;                      // Move to the next byte.
        n--;                        // Decrement the remaining count of bytes.
    }

    // Return the original pointer to the memory block.
    return s;
}

int main () {
   char str[50];
   strcpy(str, "Welcome to Tutorialspoint");
   printf("%s\n", str);

   // memset
   my_memset(str, '#', 7);
   printf("%s\n", str);
   
   return(0);
}