// Author : Yash Deshpande
// Date : 10-07-2022
// Tutor : Love Babbar

#include <iostream>
using namespace std;

// My Approach :
// TC : O(N) ... if N is the number of digits in n
int bitwiseComplement(int n)
{
    // for zero
    if (!n)
        return 1;
    // for non-zero numbers
    int ans = 0, i = 0;
    while (n)
    {
        int bit = n & 1;
        if (!bit)
            ans = pow(2, i) + ans;
        n = n >> 1;
        i++;
    }
    return ans;
}

// Babbar Approach
int bitwiseComplement(int n)
{
    // corner case
    if (n == 0)
        return 1;

    // Note that int is 4bytes = 32bits
    // Any number say for eg. 5 = 0000 0000 0000 0000 0000 0000 0000 0101
    // is represented likewise in memory
    // ~5 = 1111 1111 1111 1111 1111 1111 1111 1010
    // but the question wants ans = 0000 0000 0000 0000 0000 0000 0000 1010
    // Thus after taking ~5 we need to maintain the last 4 bits & toggle the 
    // initial 28 bits, thus we use a mask

    // normal case
    int mask = 0;
    int m = n;
    while (m) // create a mask
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    return ~n & mask;
}

int main()
{

    return 0;
}