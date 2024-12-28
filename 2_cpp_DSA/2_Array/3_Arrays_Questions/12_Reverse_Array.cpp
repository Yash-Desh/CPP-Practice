// Author : Yash Deshpande
// Date : 01-07-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    // Write your code here.
    int high, low;

    // For reversing after the mth array index
    low = m + 1;
    high = arr.size() - 1;

    // // For reversing the whole array
    // low = 0;
    // high = arr.size() - 1;

    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

int main()
{

    return 0;
}