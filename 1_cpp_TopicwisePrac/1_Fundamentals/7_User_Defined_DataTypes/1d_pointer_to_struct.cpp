// Author : Yash Deshpande
// Date : 21-03-2022
// Tutor : Abdul Bari DSA course

// 1. Pointer to a static struct 
// 2. Pointer to a dynamic struct

#include <iostream>
using namespace std;


// declaring a struct rectangle having 2 attributes 
struct Rectangle
{
    int length;
    int breadth;
};


int main()
{
    struct Rectangle r = {10,5};  // Declaring & Initializing a structure of type rectangle
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    
    
    // Pointer to the structure
    struct Rectangle *ptr = &r;

    // Accessing structure elements 
    (*ptr).length = 50;                 // Use parentheses here since dot operator(.) has greater 
                                        // priority than * star operator
    cout<<"Length = "<<(*ptr).length<<endl;
    
    // Using the arrow operator
    ptr -> length = 100;  
    cout<<"Length = "<<ptr->length<<endl;


    // Dynamically creating an object of the structure in heap memory


    // M1 : C
    struct Rectangle *p1;
    p1 = (struct Rectangle*)malloc(sizeof(struct Rectangle));

    p1->length = 35;
    p1->breadth = 32;

    cout<<"Length = "<<p1->length<<endl;
    cout<<"Length = "<<p1->breadth<<endl;

    // M2 : C++
    struct Rectangle *p2;
    p2 = new struct Rectangle;

    p2->length = 25;
    p2->breadth = 12;

    cout<<"Length = "<<p2->length<<endl;
    cout<<"Length = "<<p2->breadth<<endl;

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. For a normal struct variable , we can access elements using dot(.) operator

2. For a pointer struct variable , data elements can be accessed using the arrow (->) operator


*/