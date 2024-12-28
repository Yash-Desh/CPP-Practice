// Author : Yash Deshpande 
// Date : 17-08-2022
// Tutor : Striver

#include <bits/stdc++.h>
using namespace std;


void findCombination (int ind, int target, vector<int> &ds, vector<vector<int>>&ans, vector <int>&candidates)
    {
        // base condition
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        // loop to run when base case not satisfied
        for(int i=ind; i<candidates.size(); i++)
        {
            // for each value in candidates array check
            // if a particular value has already been picked at that index
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }
            // if the value of candidate is greater than required target
            if(candidates[i] > target)
            {
                break;
            }
            ds.push_back(candidates[i]);
            findCombination(i+1,target-candidates[i], ds, ans, candidates);
            ds.pop_back();
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort the given array
        sort(candidates.begin(), candidates.end());
        // ds to store current combination
        vector<int> ds; 
        // 2-d ans vector of vector to return
        vector<vector<int>> ans;    
        findCombination(0,target, ds, ans, candidates);
        return ans;
        
    }

int main()
{
    
    return 0;
}