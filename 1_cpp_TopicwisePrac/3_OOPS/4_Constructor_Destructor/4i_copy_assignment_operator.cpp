// Author : Yash Deshpande
// Date   : 20-09-2025
// Tutor  : GFG

#include <iostream>
#include <cstring>
using namespace std;

// In C++, the compiler automatically provides a default assignment operator for classes.
// This operator performs a shallow copy of each member of the class from one object to another.
// If our class has dynamic memory allocation, then shallow copy will cause double free error.

class GfG
{
public:
    int *arr;
    int _size;

    // Parameterized Constructor
    GfG(int size = 3)
    {
        arr = new int[size];
        _size = size;
    }

    //  ############### COMMENT THIS SECTION AND CHECK OUTPUT ###############
    // Overloaded assignment operator
    GfG &operator=(const GfG &c)
    {
        // self assignment check
        if (this != &c)
        {
            // Allocate new block
            int *temp = arr;
            arr = new (nothrow) int[c._size];

            // If allocation fails
            if (arr == nullptr)
            {
                arr = temp;
            }
            else
            {
                // Deallocate current block
                delete[] temp;

                // Copy data
                _size = c._size;
                memmove(arr, c.arr, _size * sizeof(int));
            }
        }
        return *this;
    }
    // #######################################################################

    // Deleting dynamic resources
    ~GfG()
    {
        delete arr;
    }
};

int main()
{
    GfG c1, c2;

    // Initialize c2.arr with some values
    for (int i = 0; i < c1._size; i++) {
        c2.arr[i] = i + 10;
    }

    // Copying c2 object to c1
    c1 = c2;

    // Print the pointers to the allocated memory
    cout << c1.arr << endl;
    cout << c2.arr;
    return 0;
}

/*

#################################### Extra Notes ############################################

Refer to this article : https://www.geeksforgeeks.org/cpp/cpp-assignment-operator-overloading/

In C++, the compiler automatically provides a default assignment operator for classes.
This operator performs a shallow copy of each member of the class from one object to another.
This means that if we don't explicitly overload the assignment operator,
the compiler will still allow us to assign one object to another using the assignment operator (=),
and it won't generate an error.

So, when we should perform assignment operator overloading?
When our class involves dynamic memory allocation (e.g., pointers) and we need to perform a deep copy
to prevent issues like double deletion or data corruption.




*/