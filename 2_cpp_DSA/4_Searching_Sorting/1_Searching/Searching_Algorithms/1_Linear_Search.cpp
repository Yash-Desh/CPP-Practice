// Author : Yash Deshpande
// Date : 11-09-2022
// Tutor : Abdul Bari , Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Case-1 : To return the index if the element is found
//          & -1 if not found


// // Iterative
// int search(int arr[], int N, int X)
// {
//     // Your code here
//     for(int i =0; i<N; i++)
//     {
//         if(arr[i] == X)
//             return i;
//     }
//     return -1;
// }


// //Recursive
// int LinearSearch(int arr[], int N, int X)
//     {
//         // Your code here
        
//         // Base Case
//         if(N == 0)
//             return -1;
            
//         if(arr[N-1] == X)
//             return N-1;
            
//         return LinearSearch(arr, N-1, X);
        
//     }


// Case-2 : To return "true" / "false"

// Iterative
int search(int arr[], int N, int X)
{
    // Your code here
    for(int i =0; i<N; i++)
    {
        if(arr[i] == X)
            return true;
    }
    return false;
}

// Recursive

bool linearSearch (int arr[], int N, int X)
{
    // Base Case
    if(N == 0)
        return false;

    if(arr[0] == X)
        return true;

    return linearSearch(arr+1, N-1, X);
}



// Recursive All-in-one Approach
// return T/F
// return index
int linearSearch (int arr[], int N, int index, int X)
{
    // Base Case : Element not found
    if(index == N)
        return -1;              // return false;

    // Element found
    if (arr[index] == X)
        return index;           // return true;

    return linearSearch(arr, N, index+1, X);
}



int main()
{
    
    return 0;
}