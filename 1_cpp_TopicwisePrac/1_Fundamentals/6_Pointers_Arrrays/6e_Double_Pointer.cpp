// Author : Yash Deshpande
// Date : 07-09-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;


// Passing double pointers to a function
// It is a "Pass by Value" Operation


void updateDoublePointer (int **ptr2)
{
    // // Case-1 : NO CHANGE
    // ptr2 = ptr2 + 1;

    // Case-2 : CHANGE
    *ptr2 = *ptr2 +1;

    // // Case-3 : CHANGE
    // **ptr2 = **ptr2 + 1;


}

int main()
{
    // // Pointer to pointer  <==> multi-level pointers
    // int var = 165;
    // int *ptr1   = &var;    // Single Pointer
    // int **ptr2  = &ptr1;   // Double Pointer
    // int ***ptr3 = &ptr2;   // Triple Pointer and so on 
    
    // Value of var
    // cout<<endl<<"Value of var"<<endl;
    // cout<<"var = "<<var<<endl;          // 165
    // cout<<"*ptr1 = "<<*ptr1<<endl;      // 165
    // cout<<"**ptr2 = "<<**ptr2<<endl;    // 165


    // Address of var
    // cout<<endl<<"Address of var"<<endl;     
    // cout<<"&var = "<<&var<<endl;            // 0x61feb8
    // cout<<"ptr1 = "<<ptr1<<endl;              // 0x61feb8
    // cout<<"*ptr2 = "<<*ptr2<<endl;            // 0x61feb8 

    // // Address of ptr1
    // cout<<endl<<"Address of ptr1"<<endl;
    // cout<<"&ptr1 = "<<&ptr1<<endl;               // 0x61feb4
    // cout<<"ptr2 = "<<ptr2<<endl;                 // 0x61feb4
    

    // // Address of ptr2
    // cout<<endl<<"Address of ptr2"<<endl;
    // cout<<"&ptr2 = "<<&ptr2<<endl;               // 0x61feb0


    // Double Pointers & Functions
    // Run all the 3 cases individually
    int var = 175;
    int *ptr1   = &var;    // Single Pointer
    int **ptr2  = &ptr1;   // Double Pointer


    cout<<endl<<"BEFORE"<<endl;
    cout<<"var = "<<var<<endl;
    cout<<"ptr1 = "<<ptr1<<endl;
    cout<<"ptr2 = "<<ptr2<<endl; 

    updateDoublePointer(ptr2);

    cout<<endl<<"AFTER"<<endl;
    cout<<"var = "<<var<<endl;
    cout<<"ptr1 = "<<ptr1<<endl;
    cout<<"ptr2 = "<<ptr2<<endl; 
    
    return 0;
}