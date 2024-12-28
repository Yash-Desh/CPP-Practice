// Author : Yash Deshpande
// Date : 24-06-2022
// Website : Leetcode
// Tutor : Love Babbar Placement series
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;

// Approach - 1
// Using hashmaps
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    int hash[nums.size() + 1];
    for (int &num : hash)
    {
        num = 0;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }
    for (int i = 0; i < nums.size() + 1; i++)
    {
        if (hash[i] == 2)
        {
            ans.push_back(i);
        }
    }
    return ans;
}


// Approach - 2
// Optimized time
vector<int> findDuplicates(vector<int> &n)
{
    vector<int> duplicates;

    for (int i = 0; i < n.size(); i++)
    {
        // evaluate index of selected element if array would have been sorted..
        int indexOfElem = abs(n[i]) - 1;

        // negate the element
        n[indexOfElem] = -n[indexOfElem];

        // if this element is positive means double negation had happened which
        // means we editied this element twice.
        if (n[indexOfElem] > 0)
            duplicates.push_back(indexOfElem + 1);
    }
    return duplicates;
}

int main()
{

    return 0;
}