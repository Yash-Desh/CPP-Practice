// Author : Yash Deshpande
// Date   : 05-10-2025
// Tutor  : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

int solve_memoization(int ind, int wt, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {
	// Base Case
	if(ind == 0) {
		if(wt >= weight[0]) {
			return value[0];
		}
		else {
			return 0;
		}
	}

	if(dp[ind][wt] != -1) {
		return dp[ind][wt];
	}

	int notTake = solve_memoization(ind-1, wt, weight, value, dp);
	int take = INT_MIN;
	if(wt >= weight[ind]) {
		take = value[ind] + solve_memoization(ind-1, wt-weight[ind], weight, value, dp);
	}
	return dp[ind][wt] = max(take, notTake);
}

int knapsack_memoization(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp (n, vector<int>(maxWeight + 1, -1));
	return solve_memoization(n-1, maxWeight, weight, value, dp);
}

// Tabulation
int knapsack_tabulation(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp (n, vector<int>(maxWeight + 1, 0));

	// Base Case
	for(int wt = weight[0]; wt <= maxWeight; wt++) {
		dp[0][wt] = value[0];
	}

	for(int ind = 1; ind < n; ind++) {
		for(int wt = 0; wt <= maxWeight; wt++) {
			int notTake = dp[ind-1][wt];
			int take = INT_MIN;
			if(wt >= weight[ind]) {
				take = dp[ind-1][wt-weight[ind]] + value[ind];
			}
			dp[ind][wt] = max(take, notTake);
		}
	}
	return dp[n-1][maxWeight];
}


// Space Optimization
int knapsack_space_optimization(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight+1, 0);

	// Base Case
	for(int wt = weight[0]; wt <= maxWeight; wt++) {
		prev[wt] = value[0];
	}


	for(int ind = 1; ind < n; ind++) {
		vector<int> curr(maxWeight+1, 0);
		for(int wt = 0; wt <= maxWeight; wt++) {
			int notTake = prev[wt];
			int take = INT_MIN;
			if(wt >= weight[ind]) {
				take = prev[wt-weight[ind]] + value[ind];
			}
			curr[wt] = max(take, notTake);
		}
		prev = curr;
	}
	return prev[maxWeight];
}

int main() {
    return 0;
}