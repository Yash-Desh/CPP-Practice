// Author: Yash Deshpande
// Date  : 03-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Required as per question
int mod = (int)(1e9+7);

// ############################
// Normal Recursion Approach
// TC : 2^(m*n)
// SC : O(m+n) 
// Time Limit Exceeded!
// ############################
int solve(int n, int m, vector<vector<int>> &mat) {
    // Base Case.
    if(m == 0 && n == 0) {
        return 1;
    }

    if(m < 0 || n < 0) {
        return 0;
    }

    if(mat[n][m] == -1) {
        return 0;
    }
    int left = solve(n-1, m, mat);
    int up = solve(n, m-1, mat);
    return left + up;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return solve(n-1, m-1, mat);
}

// ############################
// Memoization Approach
// TC : O(m*n)
// SC :O(m-1+n-1) + O(m*n)
// ############################
int solve_memoization(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp) {
    // Base Case.
    
    if(m >= 0 && n >= 0 && mat[n][m] == -1) {
        return 0;
    }
    
    if(m == 0 && n == 0) {
        return 1;
    }

    if(m < 0 || n < 0) {
        return 0;
    }

    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    int left = solve_memoization(n-1, m, mat, dp);
    int up = solve_memoization(n, m-1, mat, dp);
    return dp[n][m] = (left + up)%mod;
}


int mazeObstacles_memoization(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve_memoization(n-1, m-1, mat, dp);
}

// ############################
// Tabulation Approach
// TC : O(m*n)
// SC : O(m*n)
// ############################
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(m, -1));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(mat[i][j] == -1) {
                dp[i][j] = 0;
            }
            
            else if(i==0 && j==0) {
				dp[0][0] = 1;
			}
			else {
				int left = 0;
				int up = 0;
				if(i-1 >=0) {
					left = dp[i-1][j];
				}
				if(j-1 >= 0) {
					up = dp[i][j-1];
				}
				dp[i][j] = (left + up)%mod;
			}
		}
	}
	return dp[n-1][m-1];
}

// ############################
// Space Optimization Approach
// TC : O(m*n)
// SC : O(n) 
// ############################
int mazeObstacles_spaceOpt(int n, int m, vector< vector< int> > &mat) {
	// Write your code here.
	vector<int> prev(m, -1);
	
	for(int i=0; i<n; i++) {
		vector<int> temp(m, -1);
		for(int j=0; j<m; j++) {
			if(mat[i][j] == -1) {
                temp[j] = 0;
            }
            
            else if(i==0 && j==0) {
				temp[0] = 1;
			}
			else {
				int left = 0;
				int up = 0;
				if(i-1 >=0) {
					up = prev[j];
				}
				if(j-1 >= 0) {
					left = temp[j-1];
				}
				temp[j] = (left + up)%mod;
			}
		}
		prev = temp;
	}
	return prev[m-1];
}


int main()
{
    return 0;
}

/* 

############################## Complexities Explained ##############################

*/