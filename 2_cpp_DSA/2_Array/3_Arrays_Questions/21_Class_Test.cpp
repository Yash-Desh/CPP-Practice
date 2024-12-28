// Author : Yash Deshpande
// Date : 03-07-2023
// Tutor : Love Babbar Weekly contest - 2

#include <bits/stdc++.h>
using namespace std;


// My Approach
int classTest(int n, vector<int> &a, int k)
{
    // Write your code here.

    // sort in descending order
    sort(a.begin(), a.end(), greater<int>());

    // return (k-1)th element
    return a[k - 1];
}

int main()
{

    return 0;
}