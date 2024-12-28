// Author : Yash Deshpande
// Date : 26-07-2023
// Tutor : 450 DSA

#include <bits/stdc++.h>
using namespace std;

// // Method - 1 : Using std::sort()
// // TC : O(N * logN)
// // SC : O(1)
// // Number of comparisons : N * logN
// pair <int, int> maxMin(int arr[], int n)
// {
//     // sort the array
//     sort(arr, arr+n);

//     // create ans pair
//     pair <int,int> ans;
//     ans.first = arr[0];
//     ans.second = arr[n-1];

//     return ans;
// }


// // Method - 2 : Linear Search
// // TC : O(N)
// // SC : O(1)
// // Number of comparisons : 2 * (N-1);
// pair <int, int> maxMin(int arr[], int n)
// {
//     int min = arr[0];
//     int max = arr[0];
//     for(int i=1; i<n; i++)
//     {
//         if(arr[i]<min)
//         {
//             min = arr[i];
//         }
//         else if (arr[i] > max)
//         {
//             max = arr[i];
//         } 
//     }
//     pair <int, int> ans = {min, max};
//     return ans;
// }



// Method - 3 : comparing in pairs (Optimal Approach)
// TC : O(N)
// SC : O(1)
// Number of comparisons : 
// N -> Odd : 3*(n-1)/2 
// N -> Even : 3n/2 -2
pair <int, int> maxMin(int arr[], int n)
{
    int min, max, i;
    // if n is odd
    if(n%2 != 0)
    {
        min = arr[0];
        max = arr[0];
        // Set the starting index for loop
        i = 1;
    }
    else  // if n is even
    {
        if(arr[0] > arr[1])
        {
            min = arr[1];
            max = arr[0];
        }
        else
        {
            min = arr[0];
            max = arr[1];
        }
        // Set the starting index for loop
        i = 2;
    }

    // for the rest of the numbers
    for(; i<n; i+=2)
    {
        if(arr[i] > arr[i+1])
        {
            if(max < arr[i])
                max = arr[i];

            else if(min > arr[i+1])
                min = arr[i+1];
        }

        else
        {
            if(max < arr[i+1])
                max = arr[i+1] ;

            else if(min > arr[i])
                min = arr[i];
        }
    }

    pair <int, int> ans = {min, max};
    return ans;
}





int main()
{
    int arr[10] = {12, 43, 76, 54, 2, -9, -54, 10,8, 97};
    pair <int, int> display = maxMin(arr, 10);
    cout<<display.first<<" "<<display.second<<endl;


    return 0;
}