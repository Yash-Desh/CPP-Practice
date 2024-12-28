// Author : Yash Deshpande
// Date : 10-10-2022
// Tutor : Abdul Bari, Love Babbar

#include <iostream>
using namespace std;

// // Iterative
// int binarysearch(int arr[], int n, int k)
// {
//     // code here
//     int l =0; 
//     int h = n-1;
//     int mid;

//     while(l <= h)
//     {
//         mid = l + (h-l)/2;
//         if(arr[mid] == k)
//             return mid;

//         else if(arr[mid] > k)
//             h = mid-1;

//         else
//             l = mid+1;
//     }
//     return -1;
// }



// Recursive
int binarysearch(int arr[], int n, int k, int l, int h)
{
    // Base Case
    if(l > h)
        return -1;

    int mid = l + (h-l)/2;
    if(arr[mid] == k)
        return mid;

    else if(arr[mid] > k)
        return binarysearch(arr, n, k, l, mid-1);

    else
        return binarysearch(arr, n, k, mid+1,h);
} 

int main()
{
    int arr[10] = {12,25,45,64,112,150,165,212,403,777};
    cout<<binarysearch(arr,10,777,0,9);
    return 0;
}