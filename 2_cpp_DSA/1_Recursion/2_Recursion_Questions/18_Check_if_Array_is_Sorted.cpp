// Author : Yash Deshpande
// Date : 11-09-2022
// Tutor : Abdul Bari , Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Recursive
bool arraySortedOrNot(int arr[], int n)
{
    // code here

    // Base Case
    if (n <= 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    return arraySortedOrNot(arr + 1, n - 1);
}

// Iterative
bool arraySortedOrNot(int arr[], int n)
{
    // code here
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}



int main()
{

    return 0;
}