// Author: Yash Deshpande
// Date  : 26-09-2026
// Tutor : Jacob Sorber (How to write your own code libraries in C.)
// Link  : https://youtu.be/JbHmin2Wtmc?si=w5cMNeVbhJori1w6

#include "mycode.h"
#include<stdio.h>

int main(int argc, char** argv) {
    if(argc > 1) {
        printf("%s\n", argv[1]);
        printf("%s\n", reverse(argv[1]));
    }
    return 0; 
}