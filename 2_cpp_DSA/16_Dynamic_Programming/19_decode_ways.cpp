// Author : Yash Deshpande
// Date   : 28-07-2026
// Tutor  : 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution_memoization_top_down {
    
    int solve(int ind, string &s, vector<int> &dp) {
        // Base Case
        if(ind < 0) {
            return 1;
        }

        if(dp[ind] != -1) {
            return dp[ind];
        }

        int count = 0;
        int num1 = stoi(s.substr(ind, 1));
        if(num1 >= 1 && num1 <= 9) {
            count += solve(ind-1, s, dp);
        }
        if(ind > 0) {
            int num2 = stoi(s.substr(ind-1, 2));
            if(num2 >= 10 && num2 <= 26) {
                count += solve(ind -2, s, dp);
            }
        }
        return dp[ind] = count;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(n-1, s, dp);
    }
};

class Solution_memoization_bottom_up {
    bool validChar(int ind, string s) {
        int digit1 = int(s[ind] - '0');
        int digit2 = int(s[ind+1] - '0');
        int num = digit1*10 + digit2;
        if(num >=1 && num <= 26) { return true; }
        else {return false;}
    }

    int solve(int ind, string s, vector<int> &dp) {
        // Base Case
        if(ind >= s.size()) {
            return 1;
        }

        if(s[ind] == '0') {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }

        // 2 possible options at each position
        // take-1
        int take1 = solve(ind+1, s, dp);
        int take2 = 0;
        if((ind < s.size()-1) && validChar(ind, s)) {
            take2 = solve(ind+2, s, dp);
        }
        return dp[ind] = take1 + take2;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, dp);
    }
};
int main() {
    return 0;
}