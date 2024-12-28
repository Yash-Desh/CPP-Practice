// Author : Yash Deshpande 
// Date : 13-04-2022
// Tutor : Abdul Bari

// Student Challenge : Find all the missing elements in a sorted array

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

void missedSorted3 (struct Array arr)
{
    int l;
    l = arr.A[0];

    int diff = l;
    cout<<"Missed elements = ";
    for(int i = 0; i<arr.length; i++)
    {
        if(diff != arr.A[i]-i)
        {
            while(diff < arr.A[i]-i)
            {
                cout<<diff + i<<" ";
                diff++;
            }
        }
    }
}

int main()
{
    struct Array arr1 = {{7,8,9,10,11,13,16,17,18},20,9};
    display(arr1);   

    missedSorted3(arr1);
    return 0;
}