// Author : Yash Deshpande
// Date : 08-07-2023
// Tutor : Love Babbar, Striver

#include <bits/stdc++.h>
using namespace std;

// My Approach
// TC : O(N^2)
void rotate(vector<vector<int>> &matrix)
{
    vector<int> copy;
    int n = matrix.size();
    int m = matrix[0].size();

    // copy given matrix row-wise in vector
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copy.push_back(matrix[i][j]);
        }
    }

    // copy back the vector elements in required order
    int ind = 0;
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][j] = copy[ind++];
        }
    }
}

// Optimal Approach
// Striver Approach
void rotate(vector<vector<int>> &matrix)
{

    // Transpose the matrix
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row within the transposed matrix
    for (int i = 0; i < matrix.size(); i++)
    {
        int j = 0, k = matrix[i].size() - 1;
        while (j < k)
        {
            swap(matrix[i][j++], matrix[i][k--]);
        }
    }
}

int main()
{

    return 0;
}