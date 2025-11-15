// Author : Yash Deshpande 
// Date : 25-02-2022

#include<iostream>
using namespace std;

class BaseClass{
    public:
        int var_base;
        void display(){
            cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived;
            void display(){
                cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};

int main(){
    BaseClass * base_class_pointer;         // BaseClass pointer
    BaseClass obj_base;                     // BaseClass object
    DerivedClass obj_derived;               // DerivedClass Object
    
    
    // Pointing base class pointer to derived class object
    base_class_pointer = &obj_derived; 
    base_class_pointer->var_base = 34;
    base_class_pointer->display();
    // base_class_pointer->var_derived= 134; --> Will throw an error
    base_class_pointer->var_base = 3400; 
    base_class_pointer->display();


    cout<<""<<endl;
    
    
    // Pointing derived class pointer to derived class object
    DerivedClass * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 9448;
    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display();

    return 0;
}
/*

##############################################Extra Notes#####################################################s

1.  We cannot set the value of the derived class data member by using the base class pointer 
    otherwise the compiler will throw an error.

2. When the function “display” is called using a base class pointer the main thing to note here is that 
   the base class “display” function will run here

3. We can set the value of base class data member by using derived class pointer 
   but we cannot set the value of derived class data member by using base class pointer

4. When the function “display” is called using a derived class pointer the main thing to note here is 
   that the derived class “display” function will run here.

*/