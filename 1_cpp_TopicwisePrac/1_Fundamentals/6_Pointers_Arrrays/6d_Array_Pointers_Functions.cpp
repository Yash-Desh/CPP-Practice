// Author : Yash Deshpande
// Date : 07-09-2022
// Tutor : Love Babbar


//************************************************DISCLAIMER********************************************
// Make sure you hv revised "Pointer_Basics.cpp" , "Arrays_Basics.cpp" & "Arrays_and_Pointers"
// before reading this file 
//******************************************************************************************************


#include <bits/stdc++.h>
using namespace std;

// NOTE : Pointers are passed to the function by value 

// print()
void print (int *p1)
{
    // Run both the cases individually

    // print the address
    cout<<p1<<endl;         // 0x61fec8

    // print the value
    cout<<*p1<<endl;        // 5
}


// update()
void update (int *p2)
{
    // // case-1 : NO CHANGE 
    // p2 = p2 +1;

    // case - 2 : CHANGE
    *p2 = *p2 + 1;
}


// NOTE : when an array is passed by address 
//        only the pointer to the first element
//        is passed to the function

// printSize()
void printSize(int arr[])
{
    // This line will give a warning
    // It will print the size of 
    // int* type pointer of size = 4
    cout<<"Inside function : sizeof(arr) = "<<sizeof(arr)<<endl;              // 4 
}


// getSum()
int getSum (int *arr, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return sum;
}


int main()
{
    // Pointers & Function 

    // // print()
    // int value = 5;
    // int *ptr = &value;
    // print(ptr);


    // update()
    int value = 15;
    int *ptr = &value;


    // before 
    cout<<endl<<"Before"<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    update(ptr);

    // After
    cout<<endl<<"After"<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<value<<endl;


    // Arrays & Functions

    // // printSize()
    // int arr [5] = {1,2,3,4,5};
    // cout<<"Outside function : sizeof(arr) = "<<sizeof(arr)<<endl;   // 20
    // printSize(arr);                                                    // 4


    // getSum()
    // NOTE : Pass only the required portion of the array to
    //        the function
    
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    // Print the sum of all elements 
    cout<<"Sum of all elements = "<<getSum(arr, 10)<<endl;
    
    // Print the sum of the last 5 elements only
    cout<<"Sum of last 5 elements = "<<getSum(arr+5, 5)<<endl;


    return 0;
}