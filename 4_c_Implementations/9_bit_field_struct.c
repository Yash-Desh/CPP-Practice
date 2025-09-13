// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube

// Q Bit Field in structure

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

// Suppose you have 8 LEDs & you need to report their status ON/OFF

// NOTE: Use bit fields with CAUTION, there are some nasty rules around them.

// Method-1 : Space Inefficient
struct statusOfLEDs {
    int LED0;       // -> 4bytes each
    int LED1;
    int LED2;
    int LED3;
    int LED4;
    int LED5;
    int LED6;
    int LED7;

};

// Method-2 : Space Efficient
struct statusOfLED_bitField {
    int LED0 : 1;       // -> 4bytes each
    int LED1 : 1;
    int LED2 : 1;
    int LED3 : 1;
    int LED4 : 1;
    int LED5 : 1;
    int LED6 : 1;
    int LED7 : 1;
};

int main() {
    struct statusOfLEDs s1;
    printf("Sizeof the space inefficient approach is %lu bytes\n", sizeof(s1));     // 32 bytes

    struct statusOfLED_bitField sb1;
    printf("Sizeof the space efficient approach is %lu bytes\n", sizeof(sb1));     // 4 bytes

    return 0;
}