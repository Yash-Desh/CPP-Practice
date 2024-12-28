// Author : Yash Deshpande
// Date : 01-04-2022

#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize (struct Rectangle *ptr1, int l , int b)   // sets the length & breadth of the struct Rectangle
{
    ptr1->length = l;
    ptr1->breadth = b;
}

int area (struct Rectangle r)   // Calculates the area of the rectangle
{
    return r.length * r.breadth;
}

void changeLength (struct Rectangle *ptr2, int len)  // Changes the length of the struct
{
    ptr2->length = len;
}
int main()
{
    struct Rectangle r;
    initialize(&r, 15,10);
    area(r);
    changeLength(&r, 20);
    
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. main() has no instructions of itself apart from calling other functions. This is the style of programming in
   the C language.

2. passed by value where values inside the struct are not modified and passed by address when values inside the 
   struct are to be modified by the function.  


*/