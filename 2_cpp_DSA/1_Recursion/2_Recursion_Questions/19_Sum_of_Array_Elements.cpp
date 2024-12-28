// Author : Yash Deshpande
// Date : 11-09-2022
// Tutor : Abdul Bari , Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Recursive
int sumElement(int arr[], int n)
{
    // Your code here
    //  Base Case
    if (n == 0)
        return 0;

    if (n == 1)
        return arr[0];

    return arr[0] + sumElement(arr + 1, n - 1);
}

// Iterative
int sumElement(int arr[], int n)
{
    // Your code here
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int main()
{

    return 0;
}