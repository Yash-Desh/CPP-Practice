// Author : Yash Deshpande
// Date : 19-01-2022


#include <iostream>
using namespace std;

int main()
{
    
   
    cout<<"Operators in C++:"<<endl;
    cout<<"Following are the types of operators in C++"<<endl;
    
    
    
    // //1. Arithmetic operators

    // int a=4, b=5;

    // cout<<"The value of a + b is "<<a+b<<endl;  // Addition
    // cout<<"The value of a - b is "<<a-b<<endl;  // Subtraction
    // cout<<"The value of a * b is "<<a*b<<endl;  // Multiplication 
    // cout<<"The value of a / b is "<<a/b<<endl;  // Division that shows only the quotient 
    // cout<<"The value of a % b is "<<a%b<<endl;  // Division that shows only the remainder

    // // Auto increment & Auto decrement operators

    // cout<<"The value of a++ is "<<a++<<endl;    // increments AFTER printing 
    // cout<<"The value of a-- is "<<a--<<endl;    // decrements AFTER printing
    // cout<<"The value of ++a is "<<++a<<endl;    // increments BEFORE printing
    // cout<<"The value of --a is "<<--a<<endl<<endl;    // decrements BEFORE printing

    //******************************************************************************************
   
    // //2. Assignment Operators
   
    // int c = 32;    // Assigns the value 32 to the integer variable c
    // cout<<"The value of c is "<<c<<endl;

    // a += b;
    // cout<<"The value of a = a + b is "<<a<<endl;  // Addition

    // a -= b;
    // cout<<"The value of a = a - b is "<<a<<endl;  // Subtraction

    // a *= b;
    // cout<<"The value of a = a * b is "<<a<<endl;  // Multiplication 

    // a /= b;
    // cout<<"The value of a = a / b is "<<a<<endl;  // Division that shows only the quotient 

    // a %= b;
    // cout<<"The value of a = a % b is "<<a<<endl<<endl;

    //****************************************************************************************************

    // // 3. Relational OR Comparison Operators 

    // cout<<"Following are the comparison operators in C++"<<endl;
    // cout<<"The value of a == b is "<<(a==b)<<endl;
    // cout<<"The value of a != b is "<<(a!=b)<<endl;
    // cout<<"The value of a >= b is "<<(a>=b)<<endl;
    // cout<<"The value of a <= b is "<<(a<=b)<<endl;
    // cout<<"The value of a > b is "<<(a>b)<<endl;
    // cout<<"The value of a < b is "<<(a<b)<<endl<<endl; 

    //****************************************************************************************************

    // 4. Logical Operators

    // cout<<"Following are the logical operators in C++"<<endl;

    // cout<<"The value of the logical and operator ((a==b) && (a<b)) is:"<<((a==b) && (a<b))<<endl; 
    // cout<<"The value of the logical or operator ((a==b) || (a<b)) is:"<<((a==b) || (a<b))<<endl; 
    // cout<<"The value of the logical not operator (!(a==b)) is:"<<(!(a==b))<<endl; 


    //**************************************************************************************************

    // 5. Bitwise Operators

    // cout<<endl<<"Following are the Bitwise operators in C++"<<endl;
    // int a = 5;   // 0101
    // int b = 6;   // 0110
    // int c = 1;   // 0001

    // cout<<"The value of Bitwise AND operator a & b is "<<(a & b)<<endl;              // 0100 = 4
    // cout<<"The value of Bitwise OR operator a | b is "<<(a | b)<<endl;               // 0111 = 7
    // cout<<"The value of Bitwise XOR operator a ^ b is "<<(a ^ b)<<endl;              // 0011 = 3
    // cout<<"The value of Bitwise 1's Complement operator ~a is "<<(~a)<<endl;         // returns -6
    // cout<<"The value of Bitwise Left Shift operator b<<c is "<<(b<<c)<<endl;         // 1100 = 12  -> Left shifted by 1  
    // cout<<"The value of Bitwise Right Shift operator b>>c is "<<(b>>c)<<endl;        // 0011 = 3   -> Right shifted by 1

    // cout<<(b&c)<<endl;

    // cout<<(15>>2)<<endl;

    // NOTE : A single right-shift operation is the equivalent to dividing the number by 2
    //        A single left-shift operation is the equivalent to multiplying the number by 2

    //**************************************************************************************************

    // // 6. Miscellaneous Operators

    // cout<<endl<<"Following are the Miscellaneous operators in C++"<<endl;
    // int x = (1,2,5);

    // cout<<"The value of sizeof(a) is "<<sizeof(a)<<endl;
    // cout<<"The value of ternary operator condition?a:b is "<<((a<b)?(a-b):(b-a))<<endl;
    // cout<<"The value of cast operator char(a) is "<<char(a)<<endl;
    // // Google search to know more on 'comma operator'
    // cout<<"The value of comma operator (,) x =1,2,5 is "<<x<<endl;
    // // & gives the address of the operand
    // cout<<"The value of & operator &a is "<<&a<<endl;
    // cout<< "The value of * operator is "<<endl;


    return 0;
}
