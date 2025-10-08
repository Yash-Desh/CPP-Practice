// Author: Yash Deshpande
// Date  : 02-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// NOTE : The problem is solved like a 0-based indexing, 
// hence the max value you want to reach is n-1

// ############################
// Recursive Approach
// ############################
int solve_recursive(int n, vector<int> &heights) {
    // Base Case
    if(n == 0) return 0;

    int jump1 = solve_recursive(n-1, heights) + abs(heights[n] - heights[n-1]);
    int jump2 = INT_MAX;
    if(n-1 > 0)
        jump2 = solve_recursive(n-2, heights) + abs(heights[n] - heights[n-2]);

    return min(jump1, jump2);
}

int frogJump_recursive(int n, vector<int> &heights)
{
    // Write your code here.
    return solve_recursive(n-1, heights);
}


// ############################
// Memoization Approach
// TC : O(N)
// SC : O(N) + O(N) for the recursion stack space & dp array
// ############################
int memoization(int index, vector<int> &heights, vector<int> &dp) {
    if(index == 0) {
        return 0;
    }
    if(dp[index] != -1) {
        return dp[index];
    }

    int jump1 = memoization(index-1, heights, dp) + abs(heights[index]-heights[index-1]);
    int jump2 = INT_MAX;
    if(index > 1) {
        jump2 = memoization(index-2, heights, dp) + abs(heights[index]-heights[index-2]);
    }
    return dp[index] = min(jump1, jump2);
}

int frogJump_1(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    return memoization(n-1, heights, dp);
}

// ############################
// Tabulation Approach
// TC : O(N)
// SC : O(N) for the dp array
// ############################
int frogJump_2(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i = 1; i<=n-1; i++) {
        int jump1 = dp[i-1] + abs(heights[i]-heights[i-1]);
        int jump2 = INT_MAX;
        if(i > 1) {
            jump2 = dp[i-2] +  abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(jump1, jump2);
    }
    return dp[n-1];
}


// ############################
// Space Optimization Approach
// TC : O(N)
// SC : O(N) for the dp array
// ############################
int frogJump_2(int n, vector<int> &heights)
{
    // Write your code here.
    int prev = 0;
    int prev2 = 0;
    for(int i = 1; i<=n-1; i++) {
        int jump1 = prev + abs(heights[i]-heights[i-1]);
        int jump2 = INT_MAX;
        if(i > 1) {
            jump2 = prev2 +  abs(heights[i]-heights[i-2]);
        }
        int current = min(jump1, jump2);
        prev2 = prev;
        prev = current;
    }
    return prev;
}




int main()
{
    
    return 0;
}