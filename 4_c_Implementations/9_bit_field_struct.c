// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : Embedded World YouTube

// Q Bit Field in structure

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

// Suppose you have 8 LEDs & you need to report their status ON/OFF

// NOTE: Use bit fields with CAUTION, there are some nasty rules around them.

/* ============================================================================
 * WARNING: BIT FIELD CRITICAL RULES & GOTCHAS
 * Added by     : Claude Opus 4.8
 * Date         : 01-07-2026
 * ----------------------------------------------------------------------------
 * 1. SILENT OVERFLOW
 *    A ": 1" field holds only 0 or 1. Assigning 2 wraps to 0, 3 wraps to 1,
 *    etc. The compiler usually gives NO warning.
 *
 * 2. SIGNEDNESS TRAP (see example below)
 *    With "int LED0 : 1", whether the single bit is treated as signed is
 *    implementation-defined. A 1-bit SIGNED field can only hold -1 and 0,
 *    NOT 0 and 1! Always use "unsigned int" for flags.
 *
 * 3. NO ADDRESS OF A BIT FIELD
 *    &reg.enable is illegal, because addresses point to bytes, not bits.
 *
 * 4. LAYOUT IS NOT PORTABLE
 *    Bit ordering, padding, and straddling of storage units are all
 *    compiler/platform dependent. Do not rely on exact layout across
 *    compilers (e.g. for network packets or hardware register mapping).
 *
 * 5. MISC RESTRICTIONS
 *    You cannot apply sizeof to a single bit field, and arrays of bit
 *    fields are not allowed.
 * ----------------------------------------------------------------------------
 * SIGNEDNESS TRAP EXAMPLE:
 *
 *      struct s { int flag : 1; };   // signed 1-bit field
 *      struct s x;
 *      x.flag = 1;
 *      printf("%d\n", x.flag);       // may print -1, NOT 1
 *
 *      // FIX: use unsigned
 *      struct s2 { unsigned int flag : 1; };
 *      struct s2 y;
 *      y.flag = 1;
 *      printf("%d\n", y.flag);       // reliably prints 1
 * ============================================================================
 */

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
// Always use unsigned int for single-bit bit fields
struct statusOfLED_bitField {
    unsigned int LED0 : 1;       // -> 4bytes each
    unsigned int LED1 : 1;
    unsigned int LED2 : 1;
    unsigned int LED3 : 1;
    unsigned int LED4 : 1;
    unsigned int LED5 : 1;
    unsigned int LED6 : 1;
    unsigned int LED7 : 1;
};

int main() {
    struct statusOfLEDs s1;
    printf("Sizeof the space inefficient approach is %lu bytes\n", sizeof(s1));     // 32 bytes

    struct statusOfLED_bitField sb1;
    printf("Sizeof the space efficient approach is %lu bytes\n", sizeof(sb1));     // 4 bytes

    return 0;
}