// Author : Yash Deshpande 
// Date : 13-04-2022
// Tutor : Abdul Bari

// Student Challenge : Find all the missing elements in an unsorted array

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

int max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

void missedUnsorted (struct Array arr)
{
    int l,h;
    l = min(arr);
    h = max(arr);
    cout<<"Missed Elements = ";

    int H [h+1] = {0};
    for(int i=0; i<arr.length; i++)
    {
        H[arr.A[i]]++;
    }
    for(int i =l; i<=h; i++)
    {
        if(H[i] == 0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    struct Array arr1 = {{3,7,4,9,12,6,1,11,2,10},20,10};
    display(arr1);   

    missedUnsorted(arr1);
    return 0;
}