// Author : Yash Deshpande 
// Date : 19-04-2022
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

// Linear Search

int LinearSearch (struct Array arr, int key)
{
    int i;
    for(i = 0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;    // Current index returned if search successful
        }
    }
    return -1;  // Invalid index returned if search unsuccessful
}

int main()
{
    struct Array arr = {{1,2,3,4,17},20,5};
    display(arr); 

    int key_index = LinearSearch(arr, 7);
    cout<<"Index of key "<<key_index<<endl;  
    return 0;
}