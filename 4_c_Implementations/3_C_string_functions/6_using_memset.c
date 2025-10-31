// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : GFG (https://www.geeksforgeeks.org/c/memset-c-example/)

// C program to demonstrate working of memset()
#include <stdio.h>
#include <string.h>

void printArray(int arr[], int n)
{
   for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
}

int main()
{
    int n = 10;
    int arr[n];

    // Fill whole array with 100.
    memset(arr, 10, n*sizeof(arr[0]));          // why does setting it to 10 not work ?
    printf("Array after memset()\n");
    printArray(arr, n);

    return 0;
}