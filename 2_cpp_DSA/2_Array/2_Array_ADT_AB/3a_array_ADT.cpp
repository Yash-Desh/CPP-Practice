// Author : Yash Deshpande 
// Date : 13-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Array 
{
    int *A;
    int size;     // Total elements in the array
    int length;   // Total values initialized in the array
};

void display (struct Array a)
{
    for(int j=0; j<a.length; j++)
    {
        cout<<a.A[j]<<" ";
    }
}

int main()
{
    struct Array arr;
    cout<<"Enter the size of the array : ";
    cin>>arr.size;
    arr.A = new int [arr.size];

    int n;
    cout<<"Enter the number values you wish to initialize : ";
    cin>>n;

    cout<<"Enter the element values : "<<endl;
    for(int i = 0; i<n; i++)
    {
        cin>>arr.A[i];
    }
    arr.length = n;

    display(arr);
    return 0;
}
