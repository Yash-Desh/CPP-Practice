// Author : Yash Deshpande 
// Date : 16-08-2022
// Tutor : Striver

// Q. Print all the subsequences of the given array whose sum is K

// NOTE : This program has the same code as that of the previous code 
//        only with minor modifications


#include <bits/stdc++.h>
using namespace std;

void printSubseqK (int index, vector <int> v, int sum, int arr[], int n, int k)        // n = size of the array
{
    if(index == n)
    {
        if(sum == k)
        {
            for(int num : v)
            {
                cout<<num<<" ";
            }
            cout<<endl;
        }
        return;                 // very important to return
    }

    // case - 1 : pick 
    v.push_back(arr[index]);
    sum += arr[index];
    printSubseqK(index+1, v, sum, arr, n, k);
    v.pop_back();
    sum -= arr[index];

    // case - 2 : not pick
    printSubseqK(index+1, v, sum, arr, n, k);
}


int main()
{
    int a[] = {1,2,1,1,1};
    int n = 5;              // n = size of the array
    int k = 2;

    vector <int> ls;
    int sum = 0;            // current sum
    printSubseqK(0, ls, sum, a, n, k);

    return 0;
}