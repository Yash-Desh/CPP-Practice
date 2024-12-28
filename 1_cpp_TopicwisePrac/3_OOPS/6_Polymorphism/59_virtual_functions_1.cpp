// Author : Yash Deshpande 
// Date : 25-02-2022

#include<iostream>
using namespace std;

class BaseClass{
    public:
        int var_base=1;
        virtual void display()     // 'virtual' Keyword used here makes the difference from the previous program
        {
            cout<<"Case - 1 : Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived=2;
            void display(){
                cout<<"Case : 2 - Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"Case : 2 - Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};
int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;

    base_class_pointer = &obj_derived;
    base_class_pointer->display();
    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. A member function in the base class which is declared using virtual keyword is called virtual functions. 

2. They can be redefined in the derived class.

3.  If we don’t use the “virtual” keyword with the “display” function of the base class then beside of the point 
    that we have pointed our base class pointer to derived class object still the compiler would have called the 
    “display” function of the base class because this is its default behavior

4. We have used the “virtual” keyword with the “display” function of the base class to make it virtual function 
   so when the display function is called by using the base class pointer the display function of the derived class 
   will run because the base class pointer is pointing to the derived class object.

*/