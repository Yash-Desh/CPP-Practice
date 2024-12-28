// Author : Yash Deshpande
// Date : 20-07-2023
// Tutor : Love Babbar Weekly Contest - 3

#include <bits/stdc++.h>
using namespace std;

// My Approach : Brute Force
// TC : O(N*logN)
int rakshaBandhan(vector<int> arr, int n)
{
    // Write your code here.

    // sort the array
    sort(arr.begin(), arr.end());

    int count = 0;
    long long int sum = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (sum + arr[i] > 0)
        {
            sum += arr[i];
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main()
{

    return 0;
}