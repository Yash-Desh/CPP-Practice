// Author : Yash Deshpande 
// Date : 16-06-2022
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



// Function to find duplicate elements in a sorted array

void duplicateSorted(struct Array arr)
{
    int lastDuplicate = 0;
    cout<<"Duplicate Elements = ";
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != lastDuplicate)
        {
            lastDuplicate = arr.A[i];
            cout<<arr.A[i]<<" ";
        }
    }
}

// function to find the number of duplicate elements in a sorted array

void numDuplicateSorted(struct Array arr)
{
    for(int i = 0; i< arr.length; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            int j = i+1;
            while(arr.A[j] == arr.A[i])
            {
                j++;
            }
            int count = j-i;
            cout<<arr.A[i]<<" is repeated "<<count<<" times"<<endl;
            i = j-1;
        }
    }
}


// function to find the number of duplicate elements in a sorted array using hashing

void duplicateSortedHash (struct Array arr)
{
    int h = max(arr);
    int H[h+1] = {0};
    for(int i=0; i<arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    for(int i=0; i<=h; i++)
    {
        if(H[i] > 1)
        {
            cout<<i<<" is repeated "<<H[i]<<" times"<<endl;
        }
    }
}

int main()
{
    struct Array arr1 = {{3,6,8,8,10,12,15,15,20,20},20,10};
    display(arr1);   

    // duplicateSorted(arr1);

    cout<<endl<<endl;

    numDuplicateSorted(arr1);

    // cout<<endl<<"using hashing"<<endl<<endl;
    // duplicateSortedHash(arr1);



    return 0;
}