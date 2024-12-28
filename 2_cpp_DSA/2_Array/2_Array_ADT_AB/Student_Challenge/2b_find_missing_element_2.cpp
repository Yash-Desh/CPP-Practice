// Author : Yash Deshpande 
// Date : 13-04-2022
// Tutor : Abdul Bari

// Student Challenge : Find single missing element in an sorted array -> Method 2


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

void missedSorted2 (struct Array arr)
{
    int l = arr.A[0];

    int diff = l;
    for(int i=0; i<arr.length; i++)
    {
        if (diff != arr.A[i]-i)
        {
            cout<<"Missing Element = "<<diff+i<<endl;
            break;
        }
    }
}

int main()
{
    struct Array arr1 = {{3,4,5,6,7,8,9,10,11,13,17},20,11};
    display(arr1);   

    missedSorted2(arr1);
    return 0;
}

/*

##############################################Extra Notes#####################################################

This method is applicable for sorted arrays with any start and end element

*/