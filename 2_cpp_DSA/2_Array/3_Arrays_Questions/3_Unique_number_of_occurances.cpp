// Author : Yash Deshpande
// Date : 24-06-2023
// Website : Leetcode
// Tutor : Love Babbar Placement series
// Topic : Arrays

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:

    // My Solution
    bool uniqueOccurrences(vector<int>& arr) {
        map <int, int> m;
        for(int i=0; i<arr.size(); i++)
        {
            m[arr[i]]++;
        }
      
        unordered_set <int> us;
        for(auto it =m.begin(); it != m.end(); it++)
        {
            us.insert(it->second);
        }
        return m.size() == us.size();
    }


    // Solution on the discussions forum
    bool uniqueOccurrences(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        vector <int> ans;
        
        for(int i = 0; i< arr.size(); i++)
        {
            int count = 1;
            if (i < arr.size()-1 && arr[i] == arr[i+1])
            {
                int j=i+1;
                while( j < arr.size() && arr[j] == arr[i])
                {
                    count++;
                    j++;
                }
                i = j-1;
            }
            ans.push_back(count);
        }


        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size()-1; i++)
        {
            if(ans[i] == ans[i+1])
                return false;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}