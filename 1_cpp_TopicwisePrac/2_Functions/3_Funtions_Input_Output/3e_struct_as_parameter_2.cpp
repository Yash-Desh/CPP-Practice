// Author : Yash Deshpande 
// Date : 25-03-2022

#include <iostream>
using namespace std;

// Q. Structure as function parameter : Pass by Reference

struct Rectangle {
    int length;
    int breadth;
};

int area(struct Rectangle &r)
{
    return r.length * r.breadth;
}

int main()
{
    struct Rectangle r1 = {10,5};
    cout<<"Area of Rectangle = "<<area(r1)<<endl;
    return 0;
}


/*

##############################################Extra Notes#####################################################

1. Since it is a "Call by Reference" any changes made to the values of the struct inside a function like area() will 
   modify the struct in the main() function 



*/