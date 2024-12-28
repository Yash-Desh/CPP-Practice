// Author : Yash Deshpande
// Date : 05-09-2022
// Website : LeetCode
// Tutor : Striver
// Topic : Matrix


#include <bits/stdc++.h>
using namespace std;


// Brute Force
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> temp;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                temp.push_back(Mat[i][j]);
            }
        }
        
        sort(temp.begin(), temp.end());
        int k=0;
        vector<vector<int>> ans;
        for(int i=0; i<N; i++)
        {
            vector<int> row;
            for(int j=0; j<N; j++)
            {
                row.push_back(temp[k++]);
            }
            ans.push_back(row);
        }
        return ans;
    }

int main()
{
    
    return 0;
}