// Author : Yash Deshpande
// Date : 22-03-2022
// Tutor : Abdul Bari DSA Course 

// Q. To return an array as return value of a function

#include <iostream>
using namespace std;

// Function that returns an array
int * fun(int n)     // int * -> return type is integer pointer
{                    // n = number of elements in the array i.e size of the array
    int *p;
    p = (int *)malloc(n*sizeof(int));  // Array created in heap memory
    // p = new int [n];
    for(int i= 0; i<n; i++)
    {
        p[i] = i+1;
    }
    return p;
}

int main()
{
    int *A, array_sz = 5;
    A = fun(array_sz);

    for(int j=0; j<array_sz; j++)
    {
        cout<<A[j]<<endl;
    }
    return 0;
}