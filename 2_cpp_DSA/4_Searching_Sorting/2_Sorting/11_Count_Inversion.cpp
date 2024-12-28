// Author : Yash Deshpande
// Date : 14-09-2022
// Tutor : Love Babbar  ,  Striver

#include <iostream>
using namespace std;

// Brute Force : TLE
// TC = O(n^2)
// SC = O(1)

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long cnt = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

// Optimal Approach : Merge Sort
// Merge Sort
// TC = O(N*LogN)
// SC = O(N)
long long merge(long long *arr, long long l, long long h)
{
    long long mid = l + (h - l) / 2;
    long long inv_cnt = 0;

    // find len
    long long len1 = mid - l + 1;
    long long len2 = h - mid;

    // create & store arrays
    long long *first = new long long[len1];
    long long *second = new long long[len2];

    long long k = l;
    for (long long i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (long long i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge 2 sorted arrays
    long long j1 = 0, j2 = 0;
    k = l;
    while (j1 < len1 && j2 < len2)
    {
        if (first[j1] <= second[j2])
            arr[k++] = first[j1++];

        else
        {
            arr[k++] = second[j2++];
            inv_cnt = inv_cnt + len1 - j1;
        }
    }

    // copy the remaining elements
    while (j1 < len1)
        arr[k++] = first[j1++];

    while (j2 < len2)
        arr[k++] = second[j2++];

    // delete
    delete[] first;
    delete[] second;

    // return inversion count
    return inv_cnt;
}
long long mergeSort(long long arr[], long long l, long long h)
{
    // Base Case
    if (l < h)
    {
        // recursive
        long long inv_cnt = 0;
        long long mid = l + (h - l) / 2;

        // sort left half
        inv_cnt += mergeSort(arr, l, mid);

        // sort right half
        inv_cnt += mergeSort(arr, mid + 1, h);

        // merge sorted arrays
        inv_cnt += merge(arr, l, h);

        return inv_cnt;
    }
    return 0;
}

// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr, 0, N - 1);
}

int main()
{

    return 0;
}
