// Author: Yash Deshpande
// Date  : 18-10-2025
// Tutor : tutorialspoint (https://www.tutorialspoint.com/cprogramming/c_bit_fields.htm)

#include <stdio.h>

struct
{
    unsigned int age : 3;
} Age;

int main()
{

    Age.age = 4;
    printf("Sizeof(Age): %ld\n", sizeof(Age));
    printf("Age.age: %d\n", Age.age);

    Age.age = 7;
    printf("Age.age : %d\n", Age.age);

    Age.age = 8;
    printf("Age.age : %d\n", Age.age);

    // Output
    // Sizeof(Age) : 4 
    // Age.age : 4 
    // Age.age : 7 
    // Age.age : 0

    return 0;
}