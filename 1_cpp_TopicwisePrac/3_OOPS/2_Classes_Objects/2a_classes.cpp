// Author : Yash Deshpande
// Date : 27-01-2022
// Tutor : Harry, Love Babbar

#include <iostream>
using namespace std;

class Employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setData(int a1, int b1, int c1); // Declaration
    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
};

// “setData” function was defined outside the “employee” class by using a scope resolution operator
void Employee ::setData(int a1, int b1, int c1)   
{
    a = a1;
    b = b1;
    c = c1;
}


// Creating an Empty class 
class Empty
{
    // Properties
};


int main()
{
    Employee harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1, 2, 4);
    harry.getData();



    // Space Allocated to classes
    Employee obj1;
    Empty obj2;
    cout<<"Space allocated to class Employee = "<<sizeof(obj1)<<endl;

    // Empty class is always given 1 byte of space
    cout<<"Space allocated to class Empty = "<<sizeof(obj2)<<endl;

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Basic Concepts in Object-Oriented Programming
    1. Classes - Basic template for creating objects
    2. Objects – Basic run-time entities
    3. Data Abstraction & Encapsulation – Wrapping data and functions into a single unit
    4. Inheritance – Properties of one class can be inherited into others
    5. Polymorphism – Ability to take more than one forms
    6. Dynamic Binding – Code which will execute is not known until the program runs
    7. Message Passing – message (Information) call format

2. Benefits of Object-Oriented Programming
    1. Better code reusability using objects and inheritance
    2. Principle of data hiding helps build secure systems
    3. Multiple Objects can co-exist without any interference
    4. Software complexity can be easily managed

3. Characteristics of Object-Oriented Programming
    1. Works on the concept of classes and object
    2. A class is a template to create objects
    3. Treats data as a critical element
    4. Decomposes the problem in objects and builds data and functions around the objects

4. Classes are user-defined data-types and are a template for creating objects. Classes consist of variables and 
   functions which are also called class members.

5. Public Access Modifier in C++
   All the variables and functions declared under public access modifier will be available for everyone. 
   They can be accessed both inside and outside the class. Dot (.) operator is used in the program to access public data members directly.

6. Private Access Modifier in C++
   All the variables and functions declared under a private access modifier can only be used inside the class. 
   They are not permissible to be used by any object or function outside the class.

7. By default all class members are private if "public : " is not mentioned explicitly.


*/
