// Author : Yash Deshpande
// Date   : 13-09-2025
// Tutor  : inpyjama YouTube

/*
Given 4 values 'm', 'n', 'x' & 'a' where 
'a' represents a 32-bit hex number
'm' & 'n' represent bit positions in 'a' where n>m
'x' represents a number smaller than 2^(n-m)
Set 'm' to 'n' th bit position in 'a' with value 'x'

Example
m = 4, n = 7
a = 0xdeadbeef
x = 0xa
answer = 0xdeadbeaf
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// Method-1 : Inefficient Approach
int updateNum(int m, int n, int a, int x) {
    int index = 0;
    for(int i=m; i<=n; i++) {
        // extract the last bit from x
        int bit = x&1;
        uint32_t mask = 1<<i;
        if(bit) {
            a = a | mask;
        }
        else {
            a = a & (~mask);
        }
        x = x>>1;
    }
    return a;
}

// Method-2 : Efficient Approach
int updateNum2(int m, int n, int a, int x) {
    // create a mask of all 1s 
    uint32_t mask = ((1<<(n-m+1))-1)<<m;
    
    // Shift x by the correct bit positions
    x = x << m;

    // clear out all the bits in the mask
    a = a & (~mask);
    a = a | x;
    return a;
}


int main() {
    int m = 4;
    int n = 7;
    int a = 0xdeadbeef;
    int x = 0xa;
    int ans = updateNum2(m, n, a, x);
    printf("0x%x\n", ans);
    return 0;
}