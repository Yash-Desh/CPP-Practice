// Author : Yash Deshpande
// Date : 01-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// TC : O(N^2)
void moveZeroes(vector<int> &nums)
{
    // Traverse from the back
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        // If you find a zero 0
        if (nums[i] == 0)
        {
            int j = i + 1;
            while (j < nums.size() && nums[j] != 0)
            {
                nums[j - 1] = nums[j];
                j++;
            }
            nums[j - 1] = 0;
        }
    }
}

// Optimal Approach
// Question : Place all zeros to the right
// Solution : Place all non-zero elements to the left
void moveZeroes(vector<int> &nums)
{
    int nonZeroPosition = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[nonZeroPosition], nums[j]);
            nonZeroPosition++;
        }
    }
}

int main()
{

    return 0;
}