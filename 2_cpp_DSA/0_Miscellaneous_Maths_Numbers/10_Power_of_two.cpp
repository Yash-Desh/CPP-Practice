// Author : Yash Deshpande
// Date : 10-07-2022
// Tutor : Love Babbar

#include <iostream>
using namespace std;

// My Approach : RTE
// Large numbers cannot be processed
bool isPowerOfTwo(int n)
{
    int divisor = 1;
    while (divisor <= n)
    {
        if (divisor == n)
            return true;

        divisor *= 2;
    }
    return false;
}

// Babbar Approach
bool isPowerOfTwo(int n)
{
    // negative numbers
    if (n <= 0)
        return false;

    // count the number of bits=1 in the binary equivalent
    // of the given number
    int count = 0;
    while (n)
    {
        int bit = n & 1;
        if (bit)
            count++;
        n = n >> 1;
    }
    // if only 1 bit is high, then it is a power of 2
    // eg. 1, 2, 4, 8, 16, 32
    // 1 = 0001
    // 2 = 0010
    // 4 = 0100
    // 8 = 1000 and so on
    return count == 1;
}

// Best Approach :
// TC : O(1)
// Note that any number that is a power of 2 & its previous number
// if we AND them together, result = 0
// 4 & 3 = 0100 & 0011 = 0
// 8 & 7 = 1000 & 0111 = 0
bool isPowerOfTwo(int n)
{
    return n > 0 && !(n & n - 1);
}

int main()
{


    return 0;
}