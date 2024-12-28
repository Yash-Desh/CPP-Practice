// Author : Yash Deshpande
// Date : 02-07-2023
// Tutor : Love Babbar Weekly contest - 1

#include <bits/stdc++.h>
using namespace std;


// Binary Search
// 

bool isPossible(int n, vector<vector<int>> &arr, int B, int maxX)
{
    int tempSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= arr[i][0]; j++)
        {
            if (arr[i][j] <= maxX)
            {
                tempSum += arr[i][j];
            }
        }
    }
    if (tempSum <= B)
    {
        return 1;
    }
    return 0;
}

int findMaxX(int n, vector<vector<int>> &arr, int B)
{
    // Write your code here.
    //  Binary Search : Minimize the search space
    int low, mid, high, ans;
    low = 0;
    high = B;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (isPossible(n, arr, B, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}