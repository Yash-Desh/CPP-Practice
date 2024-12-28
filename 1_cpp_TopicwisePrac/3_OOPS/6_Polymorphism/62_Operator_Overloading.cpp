// Author : Yash Deshpande 
// Date : 25-07-2023
// Tutor : Love Babbar

#include <iostream>
using namespace std;

class Overloader 
{
    public:
    int a;
    
    // overloading '+' operator
    void operator+ (Overloader &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;

        cout<<"Value = "<<value1 + value2<<endl;
    }

    // overloading '()' operator
    void operator() ()
    {
        cout<<"Brackets are overloaded"<<endl;
    }
};

int main()
{
    Overloader obj1, obj2;
    obj1.a = 35;
    obj2.a = 54;

    obj1+obj2;

    obj1();


    return 0;
}