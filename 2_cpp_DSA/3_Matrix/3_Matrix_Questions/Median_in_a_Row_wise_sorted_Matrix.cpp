// Author : Yash Deshpande
// Date : 05-09-2022
// Website : LeetCode
// Tutor : Striver
// Topic : Matrix

#include <bits/stdc++.h>
using namespace std;


// Brute-Force Approach
int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        vector <int> ans;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans[r*c/2];
    }

// Optimal Approach 
int lessThanEqualTo (int cut, vector<vector<int>> &matrix, int r, int c)
    {
        int cnt=0;
        
        // loop to run for all rows
        for(int i=0; i<r ; i++)
        {
            int low = 0;
            int high = c-1;
    
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(matrix[i][mid] <= cut)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            cnt+= low;
        }
        return cnt;
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        
        int l = 1;
        int h = 2000;  // as per given constraint
        int med = r * c / 2;
        int ans =-1; 
        
        while(l <= h)
        {
            int mid = (l+h)/2;
            if(lessThanEqualTo(mid, matrix, r, c) <= med)
            {
                l = mid +1;
            }
            else 
            {
                h = mid-1;
            }
        }
        return l;
    }

int main()
{
    
    return 0;
}