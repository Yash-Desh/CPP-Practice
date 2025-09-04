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

class Solution {
    int solve_memoization(int index, vector<int>& nums, vector<int> &dp) {
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve_memoization(n-1, nums, dp);
    }
};

int main()
{
    
    return 0;
}