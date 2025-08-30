// Author: Yash Deshpande
// Date  : 19-08-2025
// Tutor : Striver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ########################
// DP Memoization Approach
// TC : O(n)     -> only n recursive calls will be made the rest are constant calls
// SC : O(n) + O(n)  -> for stack space & the dp array
// ########################
int fib_memoization(int n, vector<int> &dp)
{
    // Base Case.
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fib_memoization(n-1, dp) + fib_memoization(n-2, dp);
}

// #######################
// DP Tabulation approach
// TC : O(N)
// SC : O(1)
// #######################
int fib_tabulation(int n)
{
    int prev = 1;
    int prev2 = 0;
    for(int i=2; i<=n; i++)
    {
        int current = prev + prev2;
        prev2 = prev;
        prev = current;
    }
    return prev;
}


int main()
{
    int n;
    cout<<"Enter the number for Fibonacci sequence : ";
    cin>>n;
    // vector<int> dp (n+1, -1);
    // int result = fib_memoization(n, dp);
    int result = fib_tabulation(n);
    cout<<n<<"th number in the fibonacci sequence is "<<result<<"\n";
    return 0;
}