// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube  

// Q Read a complete paragraph from a .txt file & then print line by line. 
// The line number will be the argument to your function.

#include <stdio.h>
#include <stdlib.h>

char *buffer = "This is line1.\nThis is line2.\nThis is line3.\nThis is line4.";

/*
This is line1.
This is line2.
This is line3.
This is line4.
*/

typedef char line[40];  // This contains a single line of 40 chars.
line lines[20];         // This contains 20 such lines.

void printLine (int lineNum) {
    printf("%s\n", lines[lineNum]);
}

void updateLine() {
    int charCnt = 0;
    int lineCnt = 0;
    char *Buff = buffer;

    while(*Buff != 0) {
        if(*Buff == '\n') {
            lineCnt++;
            charCnt = 0;
        }
        else {
            lines[lineCnt][charCnt] = *Buff;
            charCnt++;
        }
        Buff++;
    }
}

int main() {
    updateLine();
    printLine(2);
    return 0;
}