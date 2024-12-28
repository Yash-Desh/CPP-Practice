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



// Reverse : Method 1 - Reverse Copy using auxillary array
void reverse(struct Array *arr)    // struct passed by address for modification
{
    int *B; 
    B = new int [arr->length];  // Auxillary array must be of the length of the given array
    
    int i,j;
    for(i=arr->length-1, j=0; i>=0; i--,j++) // Loop to copy elements in reverse order in auxillary array
    {
        B[j] = arr->A[i];
    }

    for(i=0; i<arr->length; i++)  // Loop to copy elements from auxillary array back into the original array
    {
        arr->A[i] = B[i];
    }
}


// Reverse : Method 2 - Swap
void reverse2 (struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++,j--)  // swap() can be difined seperately & used 
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}



int main()
{
    struct Array arr = {{1,2,3,4,17},20,5};
    display(arr);   

    reverse(&arr);
    display(arr);

    reverse2(&arr);
    display(arr);


    return 0;
}