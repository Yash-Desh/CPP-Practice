// Author : Yash Deshpande 
// Date : 10-02-2022

#include <iostream>
using namespace std;

/*

Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/

class Base1{
    int data1;
    public:
        Base1(int i){
            data1 = i;
            cout<<"Base1 class constructor called"<<endl;
        }
        void printDataBase1(void){
            cout<<"The value of data1 is "<<data1<<endl;
        }
};

class Base2{
    int data2;

    public:
        Base2(int i){
            data2 = i;
            cout << "Base2 class constructor called" << endl;
        }
        void printDataBase2(void){
            cout << "The value of data2 is " << data2 << endl;
        }
};

class Derived: public Base2, public Base1  // Constructors are executed in this order i.e the order in which they are inherited
{
    int derived1, derived2;
    public:
        // Special Syntax
        Derived(int a, int b, int c, int d) : Base2(b), Base1(a)  // --> This statement doesn't affect the order of  constructor call  
        {
            derived1 = c;
            derived2 = d;
            cout<< "Derived class constructor called"<<endl;
        }
        void printDataDerived(void)
        {
            cout << "The value of derived1 is " << derived1 << endl;
            cout << "The value of derived2 is " << derived2 << endl;
        }
};
int main(){

    Derived harry(1, 2, 3, 4);
    harry.printDataBase1();
    harry.printDataBase2();
    harry.printDataDerived();

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. If the base class constructor does not have any arguments, there is no need for any constructor in the derived class

2. But if there are one or more arguments in the base class constructor, derived class need to pass argument to the 
   base class constructor

3. If both base and derived classes have constructors, base class constructor is executed first

4. In multiple inheritances, base classes are constructed in the order in which they appear in the class deceleration.

5. In multilevel inheritance, the constructors are executed in the order of inheritance.

6. C++ supports a special syntax for passing arguments to multiple base classes
   Syntax:
   Derived-Constructor (arg1, arg2, arg3….): Base 1-Constructor (arg1,arg2), Base 2-Constructor(arg3,arg4)
    {
    ….
    }

7. The constructor of the derived class receives all the arguments at once and then will pass the call to the respective base classes

8. The body is called after the constructors is finished executing

9. The constructors for virtual base classes are invoked before a non-virtual base class

10. If there are multiple virtual base classes, they are invoked in the order declared

11. Any non-virtual base class are then constructed before the derived class constructor is executed

12. The constructors will be executed in the order in which the classes are being inherited. 
    As in the example program above the “Base2” class is being inherited first and then “Base1” class is being inherited, 
    so the constructor of “Base2” class will be executed first.

*/