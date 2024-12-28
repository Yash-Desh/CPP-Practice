// Author : Yash Deshpande
// Date : 26-07-2023
// Tutor : 450 DSA

// This question has 2 types
// Type - 1 : Relative order of the elements need not be maintained
// Type - 2 : Relative order of the elements needs be maintained
// Solution to type-1 was covered by Abdul Bari
// This is a solution to type-2
// Try to solve it with minimum extra space 

// ##################################################
// Relative order of the elements needs be maintained
// ##################################################

// for e.g arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
// ans : {1  3  2  11  6  -1  -7  -5}

#include <bits/stdc++.h>
using namespace std;

// My Approach : AC
// Brute Force
// TC : O(N)
// SC : O(N)
void segregateElements(int arr[], int n)
{
    // Your code goes here
    vector<int> positive;
    vector<int> negative;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            positive.push_back(arr[i]);

        else
            negative.push_back(arr[i]);
    }

    int i = 0;
    for (; i < positive.size(); i++)
    {
        arr[i] = positive[i];
    }

    for (; i < positive.size() + negative.size(); i++)
    {
        arr[i] = negative[i - positive.size()];
    }
}

// 2-Pointer + Sliding window Approach
// TLE
// TC : O(N^2)
// SC : O(1)
void Rearrange(int arr[], int n)
{
    // Your code goes here
    // 2-pointer + sliding window
    int i = 0, j = 0;
    while (j < n)
    {
        // if arr[j] is positive
        if (arr[j] < 0)
        {
            int temp = arr[j];
            for (int k = j; k > i; k--)
            {
                arr[k] = arr[k - 1];
            }
            arr[i] = temp;
            i++;
        }
        j++;
    }
}

// Best Approach
// Merge Sort
// TC : O(N * logN)
// SC : O(log N)
void reverse(int arr[], int n, int start, int end)
{
    while (start < end)
    {
        swap(arr[start++], arr[end--]);
    }
}

void merge(int arr[], int n, int start, int end)
{
    int mid = start + (end - start) / 2;

    int i = start;
    int j = mid + 1;

    while (i <= mid && arr[i] < 0)
        i++;

    while (j <= end && arr[j] < 0)
        j++;

    reverse(arr, n, i, mid);
    reverse(arr, n, mid + 1, j - 1);
    reverse(arr, n, i, j - 1);
}

void solve(int arr[], int n, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    solve(arr, n, start, mid);
    solve(arr, n, mid + 1, end);

    merge(arr, n, start, end);
}


void Rearrange(int arr[], int n)
{
    // Your code goes here
    solve(arr, n, 0, n - 1);
}

int main()
{

    return 0;
}