// Author : Yash Deshpande 
// Date : 16-06-2022
// Tutor : Abdul Bari

// Student Challenge : Find single missing element in an sorted array -> Method 1

#include <iostream>
using namespace std;

struct Array 
{
    int A[20];
    int size;     // Total elements in the array
    int length;   // Total values initialized in the array
};


void display (struct Array a)
{
    cout<<"Displaying array elements : ";
    for(int j=0; j<a.length; j++)
    {
        cout<<a.A[j]<<" ";
    }
    cout<<endl;
}

void missedSorted1(struct Array arr)
{
    int sum = 0;
    for(int i=0; i<arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    int n = arr.A[arr.length-1];   // n = last & largest element in the array 
    int s = ((n) * (n+1)) / 2;
    cout<<"Missing Element = "<<s-sum<<endl;
}

int main()
{
    struct Array arr1 = {{1,2,3,4,5,6,8,9,10},20,9};
    display(arr1);   

    missedSorted1(arr1);
    return 0;
}

/*

##############################################Extra Notes#####################################################

This method -1 works only when the array is sorted & it contains the 1st n natural numbers with a single missing
number.

*/ 