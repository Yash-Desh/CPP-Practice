// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube

// Q Write set reset logic for a 32-bit variable
// Write a function that sets a specific bit position
// Write a function that resets a specific bit position

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Left shift  1  & perform OR operation.
uint32_t setBit(uint32_t data, uint8_t position) {
    // 0-based indexing
    uint32_t mask = 1 << position;
    return (data | mask);
}

// Left shift 1 then take complement & perform AND operation.
uint32_t resetBit(uint32_t data, uint8_t position) {
    // 0-based indexing
    uint32_t mask = ~(1 << position);
    return (data & mask);
}

int main() {
    uint32_t input = 7;                         // 111
    uint32_t output1 = setBit(input, 3);        // 1111
    uint32_t output2 = resetBit(output1, 2);    // 1011
    printf("Set the 3rd bit of %u to become %u\n", input, output1);
    printf("Reset the 2nd bit of %u to become %u\n", output1, output2);
    
    return 0;
}