// Author : Yash Deshpande
// Date : 28-01-2022

#include <iostream>
using namespace std;

class Employee
{
    int id;
    // private static variable
    // Static Variable == Class Variable
    static int count;   

public:
    // public static variable
    static int timeToComplete;

    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is " << id << " and this is employee number " << count << endl;
    }

    static void getCount(void){

        cout<<"The value of count is "<<count<<endl;

        // object variables cannot be accessed by a static method
        // Below line will give an error 
        // cout<<id;           
        
    }
};

// Count is the static data member of class Employee
int Employee::count; // Default value is 0

// timeToComplete is the static data member of class Employee
int Employee :: timeToComplete = 5;


int main()
{
    // Static data members belong to the class
    // They can be accessed without any object creation
    // They should be accessed using the class only, not using any object
    cout<<Employee::timeToComplete<<endl;



    // Employee harry, rohan, lovish;
    // // harry.id = 1;
    // // harry.count=1; // cannot do this as id and count are private

    // harry.setData();
    // harry.getData();
    // Employee::getCount();   // Notice the way  a static member function is called

    // rohan.setData();
    // rohan.getData();
    // Employee::getCount();

    // lovish.setData();
    // lovish.getData();
    // Employee::getCount();

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. When a static data member is created, there is only a single copy of the data member which is 
   shared between all the objects of the class.

2. When a static method is created, they become independent of any object and class. 

3. Static methods can only access static data members and static methods.
 
4. Static methods can only be accessed using the scope resolution operator. 


*/