// Author : Yash Deshpande
// Date   : 23-09-2025
// Tutor  : The Cherno
// https://youtu.be/fbYknr-HPYE?si=brKqzOPTlZH7yYFF

#include <iostream>
#include <string>
using namespace std;

// lvalue simply means an object that has an identifiable location in memory (i.e. having an address).
// r-value simply means, an object that has no identifiable location in memory (i.e. not having an address).
// r-values can also be referred to as "TEMPORARY"

// ###############################
// Utility functions for Example-2
// ###############################
int GetValue() {
    return 10;
}

int& GetValueRef() {
    static int value = 10;
    return value;
}

// ###############################
// Utility functions for Example-3
// ###############################
void SetValue(int& x) {}

// ###############################
// Utility functions for Example-4
// ###############################
void SetValueConst(const int& x) {}

// ###############################
// Utility functions for Example-5 : To demonstrate the use of const references, functions accept both lvalue & rvalue
// ###############################

// Function-1: Only accepting Lvalue reference
void printname(string &name) {
    cout<<"[lvalue] = "<<name<<endl;
}

// Function-2: Accepting lvalue reference & const rvalue
void printname(const string &name) {
    cout<<"[lvalue] = "<<name<<endl;
}

// Function-3: Only Accepting rvalue reference
void printname(string &&name) {
    cout<<"[rvalue] = "<<name<<endl;
}

int main() {

    // Example-1
    int i = 10;             // --> i = lvalue, 10 = rvalue
    // 10 = i;              // --> Compiler Error: Expression must be a modifiable lvalue
    int a = i;              // --> a = lvalue, i = lvalue

    // Example-2
    int j = GetValue();     // GetValue() returns an rvalue
    // GetValue() = 10;     // Compiler Error: Expression must be a modifiable lvalue
    GetValueRef() = 50;     // GetValueRef returns an rvalue reference

    // Example-3
    int x = 10;
    SetValue(x);
    // SetValue(10);        // Compiler Error: Cannot pass an rvalue in-place of an lvalue reference


    // Example-4
    // int &y = 10          // Compiler Error: Cannot pass an rvalue in-place of an lvalue reference
    const int &y = 10;      // Why does this work ? The compiler probably assigns some temporary storage
                            // to our rvalue 10 here.
    SetValueConst(x);
    SetValueConst(10);


    // Example-5
    // In each of the below examples 
    // LHS is a lvalue 
    // RHS is a rvalue
    string firstname = "Yan";
    string lastname = "Chernikov";
    string fullname = firstname + lastname;

    // Call to overloaded Function-1
    printname(fullname);

    // Call to overloaded Function-3
    printname(firstname + lastname);
    return 0;
}