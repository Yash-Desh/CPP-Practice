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

class Solution_Memoization {
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

/* 

############################## Complexities Explained ##############################

1. Recursive Approach
TC : O(2^N)
-> For each index, we have 2 choices/recursive function calls i.e. pick & notPick, hence
   TC will be 2*2*2*...*2 = 2^N for N elements in the array

SC : O(N)
-> Considering that there is at least 1 recursive call per each index, max stack space will be N 

2. Memoization Approach
TC : O(N) 
-> Each element will be called recursively once before storing result into dp array. Access to 
   the dp array take place in constant time.

SC : O(N) + O(N) 
-> for the recursion stack space & dp array

*/