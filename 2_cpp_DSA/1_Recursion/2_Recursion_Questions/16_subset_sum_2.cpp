// Author : Yash Deshpande 
// Date : 18-08-2022
// Tutor : Striver

#include <bits/stdc++.h>

void findSubsets (int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums)
    {
        ans.push_back(ds);
        // No base case : when the ind = 6 for a function call
        // the following for loop will not run
        // the control will reach the end of the function &
        // automatically return
        for(int i=ind; i<nums.size(); i++)
        {
            if(i > ind && nums[i] == nums[i-1])
            {
                continue;
            }
            ds.push_back(nums[i]);
            findSubsets(i+1, ds, ans, nums);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0,ds,ans,nums);
        return ans;
    }
using namespace std;

int main()
{
    
    return 0;
}