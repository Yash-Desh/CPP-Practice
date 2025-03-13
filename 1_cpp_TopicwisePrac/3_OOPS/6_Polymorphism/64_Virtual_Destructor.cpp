#include <iostream>
using namespace std;

class base
{
public:
    base()
    {
        cout << "Constructing base\n";
    }
    virtual ~base()
    {
        cout << "Destructing base\n";
    }
};

class derived : public base
{
public:
    derived()
    {
        cout << "Constructing derived\n";
    }
    ~derived()
    {
        cout << "Destructing derived\n";
    }
};

int main()
{
    derived *d = new derived();
    base *b = d;
    delete b;
    getchar();
    
    return 0;
}

/*
########################################### Notes ###########################################

Deleting a derived class object using a pointer of base class type that has a non-virtual 
destructor results in undefined behavior. To correct this situation, the base class should be 
defined with a virtual destructor. 

Making base class destructor virtual guarantees that the object of derived class is destructed 
properly, i.e., both base class and derived class destructors are called.

As a guideline, any time you have a virtual function in a class, you should immediately add a 
virtual destructor (even if it does nothing). This way, you ensure against any surprises later.

*/