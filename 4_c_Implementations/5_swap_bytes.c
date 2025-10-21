// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube

// Q. Do a bytes swap: Given=0xCC8700FC --> Expected=0xFC0087CC

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>   // --> for uint32_t 

// Solution 
// 1. Extract 1nByte & store in temp
// 2. Shift input towards left
// 3. Add the new extracted byte

uint32_t swapBytes(uint32_t data) {
    uint32_t output = 0x0;
    uint8_t temp = 0x0;

    // loop to extract 4 consecutive bytes
    for(int i=0; i<4; i++) {
        output = output<<8;
        temp = (data >> (8*i)) & 0xFF;
        output |= temp;
    }
    return output;
}

int main() {
    
    uint32_t input = 0xCC8700FC;
    uint32_t output = swapBytes(input);
    printf("After swapping bytes 0x%x becomes 0x%x\n", input, output);
    return 0;
}