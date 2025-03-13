// Author : Yash Deshpande
// Date : 06-09-2022
// Website : LeetCode
// Tutor : Love Babbar
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// TC : O(N^2)
void rotateRight(vector<int> &nums)
{
    int store = nums[nums.size() - 1];
    for (int i = nums.size() - 1; i >= 1; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[0] = store;   
}
void rotate(vector<int> &nums, int k)
{
    for (int i = 0; i < k; i++)
    {
        rotateRight(nums);
    }
}


// Better
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp;
    k = k > n ? k % n : k;

    // push_back last k elements into the new array
    for (int i = n - k; i < n; i++)
    {
        temp.push_back(nums[i]);
    }

    // push_back remaining n-k elements into new array
    for (int i = 0; i < n - k; i++)
    {
        temp.push_back(nums[i]);
    }

    // copy back contents of new array
    for (int i = 0; i < n; i++)
    {
        nums[i] = temp[i];
    }
}







// Optimal Approach
// TC : O(N)
// Using the property of modulo "%" symbol
// taking modulo of any number by n returns 
// a result in the range of 0 to n-1;
void rotate(vector<int> &nums, int k)
{
    // Using the property of modulo "%" symbol
    int n = nums.size();

    // store the rotated contents in the temp vector
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }

    // copy contents of temp back to nums
    nums = temp;
}

int main()
{

    return 0;
}