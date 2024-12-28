// Author : Yash Deshpande
// Date : 15-08-2022
// Tutor : Striver , Love Babbar

// Q. Print all the subsequences of the given array
// NOTE : time = O(n * (2^n))     --> n being the time taken to print the array
//                                --> 2^n being the time to call all functions

//         space = O(n)    --> depending upon the depth of the tracing tree
//                         --> n = number of elements in the array

// The number of subsets of any array of size n = 2^n

#include <bits/stdc++.h>
using namespace std;

void printSubseq(int index, vector<int> &v, int a[], int n) // n = size of array 'a' whose subsequences are to be printed
{                                                           // vector has to be passed by reference. To save space
    if (index >= n)                                         // if you pass by reference then popping the added element is must
    {
        // print the current vector
        for (int num : v)
        {
            cout << num << " ";
        }
        if (v.size() == 0) // when the subsequence is empty
            cout << "{}";
        cout << endl;
        return; // very important to return;
    }

    // // not pick
    // printSubseq (index+1, v, a, n);

    // pick / take a particular index into the subsequence
    v.push_back(a[index]);
    printSubseq(index + 1, v, a, n);
    v.pop_back(); // passed by address

    // not pick / not take a particular index into the subsequence
    printSubseq(index + 1, v, a, n);
}

// ######################################################
// Slightly better written code for the same above method
// ######################################################

void solve(vector<int> &nums, int index, vector<int> &temp, vector<vector<int>> &ans)
{
    // base case
    if (index == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    // select case
    temp.push_back(nums[index]);
    solve(nums, index + 1, temp, ans);

    // not select case
    temp.pop_back();
    solve(nums, index + 1, temp, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;

    solve(nums, index, temp, ans);
    return ans;
}



// ################
// Bit Manipulation
// ################

// vector<vector<int>> subsets(vector<int> &nums)
// {
//     // Bit Manipulation

//     // Initialize the size of the array
//     int size = nums.size();
//     // Initialize the number of subsets that can be formed
//     // = 2^size
//     int subsets = 1 << size;

//     // vector to store ans
//     vector<vector<int>> ans;

//     // for loop to run for all the numbers 
//     // 0 to substets-1
//     for (int i = 0; i < subsets; i++)
//     {
//         // temp vector to store current combination
//         vector<int> temp;

//         // loop to run for each element in the input array
//         for (int j = 0; j < size; j++)
//         {
//             // Check each bit 
//             // if set then add that integer to temp
//             if ((1 << j) & i)
//             {
//                 temp.push_back(nums[j]);
//             }
//         }
//         // store the combination in ans
//         ans.push_back(temp);
//     }
//     // return ans
//     return ans;
// }

int main()
{
    int arr[] = {3, 1, 2};
    vector<int> ls; // empty vector
    printSubseq(0, ls, arr, 3);
    return 0;
}