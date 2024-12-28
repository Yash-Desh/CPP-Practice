// Author : Yash Deshpande
// Date : 25-07-2023
// Tutor : Love Babbar LB : L-42, The Cherno

// ###############################################
// The "const" keyword has several uses
// This code illustrates its use-case in pointers
// To use as const pointer_variable
// Other use-cases of the const word are present at 
// const data_variable : C:\Users\Lenovo\Desktop\Vscode_Files\cpp_files\My_CPP_Practice\1_cpp_TopicwisePrac\1_Fundamentals\1_Variables_DataTypes\1f_constants.cpp
// ###############################################


#include <iostream>
using namespace std;

int main()
{
    // #####################################
    // Const Keyword With Pointer Variables:
    // #####################################

    // // 1. pointer variable points to a constant value
    // int value1 = 15;
    // int value = 79;

    // // normal pointer variable
    // int* ptr1 = &value1;

    // const int* ptr2 = &value1;
    
    // // valid change
    // value1 = 25;

    // // valid change
    // ptr1 = &value;


    // // CTE : Invalid change
    // // *ptr2 = 35;

    // // Valid change
    // ptr2 = &value;
    // cout<<*ptr2<<endl;


    // // Equilvalent declaration
    // int const * ptr3 = &value1;
    // cout<<*ptr3<<endl;




    // // 2. const pointer variable points to non-const value
    // int value2 = 21;
    // int value3 = 98;

    // int *const ptr4 = &value2;

    // // valid change
    // value2 = 23;

    // // valid change
    // *ptr4 = 25;

    // // Invalid change : CTE
    // // ptr4 = &value3;





    // // 3. const pointer variable points to const value
    // int value4 = 56;
    // int value5 = 77;

    // const int *const ptr5 = &value4;
    // cout<<"value4 = "<<value4<<" , ";
    // cout<<"*ptr5 = "<<*ptr5<<endl;
    

    // // Valid Change 
    // value4 = 99;
    // cout<<"value4 = "<<value4<<" , ";
    // cout<<"*ptr5 = "<<*ptr5<<endl;

    // // Invalid Change : CTE
    // // *ptr5 = 39;

    // // Invalid change
    // // ptr5 = &value5;

    
    return 0;
}