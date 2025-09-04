// Author: Yash Deshpande
// Date  : 02-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// ############################
// Memoization Approach
// TC : O(N*K) for each step you take k possible step
// SC : O(N) + O(N) for the recursion stack space & dp array
// ############################
int memoization(int index, int k, vector<int> &heights, vector<int> &dp) {
    // Base Case
    if(index == 0) {
        return 0;
    } 

    if(dp[index] != -1) {
        return dp[index];
    }

    int minSteps = INT_MAX;
    for(int j=1; j<=k; j++) {
        if(index-j >= 0) {
            int jump = memoization(index-j, k, heights, dp) + abs(heights[index]-heights[index-j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[index] = minSteps;
}

int frogJumpK(int n, int k, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    return memoization(n-1, k, heights, dp);
}


// ############################
// Tabulation Approach
// TC : O(N*K)
// SC : O(N) for the dp array
// ############################
int frogJumpK_2(int n, int k, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i = 1; i<=n-1; i++) {
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(minSteps, jump);
            }  
        }
    }
    return dp[n-1];
}

// ############################
// No Space Optimization for this Problem
// ############################

int main()
{
    
    return 0;
}