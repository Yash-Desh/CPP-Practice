// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : Gemini

#include <stdio.h>
#include <stdlib.h>


int my_strcmp(const char *s1, const char *s2) {
    // Iterate while both strings have characters and they match
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    // Return the difference between the first non-matching characters
    // This will be 0 if the loop finished because both strings ended at the same time
    // and will be positive or negative otherwise
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main() {
    
    char s1[] = "g f g";
    char s2[] = "g f g";
    
    // Using strcmp() to compare s2 and s2
    int res = my_strcmp(s1, s2);
    
    if (res == 0)
        printf("Equal\n");
    else
        printf("Unequal\n");
  
    return 0;
}