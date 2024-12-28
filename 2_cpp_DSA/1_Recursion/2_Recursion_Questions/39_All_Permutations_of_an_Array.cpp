// Author : Yash Deshpande
// Date : 18-07-2023
// Tutor : Striver , Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Method - 1 :
void recurPermute(vector<int> &ds, vector<vector<int>> &ans, int *freq, vector<int> &nums)
{
    // base case
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    // loop to iterate over freq map
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = 1;
            ds.push_back(nums[i]);
            recurPermute(ds, ans, freq, nums);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    // ds to store current combination
    vector<int> ds;

    // vector of vector to store all the combinations
    vector<vector<int>> ans;

    // hash map to store the frequency of each element
    // in the current combination
    int *freq = new int[nums.size()];
    // initialize the freq to zero
    for (int i=0; i<nums.size(); i++)
    {
        freq[i] = 0;
    }

    recurPermute(ds, ans, freq, nums);
    return ans;
}

// Method - 2 : Optimal Approach
void recurPermute(int index, vector<vector<int>> &ans, vector<int> &nums)
{
    // base case
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    // loop to iterate over nums
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, ans, nums);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    // vector of vector to store all the combinations
    vector<vector<int>> ans;

    recurPermute(0, ans, nums);
    return ans;
}

int main()
{

    return 0;
}