// Author : Yash Deshpande 
// Date : 13-04-2022
// Tutor : Abdul Bari

#include <iostream> 
using namespace std;

struct Array 
{
    int A[10];
    int size;     // Total elements in the array
    int length;   // Total values initialized in the array
};



void append(struct Array *arr,int x)   // Call by address : modifies the array
{
    if(arr->length < arr->size)   // Condition : if array length < array size to confirm that the array has space 
    {
        arr->A[arr->length] = x;  // appends the array
        arr->length++;            // increments the array length
    }
}



void insert(struct Array *arr, int index, int x)   // Call by address : modifies the array
{
   if(index >= 0 && index <= arr->length)          // Condition : if  index within range of array length 
   {
       for(int i = arr->length; i >index ; i--)
       {
           arr->A[i] = arr->A[i-1];       // Copies the element into the next location in the array
       }
       arr->A[index] = x;       // insert 
       arr->length++;           // increments the array length
   }
}

void display (struct Array a)
{
    cout<<"Displaying array elements : ";
    for(int j=0; j<a.length; j++)
    {
        cout<<a.A[j]<<" ";
    }
    cout<<endl;
}

int main()
{
    struct Array my_arr = {{1,2,3,4,17},10,5};
    display(my_arr);

    // append 
    append(&my_arr, 15);
    display(my_arr);

    // insert
    insert(&my_arr, 0, 45);
    display(my_arr);

    return 0;
}