// Author : Yash Deshpande
// Date   : 20-09-2025
// Tutor  : GFG

#include <iostream>
using namespace std;

int main() {
    int x = 7;
    try {
        if (x % 2 != 0) {
            
            // Throwing int
            throw -1;
        }
    }
    
    // Catching int
    catch (int e) {
        cout << "Exception Caught: " << e << endl;
    }
    return 0;
}