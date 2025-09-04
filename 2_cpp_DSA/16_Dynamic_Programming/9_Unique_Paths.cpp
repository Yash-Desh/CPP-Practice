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
int solve(int m, int n) {
	// Base Case.
	if(m == 0 && n == 0) {
		return 1;
	}

	if(m < 0 || n < 0) {
		return 0;
	}

    // Can only move to the left or top.
	int left = solve(m-1, n);
	int top = solve(m, n-1);

	return left + top;
}

int uniquePaths(int m, int n) {
	// Write your code here.
	return solve(m-1, n-1);
}

// ############################
// Memoization Approach
// TC : O(m*n)
// SC :O(m-1+n-1) + O(m*n)
// ############################
int solve_memoization(int m, int n, vector<vector<int>> &dp) {
	// Base Case.
	if(m == 0 && n == 0) {
		return 1;
	}

	if(m < 0 || n < 0) {
		return 0;
	}

	if(dp[m][n] != -1) {
		return dp[m][n];
	}

	int left = solve_memoization(m-1, n, dp);
	int top = solve_memoization(m, n-1, dp);

	return dp[m][n] = left + top;
}

int uniquePaths_memoization(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return solve_memoization(m-1, n-1, dp);
}

// ############################
// Tabulation Approach
// TC : O(m*n)
// SC : O(m*n)
// ############################
int uniquePaths_tabulation(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(i==0 && j==0) {
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
				dp[i][j] = left + up;
			}
		}
	}
	return dp[m-1][n-1];
}

// ############################
// Space Optimization Approach
// TC : O(m*n)
// SC : O(n) 
// ############################
int uniquePaths_spaceOpt(int m, int n) {
	// Write your code here.
	vector<int> prev(n, -1);
	
	for(int i=0; i<m; i++) {
		vector<int> temp(n, -1);
		for(int j=0; j<n; j++) {
			if(i==0 && j==0) {
				temp[j] = 1;
			}
			else {
				int up = 0;
				int left = 0;
				if(i-1 >=0) {
					up = prev[j];
				}
				if(j-1 >= 0) {
					left = temp[j-1];
				}
				temp[j] = up + left;
			}
		}
		prev = temp;
	}
	return prev[n-1];
}

int main()
{
    return 0;
}

/* 

############################## Complexities Explained ##############################

1. Recursive Approach:
TC : 2^(m*n)
-> There are m*n locations in the grid, for each location we could either go 
   left or top, thus 2 ways for every single location.

SC : O(m-1+n-1)
-> Recursive call stack = total path length traversed from the source to destination.


2. Memoization Approach: 
TC : O(m*n)
-> Each location will be called once before storing its result into the dp array. Hence 
   TC is total possible locations that can be visited.

SC : O(m-1+n-1) + O(m*n)
-> Recursive call stack = total path length traversed from the source to destination.
   Extra space will be required for the dp array\


3. Tabulation Approach: 
TC : O(m*n)
-> Each location will be called once before storing its result into the dp array. Hence 
   TC is total possible locations that can be visited.

SC : O(m*n)
-> Extra space will be required for the dp array


3. Tabulation Approach: 
TC : O(m*n)
-> Each location will be called once before storing its result into the dp array. Hence 
   TC is total possible locations that can be visited.

SC : O(n)
-> No Extra space will be required for the dp array

*/