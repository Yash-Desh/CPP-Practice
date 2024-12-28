// Author : Yash Deshpande 
// Date : 03-02-2022

#include<iostream>
using namespace std;

class Base{
    protected:
        int a; 
    private:
        int b;

};

class Derived: protected Base{
   
};

int main(){
    Base b;
    Derived d;
    // cout<<d.a; // Will not work since a is protected in both base as well as derived class
    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. Protected access modifiers are similar to the private access modifiers but protected access modifiers can be 
   accessed in the derived class whereas private access modifiers cannot be accessed in the derived class. 

2. Table :

                            Public derivation       Private Derivation      Protected Derivation
    1. Private members          Not Inherited       Not Inherited               Not Inherited
    2. Protected members        Protected           Private                     Protected
    3. Public members           Public              Private                     Protected
*/