// Author : Yash Deshpande
// Date : 26-08-2022
// Tutor : Love Babbar
// Platform : Coding Ninjas

#include <bits/stdc++.h>
using namespace std;


// My Approach-1: Linear Search
// Use 2 loops 
// Traverse the array from the front to find the 1st occurence
// Traverse the array from behind to find the last occurence

// My Approach : Using Linear Search
// TC : O(n)

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair <int, int> ans = {-1,-1};
    for(int i=0; i<n; i++)
    {
        if(arr[i]==k)
        {
            int j=i+1;
            while(j != n && arr[j] == k)
            {
                j++;
            }
            ans.first = i;
            ans.second = j-1;
            break;
        }
    }
    return ans;
}



// Best Approach : Using Binary Search
// TC : O(logn)

// function to find the first occurence of k 
// function to find the left-most occurence of k 
int firstOcc(vector<int>& arr, int n, int k)
{
    int l=0;
    int h=n-1;
    int mid, ans=-1;
    while(l <= h)
    {
        mid= (l+h)/2;
        
        if(arr[mid] == k)
        {
            ans = mid;
            h = mid-1;
        }

        else if(arr[mid] < k)
        {
            l = mid + 1;
        }

        else if(arr[mid] > k)
        {
            h = mid-1;
        }
    }
    return ans;
}



// function to find the last occurence of k 
// function to find the right-most occurence of k 
int lastOcc(vector<int>& arr, int n, int k)
{
    int l=0;
    int h=n-1;
    int mid, ans=-1;
    while(l <= h)
    {
        mid= (l+h)/2;
        
        if(arr[mid] == k)
        {
            ans = mid;
            l = mid+1;
        }

        else if(arr[mid] < k)
        {
            l = mid + 1;
        }

        else if(arr[mid] > k)
        {
            h = mid-1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair <int, int> p;
    p.first=firstOcc(arr,n,k);
    p.second=lastOcc(arr,n,k);
    return p;
}




// Recursive Approach : Binary Search
// TC : O(Log(N))
int firstPosition (vector<int> &arr, int l, int h, int k, int ans)
{
    // Base Condition
    if(l > h)
        return ans;
    
    int mid = l + (h-l)/2;
    
    if(arr[mid] >= k)
    {
        if(arr[mid] == k)
            ans = mid;
        return firstPosition(arr, l, mid-1, k, ans);
    }
    else
    {
        return firstPosition(arr, mid+1, h, k, ans);
    }
}

int lastPosition (vector<int> &arr, int l, int h, int k, int ans)
{
    // Base Condition
    if(l > h)
        return ans;
    
    int mid = l + (h-l)/2;
    
    if(arr[mid] <= k)
    {
        if(arr[mid] == k)
            ans = mid;
        return lastPosition(arr, mid+1,h, k, ans);
    }
    else
    {
        return lastPosition(arr, l, mid-1, k, ans);
    }
}



pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> ans;
    int l = 0;
    int h = n-1;
    ans.first = firstPosition(arr,l, h, k, -1);
    ans.second = lastPosition(arr,l, h, k, -1);
    return ans;
}

int main()
{
    vector<int> a = {1,2,2,2,4};
    cout<<firstOcc(a,5,2)<<endl;
     cout<<lastOcc(a,5,2)<<endl;
    return 0;
}