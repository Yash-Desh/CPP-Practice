// Author: Yash Deshpande
// Date  : 20-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ############################
// Recursion Approach
// TC : 2^(N)
// SC : O(N) 
// Time Limit Exceeded!
// ############################
bool solve_recursive (int n, int k, vector<int> &arr) {
    // Base Case.
    if(k == 0) {
        return true;
    }

    if(n == 0) {
        if(arr[0] == k) {
            return true;
        }
        else {
            return false;
        }
    }

    bool notPick = solve_recursive(n-1, k, arr);
    bool pick = false;
    if(k >= arr[n]) {
        pick = solve_recursive(n-1, k-arr[n], arr);
    }
    return pick | notPick; 
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    solve_recursive(n-1, k, arr);
}


// ############################
// Memoization Approach
// TC : O(N * target)
// SC : O(N * target) + O(N)
// ############################
bool solve_memoization (int n, int k, vector<int> &arr, vector<vector<int>> &dp) {
    // Base Case.
    if(k == 0) {
        return true;
    }

    if(n == 0) {
        return (arr[0] == k);
    }

    if(dp[n][k] != -1) {
        return dp[n][k];
    } 

    bool notPick = solve_memoization(n-1, k, arr, dp);
    bool pick = false;
    if(k >= arr[n]) {
        pick = solve_memoization(n-1, k-arr[n], arr, dp);
    }
    return dp[n][k] = pick | notPick;
    
}

bool subsetSumToK_memoization(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return  solve_memoization(n-1, k, arr, dp);
}

// ############################
// Tabulation Approach
// TC : O(N * target)
// SC : O(N * target) ->  for the dp array
// NOTE : Traversal is in opposite direction to memoization 
// ############################
bool subsetSumToK_tabulation(int n, int k, vector<int> &arr) {
    // Declare DP vector.
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    
    // Base Case: When target == 0
    for(int i=0; i<n; i++) {
        dp[i][0] = true; 
    }

    // Base Case: if((index == 0) && target == arr[0])
    dp[0][arr[0]] = true;

    // Loop indices explained : 
    // Both base conditions handled the 0-cases hence we start
    // from 1 in both indices.
    for(int i=1; i<n; i++) {
        for(int target=1; target<=k; target++) {
            bool notPick = dp[i-1][target];
            bool pick = false;
            if(arr[i] <= target) {
                pick = dp[i-1][target-arr[i]];
            }
            dp[i][target] = pick | notPick;
        }
    }
    return dp[n-1][k];
}

// ############################
// Space Optimization Approach
// TC : O(N*target)
// SC : O(k)  -> array to store a single row of previous results 
// ############################
bool subsetSumToK_spaceOpt(int n, int k, vector<int> &arr) {
    // Declare DP vector.
    vector<bool> prev(k+1, 0);
    vector<bool> curr(k+1, 0);

    // Base Cases.
    prev[0] = true;
    curr[0] = true;
    if(arr[0] <= k) {
        prev[arr[0]] = true;
    }

    for(int i=1; i<n; i++) {
        for(int target=1; target<=k; target++) {
            bool notPick = prev[target];
            bool pick = false;
            if(arr[i] <= target) {
                pick = prev[target-arr[i]];
            }
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    return prev[k];
}

int main() {
    return 0;
}

/* 

############################## Complexities Explained ##############################

1. Recursion Approach
TC : 2^N
-> For each element in the array, we have 2 choices whether to pick or not pick
   hence the time complexity.

SC : O(N)
-> Required for the recursion call stack.

2. Memoization Approach
TC : O(N * target)
SC : O(N * target) + O(N)


3. Tabulation Approach 



*/