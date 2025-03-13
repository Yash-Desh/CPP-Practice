// Author : Yash Deshpande
// Date : 19-08-2022
// Website : 
// Tutor : Love Babbar Placement series
// Topic : Arrays

// Q. Swap alternate elements
#include <bits/stdc++.h>
using namespace std;

// function to swap alternate elements

// logic - 1
// void swapAlternates (int arr[], int size)
// {
//     for(int i=0; i<size; i++)
//     {
//         // Only when index is odd swap with the previous index
//         if(i%2 != 0)
//         {
//             swap(arr[i-1], arr[i]);
//         }
//     }
// }


// logic - 2
void swapAlternates (int arr[], int size)
{
    for(int i=0; i<size; i+=2)      // Notice incremented by 2
    {
        if(i+1 < size)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}


// Utility function
void display (int a[], int size)
{
    for(int j=0; j<size; j++)
    {
        cout<<a[j]<<" ";
    }
}

int main()
{
    int n; 
    cout<<"Enter Number of Elements in the Array : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    swapAlternates(arr, n);
    display(arr,n);
    return 0;
}