// Author : Yash Deshpande 
// Date : 25-03-2022

#include <iostream>
using namespace std;

// Q. Structure as function parameter : Pass by Address

struct Rectangle {
    int length;
    int breadth;
};

void changeLength(struct Rectangle *r, int l)
{
    r -> length = l;
}

int main()
{
    struct Rectangle r1 = {10,5};
    changeLength(&r1, 20);
    cout<<"New Length = "<<r1.length<<endl;
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Since it is a "Call by Address" any changes made to the values of the struct inside a function like area() will 
   modify the struct in the main() function 



*/