// Author : 

// 11011001 -= 0xD9
// 00000001
// 10011011 -= 0x9B
#include <stdio.h>
#include <stdint.h>

// int reverse_binary(uint8_t num) {
//     int reversed = 0;
//     int bit;
//     for (int i = 0; i < 7; i++) {
//         bit = num & 1;
//         reversed |= bit;
//         reversed <<= 1;
//         printf("reversed: %#x\n", reversed);
//         num >>= 1;
//     }
//     return reversed | (num & 1);
// }

int reverse_binary(uint8_t num) {
    int ans = 0;
    int n = num;
    while(n) {
        ans = ans << 1;
        int bit = n & 1;
        if(bit) {
            ans |= bit;
        }
        n = n >> 1;
    }
    return ans;
}

// 0x81 -=

void test_val(unsigned int num, unsigned int expected) {
    int reversed = reverse_binary(num);
    printf("reverse_binary(\"%#x\") = %#x : %s\n",
           num, reversed, reversed == expected ? "PASS" : "FAIL");
}

int main() {
    // 0x9B = 1001-1011
    // 0x36 = 0011-0110
    test_val(0xD9, 0x9B);
    test_val(0, 0);
    test_val(0xFF, 0xFF);
    test_val(0x81, 0x81);
    test_val(-85, 0x31);

    // 1000-0001
}
