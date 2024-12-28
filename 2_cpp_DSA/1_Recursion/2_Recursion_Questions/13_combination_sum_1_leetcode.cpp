// Author : Yash Deshpande 
// Date : 16-08-2022
// Tutor : Striver

#include <bits/stdc++.h>
using namespace std;

void findCombination (int index, int target,vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        // Base case
        if(index == candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(ds);     // takes linear time 
            }
            return;
        }
        
        // pick
        if(candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            findCombination(index, (target-candidates[index]), candidates, ds, ans);
            ds.pop_back();
        }
        // not pick
        findCombination(index+1, target, candidates, ds, ans);
    }


int main()
{
    
    return 0;
}