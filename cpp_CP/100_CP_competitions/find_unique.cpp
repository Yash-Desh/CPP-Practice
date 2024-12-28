// Author : Yash Deshpande
// Date : 19-08-2022
// Website : Coding Ninjas
// Tutor : Love Babbar Placement series
// Topic : Arrays

#include <iostream>
using namespace std;

// NOTE : Any number when XORed with itself gives zero
//        6^6 = 0
//        15^15 = 0

//        Any number when XORed with 0 gives the number itself


// Best Approach
int findUnique (int *arr, int size)
{
    int result = 0;
    for(int i=0; i<size; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}


// // My Approach
// int findUnique(int *arr, int size)
// {
//     // Write your code here

//     // when given array contains no elements
//     if (size == 0)
//         return 0;

//     // when given array contains only 1 element
//     if (size == 1)
//     {
//         return arr[0];
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] != -1)
//         {
//             // When the unique element is the last element of the array
//             if (i == size - 1)
//             {
//                 return arr[i];
//             }

//             // When unique element is NOT the last element of the array
//             int j;
//             for (j = i + 1; j < size; j++)
//             {
//                 if (arr[j] == arr[i])
//                 {
//                     arr[j] = -1;
//                     break;
//                 }
//             }
//             if (j == size)
//             {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

// Helper function to print the given array
void display(int a[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << a[j] << " ";
    }
}

int main()
{
    // Standard code to take input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = findUnique(arr, n);
    cout<<ans<<endl;
    return 0;
}