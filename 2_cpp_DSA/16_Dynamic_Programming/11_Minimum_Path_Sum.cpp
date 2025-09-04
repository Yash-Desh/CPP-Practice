// Author: Yash Deshpande
// Date  : 03-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ############################
// Normal Recursion Approach
// TC : 2^(m*n)
// SC : O(m+n) 
// Time Limit Exceeded!
// ############################
int solve (int i, int j, vector<vector<int>> &grid) {
    // Base case.
    if(i == 0 && j == 0) {
        return grid[0][0];
    }

    if(i < 0 || j < 0) {
        return INT_MAX;
    }

    int left = solve(i, j-1, grid);
    int up = solve(i-1, j, grid);

    return min(up, left)+grid[i][j];
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols = grid[0].size();
    return solve(rows-1, cols-1, grid);
}

// ############################
// Memoization Approach
// TC : O(m*n)
// SC :O(m-1+n-1) + O(m*n)
// ############################
int solve_memoization (int i, int j, vector<vector<int>> &grid, vector<vector<int>>& dp) {
    // Base case.
    if(i == 0 && j == 0) {
        return grid[0][0];
    }

    if(i < 0 || j < 0) {
        return INT_MAX;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int left = solve_memoization(i, j-1, grid, dp);
    int up = solve_memoization(i-1, j, grid, dp);

    return dp[i][j] = min(up, left)+grid[i][j];
}

int minSumPath_memoization(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    return solve_memoization(rows-1, cols-1, grid, dp);
}

// ############################
// Tabulation Approach
// TC : O(m*n)
// SC : O(m*n)
// ############################
int minSumPath_tabulation(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }

            else {
                int left = INT_MAX;
                int up = INT_MAX;
                if(j-1 >= 0) {
                    left = dp[i][j-1];
                }
                if(i-1 >= 0) {
                    up = dp[i-1][j];
                }
                dp[i][j] = min(left, up) + grid[i][j];
            }
        }
    }
    return dp[rows-1][cols-1];
}

// ############################
// Space Optimization Approach
// TC : O(m*n)
// SC : O(m) 
// ############################
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> prev(cols, -1);
    for(int i=0; i<rows; i++) {
        vector<int> temp(cols, -1);
        for(int j=0; j<cols; j++) {
            if(i == 0 && j == 0) {
                temp[j] = grid[i][j];
            }

            else {
                int left = INT_MAX;
                int up = INT_MAX;
                if(j-1 >= 0) {
                    left = temp[j-1];
                }
                if(i-1 >= 0) {
                    up = prev[j];
                }
                temp[j] = min(left, up) + grid[i][j];
            }
        }
        prev = temp;
    }
    return prev[cols-1];
}

int main()
{
    return 0;
}

/* 

############################## Complexities Explained ##############################

*/