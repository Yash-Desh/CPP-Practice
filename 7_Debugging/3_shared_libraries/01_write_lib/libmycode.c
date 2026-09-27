// Author: Yash Deshpande
// Date  : 26-09-2026
// Tutor : Jacob Sorber (How to write your own code libraries in C.)
// Link  : https://youtu.be/JbHmin2Wtmc?si=w5cMNeVbhJori1w6

#include "mycode.h"
#include<string.h>

char* reverse(char* string) {
    int len = strlen(string);
    for(int i = 0; i < len/2; i++) {
        char temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }
    return string;
}