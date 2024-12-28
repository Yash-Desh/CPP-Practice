// Author : Yash Deshpande
// Date : 02-08-2023
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;

// Optimal Approach
// TC : O(N)
// SC : O(1)

int getMinDiff(int arr[], int n, int k)
{
    // code here
    // sort : adjacent elements with minimum difference
    sort(arr, arr + n);

    // current minimum
    int result = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0){
            continue;
        }
        

        int maxi = max(arr[i - 1] + k, arr[n - 1] - k);
        int mini = min(arr[i] - k, arr[0] + k);
        result = min(result, maxi - mini);
    }
    return result;
}

int main()
{

    return 0;
}