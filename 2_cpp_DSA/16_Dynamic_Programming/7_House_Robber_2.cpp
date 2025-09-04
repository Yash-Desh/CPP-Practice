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
        // Corner Case
        if(nums.size() == 1) {
            return nums[0];
        }

        vector<int> temp1, temp2;
        int n = nums.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
       

        for(int i=0; i<n; i++) {
            if(i != 0) {
                temp1.push_back(nums[i]);
            }
            if(i != n-1) {
                temp2.push_back(nums[i]);
            }
        }
        int with1stElement = solve_memoization(n-2, temp2, dp2);
        int withLastElement = solve_memoization(n-2, temp1, dp1);
        return max(with1stElement, withLastElement);

    }
};


int main()
{
    
    return 0;
}