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

// Returning a struct pointer

struct Array* merge(struct Array *ar1, struct Array *ar2)
{ 
    int i,j,k;
    i=j=k=0;
    struct Array *ar3 = new struct Array;
    while(i<ar1->length && j<ar2->length)
    {
        if(ar1->A[i] < ar2->A[j])
        {
            ar3->A[k++] = ar1->A[i++];
        }
        else
        {
            ar3->A[k++] = ar2->A[j++];
        }
    }
    for(;i<ar1->length; i++)
        {
            ar3->A[k++] = ar1->A[i];
        }

        for(;j<ar2->length; j++)
        {
            ar3->A[k++] = ar1->A[j];
        }
    ar3->length = ar1->length + ar2->length;
    ar3->size =20;
    return ar3;
}

int main()
{
    struct Array arr1 = {{1,4,4,6,10,15,25},20,7};
    display(arr1);   

    struct Array arr2 = {{3,4,7,18,20},20,5};
    display(arr2);

    // Creating a pointer for the 3rd Array
    struct Array *arr3;
    arr3 = merge(&arr1, &arr2);
    display(*arr3);   // Dereferencing the pointer arr3 for call by value
    
    return 0;
}
/*

##############################################Extra Notes#####################################################

! The executed result is not as expected please check for any errors 




*/