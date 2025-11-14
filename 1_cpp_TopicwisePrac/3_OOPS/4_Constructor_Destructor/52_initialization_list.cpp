// Author : Yash Deshpande
// Date : 10-02-2022

#include <iostream>
using namespace std;

/*

Syntax for initialization list in constructor:

constructor (argument-list) : initilization-section
{
    assignment + other code;
}


*/
class Test
{
    int a; // a is declared 1st & hence will be initialized first
    int b; // b is declared 2nd & hence will be initialized later

public:

    // Test(int i, int j) : a(i), b(j) --> This works perfectly
    // Test(int i, int j) : a(i), b(2 * j) --> This works perfectly

    Test(int i, int j) : b(j), a(i+b) // -->This will give a garbage value to a since a is initialized first 
                                           //irrespective of the order in which it is written here 
    
    // Test(int i, int j) : a(i), b(a + j) --> This works perfectly
    
    // Test(int i, int j) : a(i), b(j)  //Standard declaration
    {
        cout << "Constructor executed"<<endl;
        cout << "Value of a is "<<a<<endl;
        cout << "Value of b is "<<b<<endl;
    }
};

int main()
{
    Test t(4, 6);

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. The initialization list in constructors is another concept of initializing the data members of the class. 

2. A constructor is written first and then the initializations section is written

4. In the initialization section, the data members are initialized

5. To note here is that if we use the code shown to initialize data members --> Test(int i, int j) : b(j), a(i+b)
   the compiler will throw an error because the data member “a” is being initialized first and the “b” is being 
   initialized second so we have to assign the value to “a” data member first.

*/

