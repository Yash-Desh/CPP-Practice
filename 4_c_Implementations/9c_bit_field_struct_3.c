// Author: Yash Deshpande
// Date  : 18-10-2025
// Tutor : GFG (https://www.geeksforgeeks.org/c/bit-fields-c/)

// C program to demonstrate use of Bit-fields
#include <stdio.h>

// Space optimized representation of the date
struct date {
    // d has value between 0 and 31, so 5 bits
    // are sufficient
    int d : 5;

    // m has value between 0 and 15, so 4 bits
    // are sufficient
    int m : 4;

    int y;
};

int main()
{
    printf("Size of date is %lu bytes\n",
           sizeof(struct date));
    struct date dt = { 31, 12, 2014 };
    printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
    return 0;
}

/*

Explanation

The output comes out to be negative. What happened behind is that the value 31 
was stored in 5 bit signed integer which is equal to 11111. 
The MSB is a 1, so it's a negative number and you need to calculate the 2's 
complement of the binary number to get its actual value which is what is done internally.

By calculating 2's complement you will arrive at the value 00001 which is equivalent 
to the decimal number 1 and since it was a negative number you get a -1. 
A similar thing happens to 12 in which case you get a 4-bit representation as 1100 and on 
calculating 2's complement you get the value of -4.

*/