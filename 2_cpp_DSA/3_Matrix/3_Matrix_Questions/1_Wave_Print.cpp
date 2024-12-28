// Author : Yash Deshpande
// Date : 07-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// My Approach
// AC
// TC : O(N^2)
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    // Write your code here

    // create a vector to store the answer
    vector<int> ans;

    // loop to iterate through the columns
    for (int j = 0; j < mCols; j++)
    {
        // loop to iterate through the row top to bottom
        for (int i = 0; i < nRows; i++)
        {
            ans.push_back(arr[i][j]);
        }
        j++;

        // check if the column exists
        if (j < mCols)
        {
            // loop to iterate through the row bottom to top
            for (int i = nRows - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
}




// Babbar Approach
// TC : O(N^2)
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    // Write your code here
    vector<int> ans;
    for (int col = 0; col < mCols; col++)
    {
        if (col & 1)
        {
            // odd index -> bottom to top
            for (int row = nRows - 1; row >= 0; row--)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else
        {
            // even index -> top to bottom
            for (int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}