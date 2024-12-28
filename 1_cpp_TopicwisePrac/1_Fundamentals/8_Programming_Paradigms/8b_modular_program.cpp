// Author : Yash Deshpande 
// Date : 06-06-2022
// Tutor : Abdul Bari

// Q. Write a modular program(with functions) to calculate area & perimeter of a rectangle

#include <iostream>
using namespace std;

int area(int l, int b)
{
    return l*b;
}

int perimeter(int l, int b)
{
    int p;
    p = 2*(l+b);
    return p;
}

int main()
{
    int length = 0, breadth = 0;
    cout<<"Enter length & breadth"<<endl;
    cin>>length>>breadth;

    int Area = area(length, breadth);
    int peri = perimeter(length, breadth) ;

    cout<<"Area = "<<Area<<endl;
    cout<<"Perimeter = "<<peri<<endl; 
    return 0;
}