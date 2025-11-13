// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube

#include <stdio.h>
#include <stdlib.h>

int sum (int a, int b) {
    return a+b;
}

int mul(int a, int b) {
    return a*b;
}

void myPrint(int val) {
    printf("myPrint: %d\n", val);
}

int main() {
    int num1 = 5;
    int num2 = 10;
    
    // return_type (*func_ptr_name) (argtype)
    int (*fp1)(int, int);
    // assign the allocated function address
    fp1 = sum;

    printf("Sum of %d + %d = %d\n", num1, num2, fp1(5, 10));                    // Sum of 5 + 10 = 15

    // Function pointer taking function pointer as argument.
    void (*fp2)(int);
    fp2 = myPrint;
    fp2(fp1(7, 35));                                                            // myPrint: 42

    // Array of Function Pointers.
    int (*fp[2])(int, int) = {sum, mul};
    printf("a+b = %d\na*b = %d\n", fp[0](num1, num2), fp[1](num1, num2));       // a+b = 15
                                                                                // a*b = 50
    
    return 0;
}