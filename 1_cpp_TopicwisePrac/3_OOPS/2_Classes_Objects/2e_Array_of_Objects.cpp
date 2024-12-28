// Author : Yash Deshpande
// Date : 28-01-2022

#include <iostream>
using namespace std;

class Employee
{
    int id;
    int salary;

public:
    void setId(void)
    {
        salary = 122;
        cout << "Enter the id of employee : ";
        cin >> id;
    }

    void getId(void)
    {
        cout << "The id of this employee is " << id << endl<<endl;
    }
};

int main()
{
    // Employee harry, rohan, lovish, shruti;
    // harry.setId();
    // harry.getId();
    Employee fb[4];
    for (int i = 0; i < 4; i++)
    {
        fb[i].setId();
        fb[i].getId();
    }

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. An array of objects is declared the same as any other data-type array.  

2. An array of objects consists of class objects as its elements.

3. If the array consists of class objects it is called an array of objects.

*/