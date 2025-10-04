// Author : Yash Deshpande
// Date   : 21-09-2025
// Tutor  : The Cherno

#include <iostream>
using namespace std;

void hello_world() {
    cout<<"hello world\n";
}

void print_num(int num) {
    cout<<"You are printing the number : "<<num<<endl;
}

int main() {
    // Method-1 : Normal Function Call
    hello_world();

    // Method-2 : Function Pointer
    auto func_ptr = hello_world;
    func_ptr();

    // Method-3 : Function Pointer without auto
    // return_type(* function_pointer_name)(parameter, parameter) 
    void(*func_ptr2)() = hello_world;
    func_ptr2();

    // Method-4 : typedef
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
Functions are CPU instructions that are stored somewhere in memory in the compiled binary file
With function pointers we are pointing at the address of the functions 


*/