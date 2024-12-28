// Author : Yash Deshpande
// Date : 13-09-2022
// Tutor :  Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Approach - 1 : Iterative (Inefficient)
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=0; i<n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}


// Approach - 2 : Iterative(Efficient)
void bubbleSort(vector<int> &arr, int n)
{
    // Write your code here.
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);

                swapped = 1;
            }
        }
        // To prevent excess traversals when the 
        // array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

// Approach - 3 : Recursive
void bubbleSort(int *arr, int n)
{
    // Base Case -> Already Sorted
    if (n <= 1)
    {
        return;
    }

    // Processing :
    // Place the ith largest element in its right place
    // in the ith round
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            swap(arr[i], arr[i - 1]);
    }

    // Recursive Call
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {4, 7, 1, 44, 23, 91, 2};
    bubbleSort(arr, 7);

    for (int i : arr)
        cout << i << " ";
    return 0;
}