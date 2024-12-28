// Author : Yash Deshpande
// Date : 01-07-2023
// Tutor : Love Babbar
// Website : LeetCode

#include <bits/stdc++.h>
using namespace std;

// My Approach : Modified from Babbar approach
bool check(vector<int> &nums)
{

    int pivotCnt = 0;

    // loop to determine if array is sorted
    // or if it has a pivot point
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
        {
            pivotCnt++;
        }
    }

    // No pivot point detected
    // Array is also sorted
    if (pivotCnt == 0)
        return true;

    // One pivot point detected
    // Hence array must be rotated & sorted
    // To confirm compare first & last elements
    else if (pivotCnt == 1 && nums[0] >= nums[nums.size() - 1])
        return true;

    // More than 1 pivot points detected
    // Array not sorted & rotated
    else
        return false;
}





// Babbar Appraoch
bool check(vector<int> &nums)
{
    // Babbar solution
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
            count++;
    }

    // compare the last and the first element as well
    if (nums[n - 1] > nums[0])
        count++;

    return count <= 1;
}

int main()
{

    return 0;
}