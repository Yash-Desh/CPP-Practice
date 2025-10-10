// Author : Yash Deshpande
// Date   : 09-10-2025
// Tutor  : Mike Shah YT (https://youtu.be/GuhO2Xi6ips?si=dZlW-OUeLKV98uwX)

// Pre-Requisite : 1b_datatype_modifiers.cpp --> contains sizeof() important data types
// Post-Completion : Also look at structure padding & packing.

#include <iostream>
#include <vector>
using namespace std;

class MyClass {
    int x, y;
    char ch;
    public:
    MyClass(int val = 10) : x(val){}
};


int main() {

    // Local variable (primitive type)
    int x = 7;

    // Pointer variable.
    int *ptr = &x;

    // Stack allocated array
    int array[] = {1, 3, 5, 7, 9};

    // Heap allocated array
    int* dynamicArray = new int [100];

    // vector C++ STL
    vector<int> vec = {10, 20, 30, 40, 50};

    // class object
    MyClass myObject;


    // Output
    cout<<"sizeof(x)            :"<<sizeof(x)<<endl;                // 4
    cout<<"sizeof(ptr)          :"<<sizeof(ptr)<<endl;              // 8    --> sizeof(any pointer) = 8B on 64-bit machines
    cout<<"sizeof(array)        :"<<sizeof(array)<<endl;            // 20
    cout<<"sizeof(dynamicArray) :"<<sizeof(dynamicArray)<<endl;     // 8    --> sizeof(any pointer) = 8B on 64-bit machines
    cout<<"sizeof(vec)          :"<<sizeof(vec)<<endl;              // 24

    /*
    [**NVIDIA**] Why is the size of vector 24B ?
    --> vector dynamically allocates data array on the heap
    --> The vector object stores only pointers & metadata
    --> Specifically 3 pointers
    _M_start            : pointer to the first element
    _M_finish           : pointer one past the last element
    _M_end_of_storage   : pointer one past the allocated memory block
    As seen previously size of a single pointer on 64-bit machine is 8B hence total is 24B
    
    */

    cout<<"sizeof(MyClass)      :"<<sizeof(MyClass)<<endl;              // 12  --> Will print out the size of object of the class
    cout<<"sizeof(myObject)     :"<<sizeof(myObject)<<endl;             // 12

    return 0;
}