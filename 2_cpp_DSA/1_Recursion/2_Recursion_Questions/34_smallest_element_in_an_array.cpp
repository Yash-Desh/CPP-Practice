// Author : Yash Deshpande
// Date : 01-02-2023

#include <bits/stdc++.h>
using namespace std;

// ************************** Smallest/Minimum Element **************************

// Approach - 1 : Iterative
int smallest(vector<int> &arr, int n)
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < ans)
            ans = arr[i];
    }
    return ans;
}

// Approach - 2 : Recursive
int smallest(vector<int> &arr, int n)
{
    // Base Case
    if (n == 0)                      
        return INT_MAX;


    // OR
    // if (n == 1)
    //     return arr[0];    

    int value = smallest(arr, n - 1);
    return min(value, arr[n - 1]);
}




int main()
{

    return 0;
}