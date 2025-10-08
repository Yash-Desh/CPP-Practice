// Author : Yash Deshpande
// Date   : 04-10-2025
// Tutor  : NeetCode

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ############################
// Recursive Approach
// ############################
class Solution_Recursive {
    int solve(vector<int> &cost, int n) {
        if(n >= cost.size()) {
            return 0;
        }
        int cost1 = solve(cost, n+1);
        int cost2 = solve(cost, n+2);
        return min(cost1, cost2) + cost[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost, 0), solve(cost, 1));
    }
};

// ############################
// Memoization Approach
// TC : O(N)
// SC : O(N) + O(N) for the recursion stack space & dp array
// ############################
class Solution_Memoization {
    int solve(vector<int> &cost, int n, vector<int> &dp) {
        if(n >= cost.size()) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int cost1 = solve(cost, n+1, dp);
        int cost2 = solve(cost, n+2, dp);
        return dp[n] = min(cost1, cost2) + cost[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};

int main() {

    return 0;
}
