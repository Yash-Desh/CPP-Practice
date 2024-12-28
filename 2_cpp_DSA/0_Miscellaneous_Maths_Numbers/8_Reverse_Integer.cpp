// Author : Yash Deshpande
// Date : 10-07-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Optimal Approach
// TC : O(N) ... where x contains N digits
int reverse(int x)
{
    int ans = 0;
    int n = x;

    // Handles both cases 
    // when n > 0 
    // when n < 0
    while (n)
    {
        // Extract the last digit
        int digit = n % 10;

        // Check for overflow beyond the storage capacity of integer
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
            return 0;

        // Add the digit to the answer
        ans = ans * 10 + digit;
        n = n / 10;
    }
    return ans;
}

int main()
{

    return 0;
}