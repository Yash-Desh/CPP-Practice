// Author : Yash Deshpande
// Date : 31-01-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Approach - 1 : Recursion (only)
// TLE

int countDistinctWays(int nStairs)
{
    //  Write your code here.

    // Base Case
    if (nStairs < 0)
        return 0;

    if (nStairs == 0)
        return 1;

    // Recursive Call
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main()
{

    return 0;
}