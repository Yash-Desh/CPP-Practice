// Author : Yash Deshpande
// Date : 13-09-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach-1 : Less Memory Efficient
// TC = O(N*LogN)
// SC = O(N)

// Helper Function to merge 2 sorted arrays
void merge2Sorted(int arr[], int s, int e)
{
    int mid  = (s+e)/2;

    // copy the 2 arrays separately
    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for(int i=0; i<len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0; i<len2; i++)
    {
        second[i] = arr[k++];
    }


    // merge 2 sorted arrays
    k=s;
    int j1 =0, j2 =0;
    while(j1 < len1 && j2 < len2)
    {
        if(first[j1] < second[j2])
            arr[k++] = first[j1++];

        else
            arr[k++] = second[j2++];
    }

    // Copy the remaining elements
    while(j1 < len1)
    {
        arr[k++] = first[j1++];
    }

    while(j2 < len2)
    {
        arr[k++] = second[j2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e)
{
    // Base Case
    if(s >= e)
        return;

    // Recursive 
    int mid = (s+e)/2;

    // Sort the left part
    mergeSort(arr, s, mid);

    // Sort the right part
    mergeSort(arr, mid+1, e);

    // merge the 2 arrays
    merge2Sorted (arr, s, e);
}





// Approach-2 : Memory Efficient
// In-place merge sort algorithm

void merge(vector < int > & arr, int n, int start, int end)
{
    int mid = start +(end-start)/2;

    // Two pointers to maintain start
    // of both arrays to merge 
    int k1 = start;
    int k2 = mid+1;
    while(k1 <= mid && k2 <= end)
    {
        // If element 1 is in right place
        if(arr[k1] <= arr[k2])
        {
            k1++;
        }
        else{
            int value = arr[k2];
            int index = k2;
            // Shift all the elements between element 1
            // element 2, right by 1.
            while(index >= 0 && index != k1)
            {
                arr[index] = arr[index-1];
                index--;
            }
            arr[index] = value;

            // Update all the pointers
            k1++;
            k2++;
            mid++;
        }
    }
}


void solve(vector < int > & arr, int n, int start, int end)
{
    // Base Case
    if(start >= end){
        return;
    }
    
    int mid = start +(end-start)/2;
    // merge sort the left part
    solve(arr, n, start, mid);
    // merge sort the right part
    solve(arr, n, mid+1, end);
    // merge 2 sorted arrays
    merge(arr, n, start, end);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    int first = 0;
    int last = n-1;
    solve(arr, n, first, last);
}



















int main()
{
    int arr[] = {12,4,4,4,56,1,9,13,44,44,17};
    mergeSort(arr, 0, 10);
    for(int x : arr)
    {
        cout<<x<<" ";
    }
    return 0;
}