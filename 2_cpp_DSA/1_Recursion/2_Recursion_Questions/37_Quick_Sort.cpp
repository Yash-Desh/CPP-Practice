// Author : Yash Deshpande
// Date : 17-09-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Helper function that provides the partition
int partition (int arr[], int s, int e)
{
    int pivot = arr[s];

    // count the no. of elements smaller than
    // the pivot element
    int cnt = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] <= pivot)
            cnt++;
    }

    // Place the pivot at the correct spot
    int pivotIndex = s+cnt;
    
    swap(arr[pivotIndex], arr[s]);

    // Meet the conditions of the partition
    // Elements to the left of pivot < pivot
    // Elements to the right of pivot > pivot

    int i = s;
    int j = e;
    while(i < pivotIndex &&  j > pivotIndex)
    {
        while(arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if (i < pivotIndex &&  j > pivotIndex)
            swap(arr[i], arr[j]);
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // Base Case -> Entire array is sorted
    if(s >= e)
        return;

    // Find the partition
    int p = partition(arr, s, e);

    // Recursive Calls
    // sort the left part
    quickSort(arr, s, p-1);

    // sort the left part
    quickSort(arr, p+1, e);
}

int main()
{
    int arr[] = {9, 9, 9, 8, 2, 3, -6 };
    quickSort(arr, 0, 6);
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}