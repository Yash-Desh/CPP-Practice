// Author: Yash Deshpande
// Date  : 05-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ############################
// Normal Recursion Approach
// TC : 2^(N)
// SC : O(N) 
// N = number of rows in the matrix.
// Time Limit Exceeded!
// ############################
int solve(int i, int j, vector<vector<int>> &matrix) {
    // Base Case.
    int rows = matrix.size();
    int cols = matrix[0].size();
    if(j < 0 || j >= cols) {
        return INT_MIN;
    }

    if(i == 0) {
        return matrix[i][j];
    }

    int maxPath = 0;
    int up = solve(i-1, j, matrix);
    int left_diagonal = solve(i-1, j-1, matrix);
    int right_diagonal = solve(i-1, j+1, matrix);
    maxPath = max(up, max(left_diagonal, right_diagonal)) + matrix[i][j];
    return maxPath;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxPath = INT_MIN;
    for(int i=0; i<cols; i++) {
        maxPath = max(maxPath, solve(rows-1, i, matrix));
    }
    return maxPath;
}

// ############################
// Memoization Approach
// TC : O(N*M)
// SC : O(N) + O(N*M) ->  for the recursion call stack & the dp array
// ############################
int solve_memoization(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // Base Case.
    int rows = matrix.size();
    int cols = matrix[0].size();
    if(j < 0 || j >= cols) {
        return INT_MIN;
    }

    if(i == 0) {
        return matrix[i][j];
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int maxPath = 0;
    int up = solve_memoization(i-1, j, matrix, dp);
    int left_diagonal = solve_memoization(i-1, j-1, matrix, dp);
    int right_diagonal = solve_memoization(i-1, j+1, matrix, dp);
    maxPath = max(up, max(left_diagonal, right_diagonal)) + matrix[i][j];
    return dp[i][j] = maxPath;

}

int getMaxPathSum_memoization(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxPath = INT_MIN;
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    for(int i=0; i<cols; i++) {
        maxPath = max(maxPath, solve_memoization(rows-1, i, matrix, dp));
    }
    return maxPath;
}


// ############################
// Tabulation Approach
// TC : O(N*M) + O(M)  Extra time complexity to select answer from last row of dp array
// SC : O(N*M) ->  for the dp array
// NOTE : Traversal is in opposite direction to memoization 
// ############################
int getMaxPathSum_tabulation(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxPath = INT_MIN;
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    
    // Base Case for Tabulation.
    for(int j=0; j<cols; j++) {
        dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int left_diagonal = INT_MIN;
            int right_diagonal = INT_MIN;
            
            int up = dp[i-1][j];
            if(j-1 >= 0) {
                left_diagonal = dp[i-1][j-1];
            }
            if(j+1 < cols) {
                right_diagonal = dp[i-1][j+1];
            }
            int maxPath = max(up, max(left_diagonal, right_diagonal)) + matrix[i][j];
            dp[i][j] = maxPath;
        }
    }

    int ans = INT_MIN;
    for(int j=0; j<cols; j++) {
        ans = max(ans, dp[rows-1][j]);
    }
    return ans;
}

// ############################
// Space Optimization Approach
// TC : O(N*M)
// SC : O(M)  -> array to store a single row of previous results 
// ############################
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxPath = INT_MIN;
    vector<int> prev(cols, -1);
    
    // Base Case for Tabulation.
    for(int j=0; j<cols; j++) {
        prev[j] = matrix[0][j];
    }

    for(int i=1; i<rows; i++) {
        vector<int> temp(cols, -1);
        for(int j=0; j<cols; j++) {
            int left_diagonal = INT_MIN;
            int right_diagonal = INT_MIN;
            
            int up = prev[j];
            if(j-1 >= 0) {
                left_diagonal = prev[j-1];
            }
            if(j+1 < cols) {
                right_diagonal = prev[j+1];
            }
            int maxPath = max(up, max(left_diagonal, right_diagonal)) + matrix[i][j];
            temp[j] = maxPath;
        }
        prev = temp;
    }

    int ans = INT_MIN;
    for(int j=0; j<cols; j++) {
        ans = max(ans, prev[j]);
    }
    return ans;
}

int main() {
    return 0;
}

/* 

############################## Complexities Explained ##############################

1. Recursion Approach


*/