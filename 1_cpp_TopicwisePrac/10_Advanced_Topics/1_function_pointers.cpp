// Author : Yash Deshpande
// Date   : 21-09-2025
// Tutor  : The Cherno (https://youtu.be/p4sDgQ-jao4?si=wyLWfSITXLxSmkVo)

/*
Function Pointers are pre-requisite to learn about lambda functions.
This file is a part-1 to learn about function pointers. 
Function pointers can be replaced with lambda functions. 
*/

#include <iostream>
using namespace std;

void hello_world() {
    cout<<"hello world\n";
}

void print_num(int num) {
    cout<<"You are printing the number : "<<num<<endl;
}

int main() {
    // ----------- Normal Function Call ----------- // 
    hello_world();


    // ------------- Function Pointer ------------- // 

    // Method-1 : Function Pointer using "auto"
    auto func_ptr = hello_world;
    func_ptr();

    // Method-2 : C-style function pointers
    // return_type(* function_pointer_name)(parameter, parameter) 
    // Notice no brackets () are used after "hello_world"
    void(*func_ptr2)() = hello_world;
    func_ptr2();

    // Method-3 : typedef
    typedef void(*hello_world_function)();
    hello_world_function func_ptr3 = hello_world;
    func_ptr3();

    // With parameters
    typedef void(*printer_func)(int);
    printer_func func_ptr4 = print_num;
    func_ptr4(14);


    return 0;
}

/*
C-style function pointers.
- Function Pointers are a way to assign functions to variables & pass functions as parameters 
  to other functions 
- Functions are CPU instructions that are stored somewhere in memory in the compiled binary file
- With function pointers we are pointing at the address of the functions 


*/