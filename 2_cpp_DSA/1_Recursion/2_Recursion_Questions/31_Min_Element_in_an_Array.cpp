// Author : Yash Deshpande
// Date : 21-10-2022

// Find the max element in an array
#include <iostream>
using namespace std;

// Approach - 1 : Iterative


// Approach - 2 : Recursive
int maxElement (int arr[], int n)
{
    // base case
    if(n == 1)
        return arr[0];

    int maxi = maxElement(arr+1, n-1);
    return min(maxi , arr[0]);
}


int main()
{
    int arr [] = {12,3,47,7,33,9,17};
    cout<<maxElement(arr, 7)<<endl;
    return 0;
}