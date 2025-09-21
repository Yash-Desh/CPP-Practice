// Author: Yash Deshpande
// Date  : 02-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ############################
// Recursive Approach
// ############################
class Solution1 {
    int solve(int n) {
        if(n <= 1) {
            return 1;
        }
        return solve(n-1) + solve(n-2);
    }
public:
    int climbStairs(int n) {
        return solve(n);
    }
};

// ############################
// Memoization Approach
// ############################
class Solution2 {
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

// ############################
// Tabulation Approach
// ############################
class Solution {
public:
    int climbStairs_tabulation(int n) {
        vector<int> dp(n+1, -1);
        dp[0]= dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    
    return 0;
}