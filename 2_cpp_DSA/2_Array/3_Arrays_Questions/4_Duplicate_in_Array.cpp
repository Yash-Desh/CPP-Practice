// Author : Yash Deshpande
// Date : 19-08-2022
// Website : Coding Ninjas
// Tutor : Love Babbar Placement series
// Topic : Arrays


#include <bits/stdc++.h>
using namespace std;

// My Approach
// int findDuplicate(vector<int> &arr) 
// {
//     // Write your code here
// 	   int sum = 0 ;
//     int size = arr.size();
//     int real_sum = size*(size-1)/2;
//     for(int i=0; i<size; i++)
//     {
//         sum += arr[i];
//     }
//     return sum - real_sum;
// }


// NOTE : Any number when XORed with itself gives zero
//        6^6 = 0
//        15^15 = 0

//        Any number when XORed with 0 gives the number itself



// Babbar Approach
int findDuplicate (vector <int> &arr)
{
    int ans =0;

    // XOR each element of the array 
    for(int i=0; i<arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR all the values from 1 to N-1 
    // This cancels out all the elements in the array
    // Only the repeated element will remain 
    for(int i=1; i<arr.size(); i++)
    {
        ans = ans ^ i;
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

    int duplicate = findDuplicate(arr);
    cout<<duplicate<<endl;
    return 0;
}