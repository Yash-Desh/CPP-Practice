// Author : Yash Deshpande
// Date : 24-01-2022

// ###############################################
// The "const" keyword has several uses
// This code illustrates its most basic use-case
// To use as const data_variable
// Other use-cases of the const word are present at 
// const in pointers : C:\Users\Lenovo\Desktop\Vscode_Files\cpp_files\My_CPP_Practice\1_cpp_TopicwisePrac\1_Fundamentals\6_Pointers_Arrrays\6j_const_pointers.cpp
// ###############################################


#include <iostream>
using namespace std;

int main()
{
    int a = 34; 
    cout<<"The value of a was: "<<a<<endl;
    a = 45; 
    cout<<"The value of a is: "<<a<<endl;
    
    // **** Constants in C++ ****

    const int b = 3;
    cout<<"The fixed value of b is : "<<b<<endl;
    
    // b = 45; -->  You will get an error because a is a constant
   
    return 0;
}