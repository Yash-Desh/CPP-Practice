// Author : Yash Deshpande
// Date   : 28-09-2025
// Tutor  : The Cherno

#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructing Base\n";
    }
    // ~Base()
    virtual ~Base()
    {
        cout << "Destructing Base\n";
    }
};

class Derived : public Base
{
private:
    int *m_Array;
public:
    Derived()
    {
        cout << "Constructing Derived\n";
        m_Array = new int [5];
    }
    ~Derived()
    {
        cout << "Destructing Derived\n";
        delete [] m_Array;
    }
};

int main()
{
    // Run this first ///////////////////////////////////
    Base* base = new Base;
    delete base;

    std::cout << "-------------------------------\n";

    Derived* derived = new Derived();
    delete derived;

    std::cout << "-------------------------------\n";

    // Check output by commenting out the virtual destructor
    // It causes a memory leak if the derived destructor is not called.
    Base* poly = new Derived;
    delete poly;



    // Run this second //////////////////////////////////
    // Derived *d = new Derived();
    // Base *b = d;
    // delete b;
    // getchar();
    
    return 0;
}

/*
########################################### Notes ###########################################

Cherno : You need a virtual destructor in any class which could be later inherited.

Deleting a Derived class object using a pointer of Base class type that has a non-virtual 
destructor results in undefined behavior. To correct this situation, the Base class should be 
defined with a virtual destructor. 

Making Base class destructor virtual guarantees that the object of Derived class is destructed 
properly, i.e., both Base class and Derived class destructors are called.

As a guideline, any time you have a virtual function in a class, you should immediately add a 
virtual destructor (even if it does nothing). This way, you ensure against any surprises later.

*/