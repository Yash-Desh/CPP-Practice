

#include <iostream>
using namespace std;

int main()
{
    
   
    cout<<"Operators in C++:"<<endl;
    cout<<"Following are the types of operators in C++"<<endl;
    
    
    
    //1. Arithmetic operators

    int a=4, b=5;

    cout<<"The value of a + b is "<<a+b<<endl;  // Addition
    cout<<"The value of a - b is "<<a-b<<endl;  // Subtraction
    cout<<"The value of a * b is "<<a*b<<endl;  // Multiplication 
    cout<<"The value of a / b is "<<a/b<<endl;  // Division that shows only the quotient 
    cout<<"The value of a % b is "<<a%b<<endl;  // Division that shows only the remainder

    // Auto increment & Auto decrement operators

    cout<<"The value of a++ is "<<a++<<endl;    // increments AFTER printing 
    cout<<"The value of a-- is "<<a--<<endl;    // decrements AFTER printing
    cout<<"The value of ++a is "<<++a<<endl;    // increments BEFORE printing
    cout<<"The value of --a is "<<--a<<endl<<endl;    // decrements BEFORE printing

    //******************************************************************************************
   
    //2. Assignment Operators
   
    int c = 32;    // Assigns the value 32 to the integer variable c
    cout<<"The value of c is "<<c<<endl;

    a += b;
    cout<<"The value of a = a + b is "<<a<<endl;  // Addition

    a -= b;
    cout<<"The value of a = a - b is "<<a<<endl;  // Subtraction

    a *= b;
    cout<<"The value of a = a * b is "<<a<<endl;  // Multiplication 

    a /= b;
    cout<<"The value of a = a / b is "<<a<<endl;  // Division that shows only the quotient 

    a %= b;
    cout<<"The value of a = a % b is "<<a<<endl<<endl;

    //****************************************************************************************************

    // 3. Relational OR Comparison Operators 

    cout<<"Following are the comparison operators in C++"<<endl;
    cout<<"The value of a == b is "<<(a==b)<<endl;
    cout<<"The value of a != b is "<<(a!=b)<<endl;
    cout<<"The value of a >= b is "<<(a>=b)<<endl;
    cout<<"The value of a <= b is "<<(a<=b)<<endl;
    cout<<"The value of a > b is "<<(a>b)<<endl;
    cout<<"The value of a < b is "<<(a<b)<<endl<<endl; 

    //****************************************************************************************************

    // 4. Logical Operators

    cout<<"Following are the logical operators in C++"<<endl;

    cout<<"The value of this logical and operator ((a==b) && (a<b)) is:"<<((a==b) && (a<b))<<endl; 
    cout<<"The value of this logical or operator ((a==b) || (a<b)) is:"<<((a==b) || (a<b))<<endl; 
    cout<<"The value of this logical not operator (!(a==b)) is:"<<(!(a==b))<<endl; 


    //**************************************************************************************************

    // 5. Bitwise Operators




    //**************************************************************************************************

    // 6. Ternary Operators

    
    return 0;
}
