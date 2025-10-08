// Author : Yash Deshpande
// Date   : 05-10-2025
// Tutor  : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// ############################
// Memoization Approach
// TC : 
// SC : 
// ############################
class Solution {
    int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        // Base Cases.
        if(index == 0) {
            if(amount%coins[index] == 0) {
                return amount/coins[index];
            }
            else {
                return 1e9;
            }
        }

        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int notTake = solve(index-1, amount, coins, dp);
        int take = INT_MAX;
        if(amount >= coins[index]) {
            take = solve(index, amount-coins[index], coins, dp) +1;
        }
        return dp[index][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int result = solve(coins.size()-1, amount, coins, dp);
        return (result == 1e9) ? -1 : result;
    }
};

// ############################
// Tabulation Approach
// TC : 
// SC : 
// ############################
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        // int result = solve(coins.size()-1, amount, coins, dp);
        // return (result == 1e9) ? -1 : result;

        for(int amt = 0; amt <= amount; amt++) {
            if(amt%coins[0] == 0) {
                dp[0][amt] = amt/coins[0];
            }
            else {
                dp[0][amt] = 1e9;
            }
        }

        for(int index = 1; index < coins.size(); index++) {
            for(int amt = 0; amt <= amount; amt++) {
                int notTake = dp[index-1][amt];
                int take = INT_MAX;
                if(amt >= coins[index]) {
                    take = dp[index][amt-coins[index]] + 1;
                }
                dp[index][amt] = min(take, notTake);
            }
        }
        int ans = dp[coins.size()-1][amount];
        if(ans >= 1e9) {return -1;}
        else {return ans;}
    }
};

int main() {
    return 0;
}