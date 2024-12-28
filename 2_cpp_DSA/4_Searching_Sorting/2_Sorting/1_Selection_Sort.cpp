// Author : Yash Deshpande
// Date : 15-09-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach -1 : Basic Iterative (Unstable)
// void selectionSort (int arr[], int n)
// {
//     for(int i=0; i<n-1; i++)
//     {
//         int minIndex = i;

//         for(int j=i+1; j<n; j++)
//         {
//             if(arr[j] < arr[minIndex])
//             {
//                 minIndex = j;
//             }
//         }
//         swap(arr[i], arr[minIndex]);
//     }
// }

// Approach - 2 : Stable Iterative
// similar to insertion sort
void selectionSort(vector<int> &arr, int n)
{
    // Write your code here.
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        // Rotation instead of swapping
        if (min != i)
        {
            int store = arr[min];
            for (int k = min; k > i; k--)
            {
                arr[k] = arr[k - 1];
            }
            arr[i] = store;
        }
    }
}

// Approach -3 : Recursive + Iterative
void selectionSort(int arr[], int n)
{
    // Base Case
    if (n <= 1)
        return;

    // Processing is done iteratively
    int minIndex = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] < arr[minIndex])
        {
            minIndex = j;
        }
    }
    swap(arr[0], arr[minIndex]);

    // Recursive Call
    selectionSort(arr + 1, n - 1);
}

// // Approach-4 : Recursive

// // Utility function to find the
// // min element recursively
// int minElement(int arr[],int i ,int j)
// {
//     // Base Case
//     if(i >= j)
//         return i;

//     int k = minElement(arr, i+1, j);

//     return arr[i] > arr[k] ? k : i;

// }

// void selectionSort(int arr[], int n)
// {
//     // Base Case
//     if(n <= 1)
//         return;

//     // Processing
//     int k = minElement(arr, 0, n);

//     // Swap
//     swap(arr[k], arr[0]);

//     selectionSort(arr+1, n-1);
// }

int main()
{
    int arr[] = {5, 4, 3, 71, 9, 7, 77, 7, 2, 1};
    selectionSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}