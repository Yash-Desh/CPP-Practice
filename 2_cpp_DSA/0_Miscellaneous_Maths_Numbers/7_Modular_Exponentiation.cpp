// Author : Yash Deshpande
// Date : 09-07-2022
// Tutor : Love Babbar

#include <iostream>
using namespace std;

// My Approach : Brute Force
// WA
// TC : O(N) ... where is the exponent
// SC : O(1)
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ans * x;
    }
    return ans % m;
}

// Babbar Approach : Optimal Approach
// TC : O(log(N)) ... where N is the exponent
// SC : O(1)
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int res = 1;
    while (n > 0)
    {
        // solve the odd exponent
        if (n & 1)
        {
            // typecast to long long to prevent overflow
            res = ((1LL) * (res % m) * (x % m)) % m;
        }

        // typecast to long long to prevent overflow
        x = ((1LL) * (x % m) * (x % m)) % m;

        // divide the exponent by 2
        n = n >> 1;
    }
    return res;
}

int main()
{

    return 0;
}