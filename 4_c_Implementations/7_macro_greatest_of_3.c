// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube

// Q Write a macro to find the largest of 3 numbers without using if-else

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX(x, y, z) (x>y)? ((x>z)? x:z) : ((y>z)? y:z)

// Logically the macro should look like this 
int findMaxof3 (int num1, int num2, int num3) {
    if(num1 > num2) {
        if(num1 > num3) {
            return num1;
        }
        else {
            return num3;
        }
    }
    else {
        if(num2 > num3) {
            return num2;
        }
        else {
            return num3;
        }
    }
}

int main() {

    printf("Max of 7, 8, 9 is %u\n", MAX(7, 8, 9));
    return 0;
}