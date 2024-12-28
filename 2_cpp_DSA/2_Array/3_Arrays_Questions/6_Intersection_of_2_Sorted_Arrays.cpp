// Author : Yash Deshpande
// Date : 19-08-2022
// Website : Coding Ninjas
// Tutor : Love Babbar Placement series
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;

// Brute force
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
//     vector <int> ans ;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             if(arr1[i] == arr2[j])
//             {
//                 ans.push_back(arr1[i]);
//                 arr2[j] = -1;   
//                 break;
//             }
//         }
//     }
// }


// Brute Force + Minor Optimization
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector <int> ans ;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            // minor optimization
            if(arr1[i]< arr2[j])
            {
                break;
            }
            
            if(arr1[i] == arr2[j])
            {
                ans.push_back(arr1[i]);
                arr2[j] = -1;   
                break;
            }
        }
    }
}


// 2-Pointer Approach
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    int i=0, j=0;
    vector <int> ans ;
    while( i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        if(arr1[i] > arr2[j])
        {
            j++;
        }
        if(arr1[i] < arr2[j])
        {
            i++;
        }
    }
    return ans;
}

// Helper function to print the given array
void display(int a[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << a[j] << " ";
    }
}

int main()
{
    // Standard code to take input
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // findArrayIntersection();
    return 0;
}