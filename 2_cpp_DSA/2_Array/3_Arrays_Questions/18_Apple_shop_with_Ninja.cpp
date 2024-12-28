// Author : Yash Deshpande
// Date : 02-07-2023
// Tutor : Love Babbar Weekly contest - 1

#include <bits/stdc++.h>
using namespace std;


// Brute Force
// AC
// TC : O(N*log(N))
// SC : O(1)
long long appleAndCoupon(int n, int m, vector<int> arr)
{
    // Write your code here.

    // sort the array
    sort(arr.begin(), arr.end());

    // find sum of all array elemnts
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Remove the (n-m)th element's value
    sum -= arr[n - m];

    // return remaining sum
    return sum;
}

int main()
{

    return 0;
}
