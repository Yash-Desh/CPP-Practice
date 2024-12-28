// Author : Yash Deshpande
// Date : 31-01-2022

#include <iostream>
using namespace std;

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
