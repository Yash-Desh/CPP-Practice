// Author : Yash Deshpande
// Date : 31-01-2022

#include <iostream>
using namespace std;

class Complex
{
    int x,y;
    public:
    Complex(int, int);  // Constructor declaration
    void printNumber(void)
    {
        cout<<"The number is "<<x<<" + "<<y<<"i"<<endl;
    }

};

Complex :: Complex(int a, int b)  // ----> This is a parameterized constructor as it takes 2 parameters
{
    x = a;
    y = b;
}

int main()
{
    // Implicit call
    Complex c1(4, 6);
    c1.printNumber();

    // Explicit call
    Complex c2 = Complex(5, 7);     
    c2.printNumber();               
    
    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. Parameterized constructors are those constructors that take one or more parameters. 

2. Default constructors are those constructors that take no parameters. 


*/