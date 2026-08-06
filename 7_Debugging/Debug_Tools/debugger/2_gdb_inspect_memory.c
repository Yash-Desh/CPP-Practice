// Author: Yash Deshpande
// Date  : 08-01-2026
// Tutor : Jack Sorber
// Link  : https://youtu.be/A_pV61xFty8?si=1oNpodFz-YJcib1t

// ######################################################
// Determine why the size of this struct is 12B using gdb
// ######################################################

#include <stdio.h>
#include <stdint.h>

// #pragma pack(1)      // compiler directive to prevent struct padding
typedef struct {
    int8_t hours;
    uint32_t micros;
    uint16_t seconds;
} timestuff_t;

int main() {
    timestuff_t t = {.hours=6, .micros=0x12345678, .seconds = 0xDEAD};
    printf("%lu\n", sizeof(t));
    return 0;
}