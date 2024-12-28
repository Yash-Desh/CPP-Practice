// Author : Yash Deshpande
// Date : 08-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// My Approach, TLE
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

// Another : My Approach
// AC
// TC : O(M*log(N)) ... if matrix has M rows & N columns
// SC : O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        // Apply Binary Search to each row individually
        int low, high, mid;
        low = 0;
        high = matrix[0].size() - 1;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (matrix[i][mid] == target)
                return true;

            else if (matrix[i][mid] > target)
                high = mid - 1;

            else
                low = mid + 1;
        }
    }
    return false;
}

// Optimal Approach
// Babbar Approach
// TC : O(N+M) ...if matrix has M rows & N columns
// SC : O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
            return 1;

        else if (element < target)
            rowIndex++;

        else if (element > target)
            colIndex--;
    }
    return 0;
}

int main()
{

    return 0;
}