// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Love Babbar
// Platform : LeetCode

#include <bits/stdc++.h>
using namespace std;

// Brute Force : TLE
int pivotIndex(vector<int> &nums)
{
    int Lsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int Rsum = 0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            Rsum += nums[j];
        }
        if (Rsum == Lsum)
        {
            return i;
        }
        Lsum += nums[i];
    }
    return -1;
}

// Improved Brute Approach
// Use 2 arrays
// 1 to store the left cumulative sum up till that element
// 2 to store the right cumulative sum up till that element
// Iterate through the both arrays at once , the ith position
// having same left sum & right sum is pivot
int pivotIndex(vector<int> &arr)
{

    // create 2 vectors to store prefix & suffix sums
    vector<int> prefix = {0};
    vector<int> suffix = {0};

    int prefixSum = 0, suffixSum = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        prefixSum += arr[i - 1];
        prefix.push_back(prefixSum);
    }

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        suffixSum += arr[i + 1];
        suffix.insert(suffix.begin(), suffixSum);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (prefix[i] == suffix[i])
            return i;
    }

    return -1;
}

// Better Approach : Prefix Sum
int pivotIndex(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    int Lsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (Lsum == sum - nums[i] - Lsum)
        {
            return i;
        }
        Lsum += nums[i];
    }
    return -1;
}

int main()
{

    return 0;
}