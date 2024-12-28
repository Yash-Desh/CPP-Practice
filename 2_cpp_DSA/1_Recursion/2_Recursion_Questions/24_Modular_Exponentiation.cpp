// Author : Yash Deshpande
// Date : 17-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Iterative Approach
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = ((1LL) * (res % m) * (x % m)) % m;
        }
        x = ((1LL) * (x % m) * (x % m)) % m;
        n = n >> 1;
    }
    return res;
}


// Recursive Approach
long long int PowMod(long long int x, long long int n, long long int M)
{
    // Code here
    if (n == 0)
        return 1;

    if (n & 1)
        return ((x % M) * PowMod((x % M) * (x % M), n / 2, M)) % M;

    else
        return PowMod((x % M) * (x % M), n / 2, M) % M;
}

int main()
{

    return 0;
}