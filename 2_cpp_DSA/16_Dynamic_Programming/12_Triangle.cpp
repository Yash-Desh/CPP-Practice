// Author: Yash Deshpande
// Date  : 05-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// NOTE: Here recursion is being done from (0,0) to (n-1, n-1)
// That is because there is no fixed ending point in this problem
// But there is a fixed starting poing (0, 0). 

// ############################
// Normal Recursion Approach
// TC : 2^(n*(n+1))/2
// SC : O(n) 
// n = number of rows in the triangle.
// Time Limit Exceeded!
// ############################
int solve(vector<vector<int>>& triangle, int n, int i, int j) {
	// Base case 

	if(i == n-1) {
		return triangle[i][j];
	}

	int bottom = solve(triangle, n, i+1, j);
	int diagonal = solve(triangle, n, i+1, j+1);

	return min(bottom, diagonal) + triangle[i][j];
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	return solve(triangle, n, 0, 0);
}

// ############################
// Memoization Approach
// TC : O(n*(n+1)/2)
// SC : O(n) + O(n^2) ->  for the recursion call stack & the dp array
// ############################
int solve_memoization(vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>> &dp) {
	// Base case 

	if(i == n-1) {
		return triangle[i][j];
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	int bottom = solve_memoization(triangle, n, i+1, j, dp);
	int diagonal = solve_memoization(triangle, n, i+1, j+1, dp);

	return dp[i][j] = min(bottom, diagonal) + triangle[i][j];
}

int minimumPathSum_memoization(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve_memoization(triangle, n, 0, 0, dp);
}

// ############################
// Tabulation Approach
// TC : O(n*(n+1)/2)
// SC : O(n^2) ->  for the dp array
// NOTE : Traversal is in opposite direction to memoization 
// ############################
int minimumPathSum_tabulation(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n, -1));
	
    // There are n+1 base cases as there are n+1 possible destinations.
    for(int i=0; i<n; i++) {
		dp[n-1][i] = triangle[n-1][i];
	}

	for(int i=n-2; i>=0; i--) {
		for(int j=i; j>=0; j--) {
			dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
		}
	}
	return dp[0][0];
}

// ############################
// Space Optimization Approach
// TC : O(n*(n+1)/2)
// SC : O(n)  -> there are n+1 elements in the nth level of the triangle 
// ############################
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<int> prev(n, -1);

	// Base Case
	for(int i=0; i<n; i++) {
		prev[i] = triangle[n-1][i];
	}


	for(int i=n-2; i>=0; i--) {
		vector<int> temp(n, -1);
		for(int j=i; j>=0; j--) {
			temp[j] = min(prev[j], prev[j+1]) + triangle[i][j];
		}
		prev = temp;
	}
	return prev[0];
}

int main() {
    return 0;
}

/* 

############################## Complexities Explained ##############################

1. Recursion Approach
TC : 2^{(n*(n+1))/2}
-> In each of the rows there are 1 -> 2 -> 3 -> ... -> n elements
   Each element has 2 choices either to go down to the diagonal
   hence 2^(total number of elements in the triangle)

SC : O(n)
-> max number of elements in the stack space for the recursive call.
   n is the number of rows in the triangle

*/