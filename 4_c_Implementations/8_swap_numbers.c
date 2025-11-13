// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube

// Q Swap 2 numbers without using any extra variable

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

void swap1(int* num1, int* num2) {
    // swapping
    *num1 = *num1^*num2;
    *num2 = *num2^*num1;
    *num1 = *num1^*num2;
}

void swap2(int* num1, int* num2) {
    // swapping
    *num1 = *num1+*num2;
    *num2 = *num1-*num2;
    *num1 = *num1-*num2;
}

void swap3(int *num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    int num1 = 5;
    int num2 = 6;
    printf("Initially num1 = %d & num2 = %d\n", num1, num2);

    // swap1(&num1, &num2);
    // swap2(&num1, &num2);
    swap3(&num1, &num2);

    printf("After swapping num1 = %d & num2 = %d\n", num1, num2);
    return 0;
}