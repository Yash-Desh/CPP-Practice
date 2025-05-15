// Author : Yash Deshpande
// Date : 19-08-2022
// Website : Coding Ninjas
// Tutor : Love Babbar Placement series
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;

// Brute Approach : Using 2 For loops
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> ds;
                ds.push_back(arr[i]);
                ds.push_back(arr[j]);
                ans.push_back(ds);
            }
        }
    }
    return ans;
}

// Love Babbars Approach
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// Best Approach : 2 pointer approach only if array sorted


// hash map
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int, int> mp;  // value -> index
    vector <int> ans;
    for(int i=0; i<nums.size(); i++)
    {
        int diff = target - nums[i];
        if(mp.find(diff) != mp.end())
        {
            ans.push_back(mp[diff]);
            ans.push_back(i);
            break;
        }
        else
        {
            mp.insert({nums[i], i});
        }
    }
    return ans;
}

int main()
{

    return 0;
}