// Author : Yash Deshpande
// Date : 10-02-2022

#include <iostream>
using namespace std;


/*

###########################################
Run Time Polymorphism : Function Overriding
###########################################

Ambiguity Resolution : one class is derived from one or more base classes 
                       then the base classes & the derived class may have 
                       functions with the same name & same parameters 

*/

class B{
    public:
        void say(){
            cout<<"Hello world"<<endl;
        }
};

class D: public B{
    int a;
    
    // D's new say() method will override base class's say() method
    public:
        void say()
        {
            cout << "Hello my beautiful people" << endl;
        }
};


int main()
{
    // Ambibuity 2
    B b;
    b.say();

    D d;
    d.say();

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. Both “B” and “D” classes have the same function “say”, So if the class “D” will call the function “say” it will 
   override the base class “say” method because compiler by default run the method which is already written in its 
   own body. 

2. But if the function “say” was not present in the class “D” then the compiler will run the method of the class “B”.


*/