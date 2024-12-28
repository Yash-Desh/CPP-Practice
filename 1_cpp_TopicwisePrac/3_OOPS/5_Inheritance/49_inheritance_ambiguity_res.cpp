// Author : Yash Deshpande
// Date : 10-02-2022

#include<iostream>
using namespace std;


/*

Ambiguity Resolution : one class is derived from two or more base classes 
                       then the base classes have functions with the same name.

*/

class Base1{
    public:
        void greet(){
            cout<<"How are you?"<<endl;
        }

        void handshake()
        {
            cout<<"Let us shake hands"<<endl;
        }
};

class Base2{
    public:
        void greet()
        {
            cout << "Kaise ho?" << endl;
        }

        void handshake()
        {
            cout<<"Did you shake hands ?"<<endl;
        }
};


class Derived : public Base1, public Base2{
   int a;
   public:

   // There are 2 methods "greet()" & "handshake()" which are 
   // present in both the parent classes
   // This ambiguity can be resolved in the following 2 ways
    
    // Method - 1
    // Without ambiguity resolution as done below compiler will generate the following error
    // --> error : request for member 'greet' is ambiguous
    // method "greet()" is redefined in the child class & explicit call to one of the 2 
    // parent class methods is done.

    // handling ambiguity of "greet()" method
    void greet()
    {
        Base2 :: greet();   // Explicit call to greet() from class Base2
    }

    // handling ambiguity of "handshake()" method
    // No redefinition done

};


int main(){
    // Ambibuity 1

    Base1 base1obj;
    base1obj.greet();

    Base2 base2obj;
    base2obj.greet();


    Derived d;
    // No explicit made to either of the parent classes since function was redefined
    d.greet();

    // Method - 2 : Function was not redefined
    // Explicit call to a specific parent class method done
    d.Base1 :: handshake();



    
    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. Ambiguity in inheritance can be defined as when one class is derived for two or more base classes then there are chances 
   that the base classes have functions with the same name. 

2. So it will confuse derived class to choose from similar named functions. 

3. To solve this ambiguity scope resolution operator is used “::”.

4. When the function “greet” is called by the object “d” it will run the “greet” function of the “Base2” class 
   because we had specified it using scope resolution operator “::” to get rid ambiguity. 





*/