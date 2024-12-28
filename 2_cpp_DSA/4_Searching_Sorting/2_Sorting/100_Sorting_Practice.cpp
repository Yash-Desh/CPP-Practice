// Author : Yash Deshpande
// Date : 09-01-2023
// Date : 17-01-2023


// This is a practice site for sorting 
#include <bits/stdc++.h>
using namespace std;

void quickSort (int *arr, int l, int h);

int partition (int arr[], int l, int h);

int main()
{
    int arr[] = {12,4,56,-2,77,35,72,77,90,77};
    quickSort(arr,0,9);

    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

void quickSort(int *arr, int l, int h)
{
    // Base Case
    if(l >= h)
        return;

    // partition
    int p = partition(arr, l,h);

    // quick sort the left part
    quickSort(arr, l,p-1);

    // quick sort the right part
    quickSort(arr,p+1,h);
}

int partition (int *arr, int l, int h)
{
    int pivotIndex = l;

    // count the number of elements smaller 
    // than the 1st element of the given array
    int cnt = 0;
    for(int i=l+1; i<=h; i++)
    {
        if(arr[i] < arr[pivotIndex])
            cnt++;
    }

    pivotIndex = l + cnt;
    swap(arr[pivotIndex], arr[l]);

    while(l < pivotIndex && h > pivotIndex)
    {
        while(arr[l] < arr[pivotIndex])
            l++;

        while(arr[h] >= arr[pivotIndex])
            h--;

        if(l < pivotIndex && h > pivotIndex)
            swap(arr[l], arr[h]);
    }

    return pivotIndex;
}
