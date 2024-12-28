// Author : Yash Deshpande
// Date : 06-06-2022
// Tutor : Abdul Bari

// Q. Write a program with classes to calculate area & perimeter of a rectangle

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    void initialize(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        int p;
        p = 2 * (length + breadth);
        return p;
    }
};

int main()
{
    Rectangle r1;

    int length = 0, breadth = 0;
    cout << "Enter length & breadth" << endl;
    cin >> length >> breadth;

    r1.initialize( length, breadth);

    int Area = r1.area();
    int peri = r1.perimeter();

    cout << "Area = " << Area << endl;
    cout << "Perimeter = " << peri << endl;
    return 0;
}