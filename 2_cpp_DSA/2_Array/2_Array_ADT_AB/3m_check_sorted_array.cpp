// Author : Yash Deshpande 
// Date : 14-06-2022
// Tutor : Abdul Bari

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

// Check whether the given array is sorted in ascending
int isSorted(struct Array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}



int main()
{
    struct Array my_arr = {{1,2,3,34,17},20,5};
    display(my_arr);  

    cout<<"Check whether array is sorted : "<<isSorted(my_arr)<<endl; 
    return 0;
}