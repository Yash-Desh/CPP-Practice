// Author : Yash Deshpande
// Date   : 12-07-2026
// Tutor  : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution_Recursion {
    int solve(int ind, int prev_ind,vector<int>& arr, int n) {
      if(ind == n) return 0;

      int len = 0 + solve(ind+1, prev_ind, arr, n);
      if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
          len = max(len, 1 + solve(ind+1, ind, arr, n));
      }
      return len;
  }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(0, -1, nums, nums.size());
    }
};


// Memoization
class Solution_Memoization {
    int solve(int ind, int prev_ind,vector<int>& arr, int n, vector<vector<int>> dp) {
      if(ind == n) return 0;

      if(dp[ind][prev_ind+1] != -1) {
        return dp[ind][prev_ind+1   ];
      }

      int len = 0 + solve(ind+1, prev_ind, arr, n, dp);
      if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
          len = max(len, 1 + solve(ind+1, ind, arr, n, dp));
      }
      return dp[ind][prev_ind+1] = len;
  }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return solve(0, -1, nums, nums.size(), dp);
    }
};


int main() {
    return 0;
}