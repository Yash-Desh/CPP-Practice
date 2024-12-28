// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Love Babbar
// Platform : Coding Ninjas

#include <bits/stdc++.h>
using namespace std;


// Approach - 1 : Brute Force
// AC
// TC : O(N)
int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    for(int i=0; i<n; i++)
    {
        if(arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}



int main()
{
    
    return 0;
}