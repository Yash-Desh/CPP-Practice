// Author : Yash Deshpande
// Date : 22-06-2023
// Website : Coding Ninjas
// Tutor : Love Babbar Placement series
// Topic : Arrays

#include <iostream>
using namespace std;


// My Solution 

int findUnique(int *arr, int size)
{
    //Write your code here
    for(int i=0; i<size; i++)
    {
        if(arr[i] != -1 && i != size-1)
        {
            for(int j=i+1; j<size; j++)
            {
                if(arr[j] == arr[i])
                {
                    arr[j] = -1;
                    arr[i] = -1;
                    break;
                }
            }
        }
        if(arr[i] != -1)
            return arr[i];
    }
}


// Love Babbar's Solution
// Using special property of XOR
int findUnique(int *arr, int size)
{
    //Write your code here
    int ans = 0;
    for(int i=0; i<size; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}


int main()
{
    
    return 0;
}