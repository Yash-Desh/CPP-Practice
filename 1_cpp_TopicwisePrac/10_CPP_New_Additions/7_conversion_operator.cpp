// Date : 28-09-2025
// Tutor : Tutorials Point

#include <iostream>
using namespace std;

// In this example, we create a class for complex numbers. 
// It has two arguments real, and imaginary. We use the conversion operator 
// to allow an object of the My_Complex class to behave like a double, 
// returning its magnitude automatically:

class Distance
{
    int meters;

public:
    Distance(int m) : meters(m) {}
    // Conversion operator to int
    operator int() const
    {
        return meters;
    }
};

int main()
{
    Distance d(100);
    int m = d;
    cout << "Meters: " << m << endl;
    return 0;
}