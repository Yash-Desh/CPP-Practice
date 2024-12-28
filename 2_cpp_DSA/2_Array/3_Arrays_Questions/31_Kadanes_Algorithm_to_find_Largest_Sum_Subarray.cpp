// Author : Yash Deshpande
// Date : 10-10-2022
// Topic : Arrays
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Method-1 : Brute Force
// TC : O(N^2)
// SC : O(1)
int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum > maxi)
                maxi = sum;
        }
    }
    return maxi;
}

// Method-2 : Optimal Approach
// Kadane's Algorithm
// TC : O(N)
// SC : O(1)
int maxSubArray(vector<int> &nums)
{
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (sum > max)
            max = sum;

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max;
}

int main()
{

    return 0;
}