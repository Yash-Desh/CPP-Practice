// Author: Yash Deshpande
// Date  : 29-11-2025
// Tutor : The Cherno (https://youtu.be/pWZS1MtxI-A?si=iXQni9d2x7d7Gu-8)

#include <iostream>
using namespace std;

int main() {

    // ------------- C-style casting ------------- //
    // Implicit Conversion-1
    int a1 = 5;
    double value1 = a1;

    // Implicit Conversion-2
    double value2 = 5.25;
    int a2 = value2;
    // int a2 = (int)value2;    --> explicit conversion is not needed here, but we can do it.


    // ------------- C++ style casting ------------- //
    double value3 = 5.25;
    double a3 = static_cast<int>(value3) + 5.3;
    
    cout << 7/5; 

    return 0;
}