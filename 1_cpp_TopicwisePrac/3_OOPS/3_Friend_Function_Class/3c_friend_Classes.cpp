// Author : Yash Deshpande
// Date : 28-01-2022

#include <iostream>
using namespace std;

// Forward declaration
class Calculator;

class Complex
{
    int a, b;
    
    // Method - 1 : Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(Complex, Complex);
    // friend int Calculator ::sumCompComplex(Complex, Complex);

    // Method -2 : Declaring the entire calculator class as friend
    friend class Calculator;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }

    // These functions must be defined after 'Complex' class definition
    int sumRealComplex(Complex o1, Complex o2);  
    int sumCompComplex(Complex , Complex );
};


int Calculator :: sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator :: sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    
    o1.setNumber(1, 4);
    o1.printNumber();

    o2.setNumber(5, 7);
    o2.printNumber();

    Calculator calc;
    int resR = calc.sumRealComplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << resR << endl;
    
    int resC = calc.sumCompComplex(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << resC << endl;

    return 0;
}
/*

##############################################Extra Notes#####################################################s

1. Friend classes are those classes that have permission to access private members of the class in which they are declared.
 
2. The main thing to note here is that if the class is made friend of another class then it can access all 
   the private members of that class. 

*/