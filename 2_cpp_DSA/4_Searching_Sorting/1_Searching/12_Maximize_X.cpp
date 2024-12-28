// Author : Yash Deshpande
// Date : 3-09-2022
// Tutor : Love Babbar
// Platform : Coding Ninjas

#include <bits/stdc++.h>
using namespace std;


bool isPossible(int mid, int n, vector<vector<int>> &arr, int B)
{
    int tempSum = 0;
    
    for(int i=0; i<n ; i++)
    {
        for(int j=1; j<=arr[i][0]; j++)
        {
            if(arr[i][j] <= mid)
            {
                tempSum += arr[i][j];
            }
        }
    }
    if(tempSum <= B)
    {
        return 1;
    }
    return 0;
}

int findMaxX(int n, vector<vector<int>> &arr, int B)
{
    //Write your code here.
    
    int maxi = arr[0][1];
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=arr[i][0]; j++)
        {
            maxi = max(maxi, arr[i][j]);
        }
    }
    
    int s = 0;
    int e = maxi;
    int ans=0;
    while (s <= e)
    {
        int mid = s + (e-s)/2;
        if(isPossible(mid, n , arr, B))
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1; 
        }
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {

    }
    return 0;
}