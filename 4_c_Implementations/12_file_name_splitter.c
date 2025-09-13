// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube  

// Q Split operation based on specific character from a string.

#include <stdio.h>
#include <stdlib.h>

char *buffer = "file.c,main.c,folder/sum.c,compile.c";

typedef char fileName[40];  // This contains a single line of 40 chars.
fileName fileList[20];         // This contains 20 such lines.

void splitFileNames(char splitter) {
    int charCnt = 0;
    int lineCnt = 0;
    char *Buff = buffer;

    while(*Buff != 0) {
        if(*Buff == splitter) {
            lineCnt++;
            charCnt = 0;
        }
        else {
            fileList[lineCnt][charCnt] = *Buff;
            charCnt++;
        }
        Buff++;
    }
}

int main() {
    splitFileNames(',');
    for(int i=0; i<4; i++) {
        printf("%s\n", fileList[i]);
    }
    return 0;
}