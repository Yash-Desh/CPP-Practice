// Author : Yash Deshpande
// Date   : 26-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <string>
using namespace std;

// This file explains the uses of the const keyword in the sense of classes.

class Entity {
private:
    int m_X, m_Y;

    // Note: here m_W is a normal integer not a pointer.
    int * m_Z, m_W; 
    
    // To get 2 pointers
    // int *m_Z, *m_W;

    mutable int var;         // --> Variable that can be modified inside a const method

public:
    // This method will not modify any of the class data members.
    // Can only read data from the class.
    int GetX() const {
        // m_X = 2;             --> Not allowed
        var = 15;            // --> mutable variable, hence allowed.
        return m_X;
    }

    // Sometimes you need to keep 2 versions of the same function
    // 1. const method
    // 2. non-const method
    int GetX() {
        return m_X;
    }

    void SetX(int x) {
        m_X = x;
    }

    // Method that returns a constant pointer whose value cannot be modified
    // The method itself doesn't modify any class members.
    const int* const GetZ() const {
        return m_Z;
    }
};

// The object is passed as a const reference as it is a read-only method
// reference -> to prevent copy overhead 
// const -> so that the function doesn't modify anything within the object.

// But this function can only call const functions of the class.
// Since we are passing const reference of the object only const methods of the 
// class guarantee that the object will remain unmodified.
void PrintEntity(const Entity& e) {

    // calls the const version of the function
    cout<<e.GetX()<<endl;
}

int main() {
    // ##################################
    // Other Uses of const in cpp -> This file is not for them.
    // ##################################

    // Use-1 : constant variables
    const int MAX_AGE = 10;       
    // MAX_AGE = 15;            --> cannot be modified


    // Use-2: constant pointers

    const int *a = new int;
    // int const *a = new int;  --> Same as the above declaration.
    // *a = 2;                  --> Cannot change the contents of the pointer.
    a = &MAX_AGE;           //  --> Can change the address it is pointing at.


    int * const b = new int;
    *b = 2 ;                //  --> Can change the contents of the pointer
    // b = &MAX_AGE;            --> Cannot change the address it is pointing at.

    const int * const c = new int;
    // *c = 2;                  --> Cannot change the contents of the pointer.
    // c = &MAX_AGE;            --> Cannot change the address it is pointing at.

    return 0;
}