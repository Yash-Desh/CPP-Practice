// Date : 28-09-2025
// Tutor : Tutorials Point

#include <iostream>
#include <cmath>
using namespace std;
class My_Complex
{
private:
    double real, imag;

public:
    My_Complex(double re = 0.0, double img = 0.0) : real(re), imag(img) {}
    double mag()
    {
        // normal function to get magnitude
        return getMagnitude();
    }
    operator double()
    {
        // Conversion operator to gen magnitude
        return getMagnitude();
    }

private:
    double getMagnitude()
    { // Find magnitude of complex object
        return sqrt(real * real + imag * imag);
    }
};
int main()
{
    My_Complex complex(10.0, 6.0);
    cout << "Magnitude using normal function: " << complex.mag() << endl;
    cout << "Magnitude using conversion operator: " << complex << endl;
}