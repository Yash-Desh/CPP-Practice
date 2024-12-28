// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Love Babbar
// Platform : -

/*

Points to note before solving the qs

1. what is a sorted rotated array ?
eg array = [1,5,2,3,8,14,6]
sorted array -> [1,2,3,5,6,8,14]
sorted rotated array -> [6,8,14,1,2,3,5,6]

2. what is the pivot element of such an array?
As per gfg
For a sorted (in increasing order) and 
rotated array, the pivot element is the only 
element for which the next element to it is 
smaller than it.
thus in given example : 14

As per LB even smallest value in the array
in this case : 1  , can be the pivot

Either of the elements 1 / 14 can be considered
as pivot & can be found using binary search

following code is to find such a pivot 
we consider 1 as the pivot

*/

#include <bits/stdc++.h>
using namespace std;

// Brute-force Approach-1 : 
// Linear search for the min element 
// TC : O(n)



// Optimal Approach 
// Binary Search
// Time : O(log n)
// case - 1 : considering the min element as the pivot 

int getPivot (int arr[], int n)
{
    int l=0, h=n-1;
    int mid;
     while(l < h)
    {
        mid = l + (h-l)/2;
        if(arr[mid] >= arr[0])
        {
            l = mid+1;
        }
        else // if(arr[mid] < arr[n-1])
        {
            h = mid;
        }
    }
    // return the index of the pivot
    // l & h both point at the same index
    // hence any of the 2 can be returned
    return l;
}



// case - 2 : Considering the max element as the pivot
int pivotElementMax (int arr[], int size)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low < high)
    {
        mid = low + (high-low)/2;

        if(arr[mid] < arr[size-1])
        {
            high = mid-1;
        }
        else
        {
            low = mid;
        }
    }
    // return the index of the pivot
    // low & high both point at the same index
    // hence any of the 2 can be returned
    return low;
    
}

int main()
{
    int arr []= {7,8,9,1,3,4};
    cout<<getPivot(arr, 6)<<endl;
    cout<<pivotElementMax(arr, 6)<<endl;
    return 0;
}