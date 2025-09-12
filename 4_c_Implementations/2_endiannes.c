// Author : Yash Deshpande
// Date   : 10-09-2025
// Tutor  : Gemini

#include <stdio.h>

int main() {
    unsigned int test_value = 1; // An integer with a known byte pattern
    char *byte_pointer = (char *)&test_value; // Point to the first byte of test_value

    if (*byte_pointer == 1) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    return 0;
}

/*

To determine the endianness of a system using C code, one common method involves inspecting the byte order of a multi-byte integer.
Method 1: Using a character pointer
This method leverages the fact that a char pointer can access individual bytes of a multi-byte data type like an int.


Explanation:
An unsigned int variable test_value is initialized to 1. In memory, this would be represented differently depending on the endianness:
Little Endian: The least significant byte (LSB) is stored at the lowest memory address. So, for a 4-byte integer, it would be 01 00 00 00 (hex).
Big Endian: The most significant byte (MSB) is stored at the lowest memory address. So, for a 4-byte integer, it would be 00 00 00 01 (hex).
A char pointer byte_pointer is created and made to point to the memory location of test_value. Since char is typically 1 byte, dereferencing byte_pointer will access the first byte of test_value.
If the value at the first byte (*byte_pointer) is 1, it indicates that the LSB is at the lowest memory address, meaning the system is Little Endian.
If the value at the first byte is 0, it indicates that the MSB is at the lowest memory address (and the LSB is at a higher address), meaning the system is Big Endian. 


*/