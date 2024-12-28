// Author : Yash Deshpande
// Date : 05-09-2022
// Website : LeetCode
// Tutor : Striver
// Topic : Matrix

#include <bits/stdc++.h>
using namespace std;

// Brute Force : TLE
int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.
    vector <int> temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp.push_back(mat[i][j]);
        }
    }
    
    int maxDiff = INT_MIN;
    
    for(int i=0; i<temp.size()-1; i++)
    {
        for(int j=i+1; j<temp.size(); j++)
        {
            if((j/n > i/n) && (j%n > i%n))
                maxDiff = max(maxDiff, temp[j]-temp[i]);
        }
    }
    return maxDiff;
}


// Best Approach
int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.
    int maxVal = INT_MIN;
    
    vector<vector<int>> maxArr( n , vector<int> (n));
    
    // last row 
    maxArr[n-1][n-1] = mat[n-1][n-1];
    for(int j=n-2; j>=0; j--)
    {
        maxArr[n-1][j] = max(mat[n-1][j] , maxArr[n-1][j+1]);
    }
    
    // last column 
    maxArr[n-1][n-1] = mat[n-1][n-1];
    for(int i=n-2; i>=0; i--)
    {
        maxArr[i][n-1] = max(mat[i][n-1] , maxArr[i+1][n-1]);
    }
    
    // process the rest of the matrix
    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-2; j>=0; j--)
        {
            if(maxArr[i+1][j+1] - mat[i][j] > maxVal)
            {
                maxVal = maxArr[i+1][j+1] - mat[i][j];
            }
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j+1], maxArr[i+1][j]));
        }
    }
    
    return maxVal;
}

int main()
{
    
    return 0;
}