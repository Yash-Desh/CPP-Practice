// Author : Yash Deshpande
// Date : 16-08-2022
// Tutor : Striver

// Q. Print count of the subsequences of the given array whose sum is K
// NOTE : Implementation of "Technique to return count"
//        The vector is no longer needed since we wont be printing the vector
//        Only the sum of pic

// NOTE : This program has the same code as that of the previous code
//        only with minor modifications

#include <bits/stdc++.h>
using namespace std;

int printSubseqK(int index, int sum, int arr[], int n, int k) // n = size of the array
{
    // // Optimization strictly only when the array contains all positive elements
    // // condition not satisfied
    // if(sum > k)
    //     return 0;

    if (index == n)
    {
        // condition satisfied
        if (sum == k)
        {
            return 1;
        }
        // condition not satisfied
        else
        {
            return 0;
        }
    }

    // case - 1 : pick

    sum += arr[index];
    int l = printSubseqK(index + 1, sum, arr, n, k);
    sum -= arr[index];

    // case - 2 : not pick
    int r = printSubseqK(index + 1, sum, arr, n, k);

    return l + r;
}

int main()
{
    int a[] = {1, 2, 1};
    int n = 3; // n = size of the array
    int k = 2;

    int sum = 0; // current sum
    cout<<printSubseqK(0, sum, a, n, k)<<endl;

    return 0;
}