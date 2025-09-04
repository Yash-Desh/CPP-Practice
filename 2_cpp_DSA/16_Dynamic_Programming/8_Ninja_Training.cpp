// Author: Yash Deshpande
// Date  : 03-09-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// ############################
// Memoization Approach
// TC : O(N*4)*3  -> N days with 4 possible states & 3 tasks per day 
// SC : O(N) + O(N*4) for the recursion stack space & dp array
// ############################
int solve_memoization(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp) {
    // Base Case.
    if(day == 0) {
        int maxPoints = INT_MIN;
        for(int i=0; i<3; i++) {
            if(i != lastTask) {
                maxPoints = max(maxPoints, points[day][i]);
            }
        }
        return maxPoints;
    }

    if(dp[day][lastTask] != -1) {
        return dp[day][lastTask];
    }

    int maxPoints = INT_MIN;
    for(int i=0; i<3; i++) {
        if(i != lastTask) {
            int currentPoints = points[day][i] + solve_memoization(day-1, i, points, dp);
            maxPoints = max(maxPoints, currentPoints);
        }
    }
    return dp[day][lastTask] = maxPoints;
}

int ninjaTraining_memoization(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // lastTask = 0, 1, 2, 3
    // lastTask = 3 -> when no other task is performed before.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve_memoization(n-1, 3, points, dp);
}


// ############################
// Tabulation Approach
// TC : O(N*4)*3  -> N days with 4 possible states & 3 tasks per day 
// SC : O(N*4) for the dp array
// ############################
int ninjaTraining_tabulation(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // task = 0, 1, 2, 3
    // task = 3 -> when no other task is performed previously
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    // Base Case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for(int day=1; day<n; day++) {
        for(int lastTask = 0; lastTask<4; lastTask++) {
            int maxPoints = INT_MIN;
            for(int i=0; i<3; i++) {
                if(i != lastTask) {
                    int currentPoints = points[day][i] + dp[day-1][i];
                    maxPoints = max(maxPoints, currentPoints);
                }
            }
            dp[day][lastTask] = maxPoints;
        }
    }

    return dp[n-1][3];
}


// ############################
// Space Optimization Approach
// TC : O(N*4)*3 -> N days with 4 possible states & 3 tasks per day 
// SC : O(1) 
// ############################
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // task = 0, 1, 2, 3
    // task = 3 -> when no other task is performed previously
    vector<int> prev(4, -1);
    
    // Base Case
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][1], max(points[0][2], points[0][0]));

    for(int day=1; day<n; day++) {
        vector<int>temp(4, 0);
        for(int lastTask = 0; lastTask<4; lastTask++) {
            int maxPoints = INT_MIN;
            for(int i=0; i<3; i++) {
                if(i != lastTask) {
                    int currentPoints = points[day][i] + prev[i];
                    maxPoints = max(maxPoints, currentPoints);
                }
            }
            temp[lastTask] = maxPoints;
        }
        prev = temp;
    }

    return prev[3];
}

int main()
{
    
    return 0;
}