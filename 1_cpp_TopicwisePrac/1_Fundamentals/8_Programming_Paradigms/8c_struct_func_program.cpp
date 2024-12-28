// Author : Yash Deshpande 
// Date : 06-06-2022
// Tutor : Abdul Bari

// Q. Write a program with structure & functions to calculate area & perimeter of a rectangle

#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b)
{
    r->length =l;
    r->breadth = b; 
}

int area(Rectangle r)
{
    return r.length*r.breadth;
}

int perimeter(struct Rectangle r)
{
    int p;
    p = 2*(r.length+r.breadth);
    return p;
}

int main()
{
    struct Rectangle r1 = {0,0};


    int length = 0, breadth = 0;
    cout<<"Enter length & breadth"<<endl;
    cin>>length>>breadth;

    initialize(&r1,length,breadth);

    int Area = area(r1);
    int peri = perimeter(r1) ;

    cout<<"Area = "<<Area<<endl;
    cout<<"Perimeter = "<<peri<<endl; 
    return 0;
}