// Author: Yash Deshpande
// Date  : 03-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ############################
// Memoization Approach
// TC : O(N) 
// SC : O(N) + O(N) for the recursion stack space & dp array
// ############################
int solve_memoization(int index, vector<int> &nums, vector<int> &dp) {
    // Base Case
    if(index == 0) {
        return nums[0];
    }
    if(index < 0) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    int pick = nums[index] + solve_memoization(index-2, nums, dp);
    int notPick = solve_memoization(index-1, nums, dp);
    return dp[index] = max(pick, notPick);
}

int maximumNonAdjacentSum_memoization(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return solve_memoization(n-1, nums, dp);
}

// ############################
// Tabulation Approach
// TC : O(N)
// SC : O(N) for the dp array
// ############################
int maximumNonAdjacentSum_tabulation(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n+1, -1);
    
    // Base Case.
    dp[0] = nums[0];

    // Bottom-Up Approach
    for(int i=1; i<n; i++) {
        int pick = nums[i];
        if(i > 1) {
            pick += dp[i-2];
        }
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}

// ############################
// Space Optimization Approach
// TC : O(N)
// SC : O(1)
// ############################
int maximumNonAdjacentSum_spaceOpt(vector<int> &nums) {
    // Write your code here.
    int n = nums.size();
    
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1; i<n; i++) {
        int pick = nums[i];
        if(i > 1) {
            pick += prev2;
        }
        int notPick = prev;
        int current = max(pick, notPick);
        prev2 = prev;
        prev = current;
    }
    return prev;
}

int main()
{
    
    return 0;
}