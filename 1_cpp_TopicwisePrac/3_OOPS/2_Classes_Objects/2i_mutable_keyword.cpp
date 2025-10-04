// Author : Yash Deshpande
// Date   : 26-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <string>
using namespace std;

class Entity
{
private:
    string m_Name;
    mutable int m_DebugCount = 0;       // --> const methods can modify this variable

public:
    const string &GetName() const { 
        m_DebugCount = 10;              // --> const methods can modify mutable variable
        return m_Name; 
    }
};

int main()
{
    // ########################################
    // Usecase-1: For modifying variables in const member functions
    // ########################################

    // const object
    const Entity e;
    e.GetName();                        // Can only call const member functions.

    
    
    
    // ########################################
    // Usecase-2: For lambdas
    // ########################################
    
    // Pass by Reference
    int x1 = 4;
    auto f1 = [&]() mutable {
        x1++;                         // Allowed -> for pass by reference
        cout<<"Hello World\n";
    };
    f1();
    cout<<"Value of x after calling the lambda = "<<x1<<endl;

    
    // Pass by Value
    int x2 = 8;
    auto f2 = [=]() {
        // x++;                         // Not Allowed -> for pass by value
        int y = x2;                      // Need to assign the variable to a local copy 
        y++;                            // Then modifications are allowed on the variable
        cout<<"Hello World\n";
    };
    f2();
    cout<<"Value of x after calling the lambda = "<<x2<<endl;

    
    // Pass by Value with mutable
    int x3 = 16;
    auto f3 = [=]() mutable {
        x3++;                         // Allowed -> for pass by value
        cout<<"Hello World\n";
    };
    f3();
    cout<<"Value of x after calling the lambda = "<<x3<<endl;


    return 0;
}