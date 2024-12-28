// Author : Yash Deshpande
// Date : 24-01-2022

#include <iostream>
using namespace std;

int main()
{
    // // **** Different ways to declare & initialize arrays in C++ ****


    int marks1 [4] = {18,16,20,15}; // M1 : array size mentioned 
    int marks2 [] = {25,20,21,23};  // M2 : array size not mentioned
    cout<<"Size of marks1 array = "<<sizeof(marks1)<<" bytes"<<endl<<endl;

    // int mathMarks[4];  // M3 : Creating an empty array & initializing each array element separately
    // mathMarks[0] = 2278;
    // mathMarks[1] = 738;
    // mathMarks[2] = 378;
    // mathMarks[3] = 578;

    // // M4 : Initializing an array with less elements than its size

    // int marks3 [10] = {12,34,54,5,23,4};   // size = 10 & length = 6
    // cout<<marks3[7]<<endl; // o/p = 0
    // cout<<marks3[8]<<endl; // o/p = 0

    // // NOTE : All the remaining uninitialized elements will be automatically initialized to zero


    // // Determining the number of elements(size) of an array

    // int new_arr[5] = {23,14,17,27,9};
    // int size = sizeof(new_arr) / sizeof(new_arr[0]);
    // cout<<"Number of elements in new_arr array = "<<size<<endl<<endl;

    // // **** Different ways to print the contents of an array **** 
    
    
    // // printing each element 
    // cout<<"These are math marks"<<endl;
    // cout<<mathMarks[0]<<endl;
    // cout<<mathMarks[1]<<endl;
    // cout<<mathMarks[2]<<endl;
    // cout<<mathMarks[3]<<endl;


    // cout<<endl<<endl;


    // // printing the values of an array using for loop
    // cout<<"Using for loop"<<endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     cout<<"The value of array element "<<i<<" = "<<marks1[i]<<endl;
    // }


    // cout<<endl<<endl;


    // // printing the values of an array using while loop
    // cout<<"Using while loop"<<endl;
    // int i = 0;
    // while ( i < 4)
    // {
    //     cout<<"The value of array element "<<i<<" = "<<marks1[i]<<endl;
    //     i++; 
    // }


    // cout<<endl<<endl;


    // // printing the values of an array using do while loop
    // cout<<"Using do-while loop"<<endl;
    // i = 0;
    // do 
    // {
    //     cout<<"The value of array element "<<i<<" = "<<marks1[i]<<endl;
    //     i++; 
    // }
    // while (i<4);


    // // printing values of an array using foreach loop
    // int arr[] = { 10, 20, 30, 40 };
  
    // // Printing elements of an array using
    // // foreach loop
    // for (int x : arr)
    //     cout << x << endl;

    // // NOTE : foreach loop cannot be used on pointers

    
    // Variable sized array : Creating array of size defined by the user

    // int arr_size ;
    // cout<<"Enter the size of the array :";
    // cin>>arr_size;

    // int var_arr[arr_size];
    // var_arr[7] =15;
    // cout<<var_arr[7]<<endl;


    // // Property : Arrays are mutable & its values can be changed
    // mathMarks[2] = 455;
    // cout<<mathMarks[2]<<endl;






    return 0;
}

/*

##############################################Extra Notes#####################################################

1. An array is a collection of items which are of the similar datatype stored in contiguous memory locations.

2. Array store data in continuous block form in the memory, and array indexes start from 0.

3. We can use loops to print the values of an array, instead of printing them one by one.

4. Arrays are stored in "stack memory".

5. Variable sized arrays cannot be initialized directly upon declaration

*/