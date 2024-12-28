// Author : Yash Deshpande
// Date : 29-03-2022

#include <iostream>
using namespace std;

void func (int a)
{
    cout<<"func called "<<a<<endl;
}

template<class T1>
void func(T1 b )
{
    cout<<"Templetized func called "<<b<<endl;
}

template<class T2>
void myfunc(T2 c )
{
    cout<<"Templetized myfunc called "<<c<<endl;
}


int main()
{

    // Exact match takes the highest priority

    func(45);   // Un-Templatized function called since exact match found

    func('T');  // Templatized function called since exact match NOT found

    myfunc(67.3);

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Overloading a function simply means assigning two or more functions with the same name, the same job, but with 
   different parameters.  For that, we’ll declare a void function named func. And a template function with the same 
   name.

2. (i) We made two void functions, one specified and one generic using a template.
   (ii) The first one receives an integer and prints the integer with a different prefix. 
   (iii) The generic one receives the value as well as the data type and prints the value with a different prefix.
   (iv) Now, we’ll wish to see the output of the following functions, by calling them from the main. 
   (v) And now when we call the function func, we’ll be interested to know which one among the two it calls. 
       So here since we’ve entered a value with an integer parameter, it finds its exact match in the overloading and 
       calls that itself. 
    (vi) That is, it gives its "exact match the highest priority".


*/