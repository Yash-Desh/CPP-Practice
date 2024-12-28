// Author : Yash Deshpande
// Date : 01-04-2022

#include <iostream>
using namespace std;

// This program is essentially a modified version of the previous program to include concepts of OOPS

class Rectangle
{
    private :
    int length;
    int breadth;

    public:
        Rectangle( int l, int b)   // Constructor to initialize 
        {
            length = l;
            breadth = b;
        }

        int area()
        {
            return length * breadth;
        }

        void changeLength(int len)
        {
            length = len;
        }

};

int main()
{
    Rectangle r(10,5);
    r.area();
    r.changeLength(15);
    return 0;
}