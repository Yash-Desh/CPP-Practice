// Author : Yash Deshpande
// Date : 07-01-2022

#include <iostream>
using namespace std;

int x = 10; // global variable 'x' declared

void func()
{
  int a;
  cout << "Value of x inside func = " << x << endl;
  // cout<<"Value of y inside func = "<<y<<endl;

  x = x + 10;
  cout << "Modified Value of x inside the function = " << x << endl;
}

void modify_global()
{
  // changed the value of global x to 35
  x = 35;
}

int main()
{

  // ****Scope of variables****

  cout << "value of global x = " << x << endl;
  // Uptil this point there is only one variable named x which is a global variable

  x += 1; // Changes made to the global variable inside 'main'
          

  cout << "Updated value of global x inside the 'main' function = " << x << endl;

  // // New local variable named x is created
  int x = 65;
  cout << "value of local variable x = " << x << endl;
  /*
  If nothing is specified then the local value of the variable is printed i.e the local variable has precedence
  over the global variable
  */

  modify_global();

  func();

  cout << "The value of the global variable x = " << ::x << endl;
  // If the scope resolution operator is used before the variable name then the global variable is printed

  x = 75; // Any changes made are automatically made to the local variable unless specified otherwise
  cout << "Local x = " << x << endl;
  cout << "Global x = " << ::x << endl; // now displays the changed value of the global x

  return 0;
}
/*

##############################################Extra Notes#####################################################

NOTE : 1. Any local variable for e.g. "x" cannot be accessed inside function like func()

2. Any variable declared inside a function for e.g. "a" inside func() cannot be accessed outside of that function.



*/