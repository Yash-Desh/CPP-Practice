// Author : Yash Deshpande
// Date : 2-09-2022
// Tutor : Love Babbar
// Platform : Coding Ninjas

#include <bits/stdc++.h>
using namespace std;


bool isPossible (int mid , vector<int> &arr, int n, int m)
{
    int studentCnt = 1;
    int pageSum = 0;
    
    for(int i=0; i<n; i++)
    {
        if( pageSum + arr[i] <= mid )
        {
            pageSum += arr[i];
        }
        else
        {
            studentCnt++;
            if(studentCnt > m || arr[i] > mid)
                return 0;
            pageSum = arr[i];
        }
    }
    return 1;
}


int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.

    // Return -1 if the number of books is less than the 
    // number of students
    if(n < m)
        return -1;
    
    // Binary Search : Minimize the search space
    
    // Find the sum of all array values
    // Find total number of pages to be allocated
    int sum =0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }

    int s =0;
    int e = sum;

    // -1 is returned if no possible solution
    int ans=-1;  

    int mid = s + (e-s)/2;
    while(s <= e)
    {
        if(isPossible(mid, arr, n , m))
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
        
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    
    return 0;
}