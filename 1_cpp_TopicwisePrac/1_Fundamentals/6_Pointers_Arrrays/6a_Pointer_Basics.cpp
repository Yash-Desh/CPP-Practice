// Author : Yash Deshpande
// Date : 24-01-2022

#include <iostream>
#include <cstdlib> // for using malloc()
using namespace std;

struct Rectangle
{
   int len;
   int breadth;
};

int main()
{
   // // What is a pointer? ----> Data type which holds the address of other data types

   // int a = 3;   // normal variable declaration & initialization
   // int *b;      // pointer variable declaration
   // b = &a;      // pointer variable initialization
   // int *d = &a; // pointer variable declaration & initialization on the same line

   // // &(ampersand) ---> (Address of) Operator
   // cout << "The address of a is " << &a << endl;
   // cout << "The address of a is " << b << endl
   //      << endl;

   // cout << "The value of a is " << a << endl;
   // // *(asterisk) ---> (value at) Dereference operator
   // cout << "The value at address b is " << *b << endl
   //      << endl;

   // // Declaring non-initialized pointers

   // // NOTE : Declaring pointers without initializing them is a
   // //        bad & dangerous practice
   // //        Hence atleast initialize them with NULL / 0

   // int *ptr = NULL;
   // cout<<ptr<<endl;    // gives segmentation fault

   // // Size of a Pointer

   // int ivar = 5;
   // int *ptrToInt = &ivar;
   // cout<<"Size of integer variable is "<<sizeof(ivar)<<" bytes"<<endl;                        // 4
   // cout<<"Size of pointer to integer variable is "<<sizeof(ptrToInt)<<" bytes"<<endl;         // 4

   // double dvar = 5.678;
   // double *ptrToDouble = &dvar;
   // cout<<"Size of double variable is "<<sizeof(dvar)<<" bytes"<<endl;                           // 8
   // cout<<"Size of pointer to double variable is "<<sizeof(ptrToDouble)<<" bytes"<<endl;         // 4

   // size of a char type pointer
   // char *ptrToChar;
   // cout << sizeof(ptrToChar) << endl;                 // 4

   // // size of a struct type pointer
   // struct Rectangle *ptrToStruct;
   // cout << sizeof(ptrToStruct) << endl;               // 4

   // NOTE : Pointers / Address variables always store address
   //        Size of pointers will be the same irrespective of
   //        what data they point to
   //        Size of pointers varries from system-to-system
   //        It can be 4 bytes or 8 bytes

   // // Value Access Using pointers

   int a = 15;
   int b = a;

   cout << "a before " << a << endl;            // 15
   b++;
   cout << "a after " << a << endl;             // 15

   // int *p = &a;
   // cout << "before " << *p << endl;
   // (*p)++;
   // cout << "after " << *p << endl;

   // // Copying Pointer

   // int var = 50;
   // int *p = &var;
   // int *q = p;

   // cout<<p <<" = "<<q<<endl;
   // cout<<*p<<" = "<<*q<<endl;

   // Pointer arithmetic

   // int var = 100;
   // int *p = &var;

   // cout << "before " << *p << endl;
   // *p = *p + 1;
   // cout << "after " << (*p) << endl;

   // cout << "before " << p << endl;
   // p = p + 1;
   // // Now p does NOT point to the address of the variable 'var'
   // cout << "after " << p << endl;

   // // Accessing Heap memory using a pointer
   // int *p;

   // // Method -1 : Using new keyword
   // p = new int[5];  // Array created in heap memory using dynamic allocation

   // // Method -2 : Using malloc()
   int* ptr = (int*)malloc(sizeof(int)*5);

   return 0;
}

/*

##############################################Extra Notes#####################################################

1. Pointer is an address variable that is meant for storing the address of data, not data itself.

2. A pointer is a data type which holds the address of other data type.

3. The “&” operator is called “address off" operator, and the "*” operator is called “value at” dereference operator.

4. Normal variables are "data variables" but pointers are "storage variables".

5. Pointers are used to access data indirectly.

6. Main memory is divided into 3 sections -> Stack , Heap , Code Section.
   Any Program has direct access of the code section and the stack sections in the memory but not to the heap memory.

7. Uses of pointers
     1. to access data in the heap
     2. to access resources unavailable / external to the program like a file on an external hard drive.
     3. for parameter passing

8. Pointer variables are also stored in the stack memory.

9. Size of a pointer variable is equal to the size of int datatype in the compiler.
   for e.g. -> integer pointer variable may take 2 bytes or 4 bytes


10. A pointer can be initialized with NULL, zero, Address of an object of the same type.



*/