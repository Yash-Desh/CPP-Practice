// Author : Yash Deshpande
// Date : 08-07-2023

#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{

    return 0;
}