// Author : Yash Deshpande
// Date : 16-07-2023
// Tutor : LB : L-35 (HW)

#include <bits/stdc++.h>
using namespace std;



// Brute Force : TLE
// TC : O(N^2)
// SC : O(1)
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long int ans = 0;
    for (long long int i = 0; i < N; i++)
    {
        for (long long int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[i])
                ans++;
        }
    }
    return ans;
}






// Optimal method : Merge Sort
// TC : O(N*log(N))
// SC : O(N)

long long int merge(long long arr[], long long N, long long start, long long end)
{
    // Initialize the variables mid & counter to store the inversions
    long long mid = start + (end - start) / 2;
    long long invCnt = 0;

    // Determine the length of each half array after it is split
    long long len1 = mid - start + 1;
    long long len2 = end - mid;


    // Create Dynamic array of the determined size
    long long *first = new long long[len1];
    long long *second = new long long[len2];

    // copy the elements into the created arrays 

    // Left half
    int index = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[index++];
    }

    // Right Half
    index = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[index++];
    }

    // merge 2 sorted arrays
    int j1 = 0, j2 = 0;
    index = start;

    while (j1 < len1 && j2 < len2)
    {
        // right portion greater than or equal to
        if (first[j1] <= second[j2])
        {
            arr[index++] = first[j1++];
        }
        else // left portion greater than right part
        {
            arr[index++] = second[j2++];
            invCnt += len1 - j1;
        }
    }

    // Copy the remaining elements
    while (j1 < len1)
    {
        arr[index++] = first[j1++];
    }

    while (j2 < len2)
    {
        arr[index++] = second[j2++];
    }

    // Delete the dynamic arrays
    delete[] first;
    delete[] second;

    return invCnt;
}

long long int solve(long long arr[], long long N, long long start, long long end)
{
    if (start >= end)
    {
        return 0;
    }

    long long int mid, invCnt = 0;
    mid = start + (end - start) / 2;

    invCnt += solve(arr, N, start, mid);

    invCnt += solve(arr, N, mid + 1, end);

    invCnt += merge(arr, N, start, end);

    return invCnt;
}

// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long int start = 0;
    long long int end = N - 1;

    long long ans = solve(arr, N, start, end);
    return ans;
}

int main()
{

    return 0;
}