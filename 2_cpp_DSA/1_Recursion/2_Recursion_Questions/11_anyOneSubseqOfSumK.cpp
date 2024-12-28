// Author : Yash Deshpande 
// Date : 16-08-2022
// Tutor : Striver

// Q. Print any one of the subsequences of the given array whose sum is K
// NOTE : Implementation of "Technique to print only 1 answer"
//        The boolean logic is only implemented to stop the recursion,
//        once we have got 1 possible ans

// NOTE : This program has the same code as that of the previous code 
//        only with minor modifications

#include <bits/stdc++.h>
using namespace std;

bool printSubseqK (int index, vector <int> v, int sum, int arr[], int n, int k)        // n = size of the array
{
    if(index == n)
    {
        // condition satisfied
        if(sum == k)
        {
            for(int num : v)
            {
                cout<<num<<" ";
            }
            cout<<endl;
            return true;
        }
        // condition not satisfied
        else  
        {
            return false;
        }
    }

    // case - 1 : pick 
    v.push_back(arr[index]);
    sum += arr[index];
    if(printSubseqK(index+1, v, sum, arr, n, k) == true)
        return true;
    v.pop_back();
    sum -= arr[index];

    // case - 2 : not pick
    if(printSubseqK(index+1, v, sum, arr, n, k) == true)
        return true;

    return false;
}


int main()
{
    int a[] = {1,2,1};
    int n = 3;              // n = size of the array
    int k = 2;

    vector <int> ls;
    int sum = 0;            // current sum
    printSubseqK(0, ls, sum, a, n, k);

    return 0;
}