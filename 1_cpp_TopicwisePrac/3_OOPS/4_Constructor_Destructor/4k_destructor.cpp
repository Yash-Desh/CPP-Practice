// Author : Yash Deshpande
// Date : 01-02-2022

#include<iostream>
using namespace std;

// Destructor never takes an argument nor does it return any value 
int count=0;  // global variable declared

class num{
    public:
        // Constructor
        num(){
            count++;
            cout<<"This is the time when constructor is called for object number"<<count<<endl;
        }

        // Destructor
        ~num(){
            cout<<"This is the time when my destructor is called for object number"<<count<<endl;
            count--;
        }
};

int main(){
    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    num n1;
    {
        cout<<endl<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num n2, n3;
        cout<<"Exiting this block"<<endl;
    }
    cout<<endl<<"Back to main"<<endl;
    

    // Dynamically created object 
    num *n4 = new num();
    // Manually deleted
    delete n4;


    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. A destructor is a type of function which is called when the object is destroyed. 

2. Destructor never takes an argument nor does it return any value.

3. For statically created objects the destructor is automatically called 

4. For dynamically created objects the destructor has to be called manually


*/