// Author : Yash Deshpande 
// Date : 18-08-2022
// Tutor : Striver

// This is a solution to a problem on GFG with the name: "subset sums"

#include <bits/stdc++.h>
using namespace std;

void sums (int ind, int sum, vector <int>&ans, vector <int> & arr, int N)
{
    // Base case
    if(ind == N)
    {
        ans.push_back(sum);
        return;
    }

    // pick
    sums(ind+1, sum+arr[ind], ans, arr, N);

    // not pick
    sums(ind+1, sum, ans, arr, N);
}

vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector <int> ans;
        sums(0, 0, ans, arr, N);
        sort(ans.begin(), ans.end());
        return ans;
    }

int main()
{
    
    return 0;
}
