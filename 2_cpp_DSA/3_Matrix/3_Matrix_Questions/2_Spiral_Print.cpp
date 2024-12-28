// Author : Yash Deshpande
// Date : 07-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Babbar Approach
// TC : O(N^2)
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();

    int cnt = 0;
    int total = m * n;

    // Initialize indices
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = m - 1;
    int endingCol = n - 1;

    while (cnt < total)
    {
        // Print starting Row
        for (int index = startingCol; cnt < total && index <= endingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            cnt++;
        }
        startingRow++;

        // print ending column
        for (int index = startingRow; cnt < total && index <= endingRow; index++)
        {
            ans.push_back(matrix[index][endingCol]);
            cnt++;
        }
        endingCol--;

        // print ending row
        for (int index = endingCol; cnt < total && index >= startingCol; index--)
        {
            ans.push_back(matrix[endingRow][index]);
            cnt++;
        }
        endingRow--;

        // print starting column
        for (int index = endingRow; cnt < total && index >= startingRow; index--)
        {
            ans.push_back(matrix[index][startingCol]);
            cnt++;
        }
        startingCol++;
    }

    return ans;
}

int main()
{

    return 0;
}