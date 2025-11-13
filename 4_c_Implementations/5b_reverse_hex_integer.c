// Author : Yash Deshpande
// Date   : 21-102-205
// Tutor  : inpyjama YT (https://youtu.be/sk4d9ZO-9Gs?si=JsF2zcvy_GJ6adGZ)


// hexadecimal number -> swap bytes
// Q. 0xDEADBEEF -> 0xEFBEADDE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t swap1(uint32_t org_hex) {
    char* org_ptr, *new_ptr;
    uint32_t new_hex;

    org_ptr = (char *)&org_hex;
    new_ptr = (char *)&new_hex;

    uint32_t len = sizeof(org_hex);
    for(int i=0; i<len; i++) {
        new_ptr[i] = org_ptr[len-1-i];
    }

    return new_hex;
}

uint32_t swap2(uint32_t org_hex) {
    char* org_ptr;
    org_ptr = (char *)&org_hex;

    char temp;

    uint32_t len = sizeof(org_hex);
    for(int i=0; i<len/2; i++) {
        temp = org_ptr[i];
        org_ptr[i] = org_ptr[len-1-i];
        org_ptr[len-1-i] = temp;
    }

    return org_hex;
}


// There is one more solution in the video for using XOR swap

uint32_t swap3(uint32_t org_hex) {
    char* org_ptr;
    org_ptr = (char *)&org_hex;

    uint32_t len = sizeof(org_hex);
    for(int i=0; i<len/2; i++) {
        org_ptr[i] = org_ptr[i] ^ org_ptr[len-1-i]; 
        org_ptr[len-1-i] = org_ptr[i] ^ org_ptr[len-1-i];
        org_ptr[i] = org_ptr[i] ^ org_ptr[len-1-i];
    }

    return org_hex;
}

int main() {
    printf("%x\n", swap1(0xdeadbeef));
    printf("%x\n", swap2(0xdeadbeef));
    printf("%x\n", swap3(0xdeadbeef));
}