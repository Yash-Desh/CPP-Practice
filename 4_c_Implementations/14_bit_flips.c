// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : inpyjama YouTube

/*
Q Given 2 integers 'a' & 'b' count the number of bits 
you need to flip to convert 'a' into 'b'
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int bitFlips(int a, int b) {
    int temp = a^b;
    int cnt = 0;
    while(temp) {
        // This resets the last set bit of a number
        temp = temp&(temp-1);
        cnt++;
    }
    return cnt;
}

int main() {
    int a = 5;
    int b = 15;
    printf("Number of bits flipped to convert %d into %d are %d\n", a, b, bitFlips(a, b));
    return 0;
}