// Author : Yash Deshpande
// Date : 31-01-2022

#include<iostream>
using namespace std;

class Number{
    int a;
    public:
        Number(){
            a = 0;
        }

        Number(int num){
            a = num;
        }
        
        // When no copy constructor is found, compiler supplies its own copy constructor
        // Note : The Parameter passed when defining a copy constructor is always 
        //        "Pass by Reference" hence the "&" sign is used 
        Number(Number &obj){
            cout<<"Copy constructor called!!!"<<endl;
            a = obj.a;
        }

        void display(){
            cout<<"The number for this object is "<< a <<endl;
        }
};
int main(){
    Number x, y, z(45), z2;
    x.display();
    y.display();
    z.display();

    Number z1(z); // Copy constructor invoked
    z1.display();

    z2 = z; // Copy constructor NOT called
    z2.display();

    Number z3 = z; // Copy constructor invoked
    z3.display();

    // z1 should exactly resemble z  or x or y

    return 0;
}


/*

##############################################Extra Notes#####################################################s

1. A copy constructor is a type of constructor that creates a copy of another object. 

2. If we want one object to resemble another object we can use a copy constructor. 

3. If no copy constructor is written in the program, compiler will supply its own copy constructor.

4. When no copy constructor is found, compiler supplies its own copy constructor
   for e.g. : Number z1(z);  --> will generate an automatic copy constructor if none is explicitly declared by the programmer

5. Default copy constructor does shallow copy 

6. User defined copy constructor does deep copy

*/