// Author : Yash Deshpande
// Date : 22-03-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;


// Fuction to print the size of the array 
void fun0(int arr[])
{
    cout<<"Size of "<<sizeof(arr)/sizeof(int)<<endl;
}
/*
Note : This will give a warning: sizeof(arr) = size of the integer pointer array
*/


// function -1 to print all the array elements taken as a parameter
void fun1 (int arr[],int n)                // arr[] is a pointer to the array
{                                          // Array is passed by address
    for(int i=0; i<n; i++)                 // Array size (n) is passed by value
    {
        cout<<"Array element "<<i<<" is "<<arr[i]<<endl;
    }
}

// function -2 to modify array elements taken as parameter
void fun2 (int *arr, int n)                 // *arr is a pointer to the array
{
    arr[2] = 25;
}

int main()
{
    int my_arr[5] = {12,43,5,0,2};

    cout<<"Before calling fun2()"<<endl;
    fun1(my_arr,5);  // to print initil value of all elements


    fun2(my_arr,5);   // to modify array element 
    cout<<endl<<"After calling fun2()"<<endl;
    fun1(my_arr,5);


    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Don't mention the size of the array during function definition / prototype.

2. Provide the array size as a seperate parameter to the function

3. Arrays as function parameters can only be "passed by address" thus array elements can be modified by the function
   to which it is passed as a parameter.

4. Methods to define a pointer to an array :
    1. void func (int arr[], size)      -> pointer definition of an array type pointer
    2. void func (int *arr, size)       -> pointer definition of any type of pointer

    Note : Method -1 is specifically for pointer to arrays

5. for(a: arr)           //arr is a pointer to some array defined in main()
    cout<<a<<endl;    --> A foreach loop cannot work on pointers & will give errors
*/