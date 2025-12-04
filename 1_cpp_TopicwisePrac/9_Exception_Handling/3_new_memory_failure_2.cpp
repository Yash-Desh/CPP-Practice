// Author: Yash Deshpande
// Date  : 29-11-2025
// Tutor : GFG (https://www.geeksforgeeks.org/cpp/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/)

// C++ program to handle memory failure
// when very large memory is allocated
#include <iostream>
using namespace std;

// Drive Code
int main()
{
    // Allocate huge amount of memory
    long MEMORY_SIZE = 0x7fffffff;

    // Allocate memory dynamically
    // using "new" with "nothrow"
    // version of new
    char* addr = new (std::nothrow) char[MEMORY_SIZE];

    // Check if addr is having
    // proper address or not
    if (addr) {

        cout << "Memory is allocated"
             << " Successfully" << endl;
    }
    else {

        // This part will be executed if
        // large memory is allocated and
        // failure occurs
        cout << "Memory  allocation"
             << " fails" << endl;
    }

    return 0;
}