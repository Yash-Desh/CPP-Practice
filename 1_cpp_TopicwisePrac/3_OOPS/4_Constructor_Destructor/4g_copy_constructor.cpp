// Author : Yash Deshpande
// Date   : 31-01-2022
// Tutor  : Code with Harry 

#include<iostream>
using namespace std;

class Number{
    int a;
    public:
        Number() {a = 0;}
        Number(int num) {a = num;}
        
        // When no copy constructor is found, compiler supplies its own copy constructor
        // Note : The Parameter passed when defining a copy constructor is always 
        //        "Pass by Reference" hence the "&" sign is used 
        // Number(Number &obj){
        //     cout<<"Copy constructor called!!!"<<endl;
        //     a = obj.a;
        // }

        // The const is optional but is added so that we do not modify the obj by mistake. 
        // Copy constructor takes a reference to an object of the same class as an argument.
        // NOTE : You can access the private data members of the passed object.
        Number(const Number &obj){
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

    // Case-1: Copy constructor invoked
    Number z1(z); 
    z1.display();

    // Case-2: Copy constructor invoked
    Number z3 = z; 
    z3.display();

    // Case-3: Copy constructor NOT called  --> copy assignment operator
    z2 = z; 
    z2.display();

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