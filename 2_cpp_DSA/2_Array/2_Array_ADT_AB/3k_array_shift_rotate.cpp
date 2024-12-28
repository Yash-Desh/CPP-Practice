// Author : Yash Deshpande 
// Date : 14-06-2022
// Tutor : Abdul Bari

/*

Student Excercise :
1. left shift
2. left rotate 
3. right shift 
4. right rotate

*/

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

// Left Shift
void left_shift (struct Array *arr)
{
    for(int i=0; i<arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
    // You can also the return the 1st element of the array
}


// Left Rotate 
void left_rotate (struct Array *arr)
{
    int temp = arr->A[0];
    for(int i=0; i<arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    } 
    arr->A[arr->length-1] = temp;
}



// Right shift
void right_shift (struct Array *arr)
{
    for(int i =arr->length-1; i>0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
    // The last element of the array can be returned 
}

// Right Rotate
void right_rotate (struct Array *arr)
{
    int temp = arr->A[arr->length - 1];
    for(int i =arr->length-1; i>0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}

int main()
{
    struct Array my_arr = {{1,2,3,4,17},20,5};
    display(my_arr); 

    cout<<"After left shift"<<endl;
    left_shift(&my_arr);
    display(my_arr);  

    cout<<"After left rotate"<<endl;
    left_rotate(&my_arr);
    display(my_arr);

    cout<<"After right shift"<<endl;
    right_shift(&my_arr);
    display(my_arr);

    cout<<"After right rotate"<<endl;
    right_rotate(&my_arr);
    display(my_arr);

    return 0;
}