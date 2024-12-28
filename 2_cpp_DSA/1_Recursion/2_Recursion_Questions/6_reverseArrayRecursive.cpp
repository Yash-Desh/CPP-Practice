// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Striver

// Q. Reverse the elements in an array recursively

// NOTE : time = O(n/2)   .... n = number of elements in the string
//        space = O(n/2)  


#include <bits/stdc++.h>
using namespace std;

// // 2 pointer Recursive mechanism 
// void rev (int arr[], int l , int h)         // l = lower pointer , h = higher pointer
// {
//     if( l >= h)
//     {
//         return;
//     }
//     swap(arr[l] , arr[h]);
//     rev(arr, l+1, h-1);
// }


// 1 pointer Recursive mechanism 
void rev (int arr[], int l , int n)         // l = lower pointer , n = size of the array
{
    if( l >= n/2)
    {
        return;
    }
    swap(arr[l] , arr[n-1-l]);
    rev(arr, l+1, n);
}



int main()
{
    int a[] =  { 23,4,55,63,91,7};
    rev(a, 0,6 );
    for(int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}