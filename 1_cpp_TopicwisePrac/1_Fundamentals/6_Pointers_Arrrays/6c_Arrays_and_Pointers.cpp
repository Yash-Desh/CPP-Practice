// Author : Yash Deshpande
// Date : 24-01-2022
// Tutor : Code With Harry , Abdul Bari , Love Babbar

// Arrays & pointers 

//************************************************DISCLAIMER********************************************
// Make sure you hv revised "Pointer_Basics.cpp" & "Arrays_Basics.cpp" before reading this file 
//******************************************************************************************************

#include <iostream>
using namespace std;


int main()
{
    // // Pointers and arrays


    // int marks [4] = {18,16,20,15};
    
    // // Notice no '&' symbol is used here
    // int* p = marks;      // Initializes p to the very first memory location of the array 

    // int *r = &marks[0];  // initializies r to the first memory location of the array marks 

    // cout<<"The address of the 1st memory location of the array is "<<marks<<endl;           // 0x7fffe7c5d1d0
    // cout<<"The address of the 1st memory location of the array is "<<p<<endl;               // 0x7fffe7c5d1d0
    // cout<<"The address of the 1st memory location of the array is "<<&marks[0]<<endl;       // 0x7fffe7c5d1d0
    // cout<<"The address of the 1st memory location of the array is "<<&marks<<endl;          // 0x7fffe7c5d1d0

    // // Accessing array elements using pointer
    // for(int i = 0; i<4; i++)
    // {
    //     cout<<p[i]<<endl;   // Pointer can act as the name of the array
    // }
    // cout<<endl;
    

    // // NOTE : arr[i] <==> *(arr+i) <==> i[arr]  
    
    // int arr[] = {1,22,31,47,64,82,12,7};
    // cout<<3[arr]<<endl;     // 47
    // cout<<arr[3]<<endl;     // 47
    // cout<<*(arr+3)<<endl;   // 47
    


    // // *****Pointer arithmetic*****
    
    // cout<<*marks<<endl; // prints the value of marks[0]
    // cout<<*(marks+3)<<endl;

    // Method - 1 : To access array elements using pointers 
    // int marks [4] = {18,16,20,15};
    // int* p = marks;
    // cout<<*(p++)<<endl; // prints the value of marks[0]
    // cout<<*(++p)<<endl; // prints the value of marks[2]
    
    
    
    // // Method - 2 : To access array elements using pointers
    // int *q = marks;
    // cout<<"The value of *q is "<<*q<<endl;
    // cout<<"The value of *(q+1) is "<<*(q+1)<<endl;
    // cout<<"The value of *(q+2) is "<<*(q+2)<<endl;
    // cout<<"The value of *(q+3) is "<<*(q+3)<<endl<<endl; 

    
    // // Method - 3 : To access array elements using pointers 
    // cout<<"The value of q[0] is "<<q[0]<<endl;
    // q[0] =  2500;
    // cout<<"The new value of q[0] is "<<q[0]<<endl;
    // cout<<"The value of q[1] is "<<q[1]<<endl;


    
    // Differences between Arrays & Pointers

    // // 1. sizeof()
    // int arr[10] = {12,234,34,56,84,232,47};
    
    // cout<<sizeof(arr)<<endl;    // 40
    // cout<<sizeof(*arr)<<endl;   // 4 - size of an integer
    // cout<<sizeof(&arr)<<endl;   // 4 - size of a pointer
    
    // int *ptr = arr;
    // cout<<sizeof(ptr)<<endl;    // 4 - size of a pointer
    // cout<<sizeof(*ptr)<<endl;   // 4 - size of an integer
    // cout<<sizeof(&ptr)<<endl;   // 4 - size of a pointer

    // // 2. & operator
    // int arr[20] = {1,3,4,5,6,12,7};

    // cout<<arr<<endl;
    // cout<<&arr<<endl;
    // cout<<&arr[0]<<endl;

    // int *p = arr;
    // cout<<p<<endl;
    // cout<<&p<<endl;


    // // 3. Contents of Symbol table are immutable
    // int arr[] = {1,2,3,4,5};
    // // arr = arr+1;  --> ERROR 
    
    // // Pointers can be modified but not the 
    // // name of the array 
    // cout<<*arr<<endl;

    // NOTE : What is a symbol table ?
    //        It maintains a mapping of all variables
    //        pointers etc to their addresses



    // // Playing with pointers
    // int arr [10] ={5,6,8,15,63,96,12,37,99,42};
    // cout<<arr<<endl;                        // 0x61fe98
    // cout<<*arr<<endl;                       // 5
    // cout<<*arr+1<<endl;                     // 6
    // cout<<*(arr+1)<<endl;                   // 6
    // cout<<*(arr)+1<<endl;                   // 6

    
    
    // Pointers to "Char" arrays 
    
    // NOTE : Implementation of int arrays & char arrays is 
    //        different 
    //        it prints the entire char array till
    //        it encounters a terminator '\0'
    

    // the '\0' is inserted automatically
    char ch[6] = "abcde";
    cout<<ch<<endl;                         // abcde

    char *c = &ch[0];
    // prints the entire char array
    cout<<c<<endl<<endl;                    // abcde

    char ch2 = 'a';
    char *ptr = &ch2;
    cout<<*ptr<<endl;                       // a
    cout<<ptr<<endl;                        // Prints some garbage value
    // This is because of how char
    // pointers are implemented 
    // To print all characters till
    // it encounters a terminator '\0'
    



    return 0;
}

/*
##############################################Extra Notes#####################################################

1. An array name acts like a pointer constant. 

2. The value of this pointer constant is the address of the first element.

3. Pointer can act as the name of the array



*/