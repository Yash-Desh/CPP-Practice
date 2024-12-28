// Author : Yash Deshpande 
// Date : 22-02-2022
// Tutor : Code with Harry , Love Babbar

#include<iostream>
using namespace std;

class A
{
    int a;
    
    public:
        A()
        {
            // this pointer stores the address of the
            // current object
            cout<<"this -> "<<this<<endl;
        }
        void setData(int a){
            this->a = a;
        }

        void getData(){
            cout<<"The value of a is "<<a<<endl;
        }
};


int main(){
    A a;
    cout<<"Address of the object a is "<<&a<<endl;
    a.setData(4);
    a.getData();

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. “this” is a keyword that is an implicit pointer. 

2. “this” pointer points to the object which calls the member function.

3. The Function “setData” will take one parameters and assign the values of parameter to the private data members “a” 
   using “this” pointer. 

*/
