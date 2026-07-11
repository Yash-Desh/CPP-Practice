// Author : Yash Deshpande
// Date : 31-01-2022

#include <iostream>
using namespace std;

/*
 * Disclaimer: Summary generated on Jul 10, 2026 by the Claude Opus 4.8
 * model. Verify against a compiler/standard before relying on it.
 *
 * Why "class Complex;" is needed: the classes are circularly dependent.
 * Calculator uses Complex as a parameter type (only needs the name, so an
 * incomplete type is enough), while Complex befriends Calculator's member
 * functions (needs Calculator's COMPLETE definition). So the order must be:
 * forward-declare Complex -> define Calculator -> define Complex. Without
 * the forward declaration, Complex is an unknown type in Calculator's
 * methods and the compiler errors: "'Complex' does not name a type".
 */
class Complex;

class Calculator
{
    public:
    int sumRealComplex(Complex , Complex);
    int sumCompComplex(Complex, Complex);
};

class Complex
{
    private:
    int a,b;

    // Method - 1 : Individually declaring functions as friends
    friend int Calculator:: sumCompComplex(Complex,Complex);
    friend int Calculator:: sumRealComplex(Complex,Complex);

    public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber(void)
    {
        cout<<"The complex number is "<<a<<" + "<<b<<"i"<<endl;
    }
};


int Calculator :: sumRealComplex(Complex o1, Complex o2 )
{
    int real;
    real = o1.a + o2.a;
    return real;
}

int Calculator :: sumCompComplex(Complex o1, Complex o2 )
{
    int imaginary ;
    imaginary = o1.b + o2.b;
    return imaginary;
}



int main()
{
    Complex c1, c2, c3;
    c1.setNumber(3,4);
    c1.printNumber();
    

    c2.setNumber(1,7);
    c2.printNumber();

    Calculator calc;
    int rp = calc.sumRealComplex(c1, c2);
    int ip = calc.sumCompComplex(c1, c2);

    c3.setNumber(rp, ip);
    c3.printNumber();


    return 0;
}
