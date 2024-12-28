// Author : Yash Deshpande
// Date : 03-02-2022

#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    
    // Base class parameterized constructor
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }

    // Base class default constructor is a must !!!
    Employee() {}
};

// Derived Class syntax
/* 

class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc...
};

*/


// Creating a Programmer class derived from Employee Base class
class Programmer : public Employee    // the “visibility-mode” is “public”.
{
public:
    int languageCode;
    
    // Derived Class parameterized constructor
    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }

    void getData()
    {
        cout<<id<<endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);
    
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    
    Programmer skillF(10);
    cout << skillF.languageCode<<endl;
    cout << skillF.id<<endl;
    skillF.getData();
    
    return 0;
    
}

/*

##############################################Extra Notes#####################################################s


1. Inheritance is a process of inheriting attributes of the base class by a derived class.

2. Default visibility mode is private

3. Public Visibility Mode: Public members of the base class becomes Public members of the derived class

4. Private Visibility Mode: Public members of the base class becomes Private members of the derived class

5. Private members are never inherited

6. **Important Concept** : The derived class constructor automatically calls the base class 'default' constructor. 
                           Hence it is mandatory to have a base class default constructor.


*/