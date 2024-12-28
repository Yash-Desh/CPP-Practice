// Author : Yash Deshpande 
// Date : 06-06-2022
// Tutor : Abdul Bari

// Q. Write a monolithic program(without any functions) to calculate area & perimeter of a rectangle

#include <iostream>
using namespace std;

int main()
{
    int length = 0, breadth = 0;
    cout<<"Enter length & breadth"<<endl;
    cin>>length>>breadth;

    int area = length*breadth;
    int perimeter = 2*(length+breadth);

    cout<<"Area = "<<area<<endl;
    cout<<"Perimeter = "<<perimeter<<endl; 
    return 0;
}