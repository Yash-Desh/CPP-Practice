// Author : Yash Deshpande
// Date : 07-06-2022
// Tutor : Abdul Bari

// Q. Write a program with class & constructor to calculate area & perimeter of a rectangle

#include <iostream>
using namespace std;

class Rectangle
{
    private:
    int length;
    int breadth;

    public:

    // Constructor
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }

    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    // Facilitator Methods
    int area()
    {
        return length*breadth;
    }

    int perimeter()
    {
        return 2*(length+breadth);
    }

    // Mutator methods
    void setlength(int l)
    {
        length = l;
    }

    void setbreadth(int b)
    {
        breadth = b;
    }

    // Accessor Methods
    int getlength()
    {
        return length;
    }

    int getbreadth()
    {
        return breadth;
    }

    // Destructor
    ~Rectangle()
    {
        cout<<"Destructor"<<endl;
    }
};

int main()
{
    Rectangle r(10,5);

    cout<<"Area = "<<r.area()<<endl;
    cout<<"Perimeter = "<<r.perimeter()<<endl;


    return 0;
}