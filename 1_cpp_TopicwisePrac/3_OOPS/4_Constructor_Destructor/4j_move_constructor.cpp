// Author : Yash Deshpande
// Date   : 20-09-2025
// Tutor  : GFG

#include <iostream>
using namespace std;

class Geeks
{
private:
    int *ptr;

public:
    // Constructor
    Geeks(int value)
    {
        // Dynamically allocate memory
        ptr = new int(value);
        cout << "Constructor called\n";
    }

    // Move Constructor
    Geeks(Geeks &&obj)
    {
        cout << "Move Constructor called\n";
        // Steal the pointer
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }

    // Destructor
    ~Geeks()
    {
        if (ptr != nullptr) {
            cout << "Destructor deleting data: " << *ptr << endl;
        }
        else {
            cout << "Destructor called on nullptr\n";
        }
        delete ptr;
    }

    // Display function
    void display()
    {
        if (ptr)
            cout << "Value: " << *ptr << endl;
        else
            cout << "No data\n";
    }
};

int main()
{
    // Constructor is called
    Geeks obj1(42);
    // Move constructor is called
    Geeks obj2 = std::move(obj1);

    cout << "\nAfter move:\n";
    cout << "obj1: ";
    // Should show "No data"
    obj1.display();
    cout << "obj2: ";
    // Should show "Value: 42"
    obj2.display();

    return 0;
}


/*

#################################### Extra Notes ############################################

Source: https://www.geeksforgeeks.org/cpp/move-constructors-in-c-with-examples/

A move constructor is a special constructor in C++ that lets us transfer 
the contents of one object to another without copying the data. 
It is useful for performance - it's faster than copying.

className&& is an rvalue reference to another object of the same class.

Move constructors are used to transfer resources (like memory or file handles) from one object 
to another without making a copy, which makes the program faster and more efficient. 
They're especially useful when working with temporary objects or large data.



*/