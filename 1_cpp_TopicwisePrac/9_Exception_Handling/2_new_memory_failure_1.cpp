// Author: Yash Deshpande
// Date  : 29-11-2025
// Tutor : GFG (https://www.geeksforgeeks.org/cpp/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/)

// C++ program to illustrate memory
// failure when very large memory
// is allocated
#include <iostream>
using namespace std;

// Driver Code
int main()
{
    // Allocate huge amount of memory
    long MEMORY_SIZE = 0x7fffffff;

    // Put memory allocation statement
    // in the try catch block
    try {
        char* ptr = new char[MEMORY_SIZE];

        // When memory allocation fails,
        // below line is not be executed
        // & control will go in catch block
        cout << "Memory is allocated"
             << " Successfully" << endl;
    }

    // Catch Block handle error
    catch (const bad_alloc& e) {

        cout << "Memory Allocation"
             << " is failed: "
             << e.what()
             << endl;
    }

    return 0;
}