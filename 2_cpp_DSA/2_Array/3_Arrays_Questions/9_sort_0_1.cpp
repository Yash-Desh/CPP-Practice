// Author : Yash Deshpande
// Date : 19-08-2022
// Website : GFG
// Tutor : Love Babbar Placement series
// Topic : Arrays

#include <iostream>
using namespace std;

// Approach -1 counting the number of 0s & 1s
// Array Needs to be traversed twice

// Using built-in sort
// time = O(nlog(n))

// Best Approach : Using 2 pointer algo
// time = O(n) with single traversal
void segregate0and1(int arr[], int n)
{
    // code here

    // 2 pointer approach
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        while (arr[low] == 0)
        {
            low++;
        }

        while (arr[high] == 1)
        {
            high--;
        }

        if (low < high)
            swap(arr[low], arr[high]);
    }
}

int main()
{

    return 0;
}