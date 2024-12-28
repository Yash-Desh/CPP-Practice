// Author : Yash Deshpande
// Date : 08-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// My Approach , AC
// Approach : Brute Force
// Linear Search
// TC : O(N^2)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            // check for the element
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// Optimal Approach
// Babbar Approach
// TC : O(log(M*N)) ... if matrix has M rows & N columns
// SC : O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    // store the number of rows & columns in the matrix
    int row = matrix.size();
    int col = matrix[0].size();

    // initialize the pointers for Binary Search
    int low, mid, high;
    low = 0;
    high = row * col - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int element = matrix[mid / col][mid % col];

        if (element == target)
            return true;

        else if (element > target)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return false;
}

int main()
{

    return 0;
}