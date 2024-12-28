// Author : Yash Deshpande
// Date : 15-09-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Iterative
void insertionSort(int n, vector<int> &arr)
{
    // Write your code here.
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // end inner loop
                break;
            }
        }
        arr[j + 1] = temp;
    }
}



// // Approach - 2 : Recursive (Tail Recursion)
// void insertionSort(int arr[], int index,int n)
// {
//     // Base Case
//     if(index == n)
//         return;

//     // Processing
//     int i = index; 
//     int key = arr[i];
//     while(i>0 && arr[i-1] > key)
//     {
//         arr[i] = arr[i-1];
//         i--;
//     }
//     arr[i] = key;    

//     // recursive call
//     insertionSort(arr, index+1, n);
// }


// // Approach - 3 : Head Recursion
// void insertionSort(int n, vector<int> &arr){
//     // Write your code here.
//     // Base Case
//     if(n == 1)
//         return;
    
//     insertionSort(n-1, arr);
//     int temp = arr[n-1];
//     int j = n-2;
//     while(j >= 0 && arr[j] > temp)
//     {
//         arr[j+1] = arr[j];
//         j--;
//     }
//     arr[j+1] = temp;
// }

int main()
{
    int arr [] = {5,4,3,77,77,11,11,11,2,1};
    // insertionSort(arr, 1, 10);
    for(int i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}