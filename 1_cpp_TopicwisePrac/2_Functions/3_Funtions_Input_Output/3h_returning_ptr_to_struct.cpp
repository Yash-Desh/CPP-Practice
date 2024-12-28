// Author : Yash Deshpande 
// Date : 06-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

struct Rectangle * func()
{
    struct Rectangle *ptr;
    ptr = new Rectangle;
    // ptr = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    
    ptr->length = 20;
    ptr->breadth = 14;

    return ptr;
}

int main()
{
    struct Rectangle *p;
    p = func();

    cout<<p->length<<endl<<p->breadth<<endl;
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. The function func() creates the struct dynamically inside heap & return its pointer to pointer p inside the 
   main function

*/