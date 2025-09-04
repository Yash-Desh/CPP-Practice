// Author: Yash Deshpande
// Date  : 02-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ############################
// Memoization Approach
// ############################
class Solution {
    int memoization(int n, vector<int> &dp) {
        if(n <= 1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return memoization(n, dp);
    }
};

int main()
{
    
    return 0;
}