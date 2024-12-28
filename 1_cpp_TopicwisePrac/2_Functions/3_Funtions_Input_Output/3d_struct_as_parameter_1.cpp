// Author : Yash Deshpande 
// Date : 25-03-2022

#include <iostream>
using namespace std;

// Q. Structure as function parameter : Pass by Value

struct Rectangle {
    int length;
    int breadth;
};

void func(struct Rectangle r)
{
    r.length += 5;   // In "Pass by value" any change made will not be reflected outside of the function
    cout<<"Length "<<r.length <<"\nBreadth "<<r.breadth<<endl;
}

int main()
{
    struct Rectangle r1 = {10,5};
    cout<<"Inside the function"<<endl;
    func(r1);
    cout<<"\nOutside the fuction"<<endl;
    cout<<"Length "<<r1.length <<"\nBreadth "<<r1.breadth<<endl;
    
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Since it is a "Call by Value" any changes made to the values of the struct inside a function like func() will not 
   modify the struct in the main() function 



*/