// C++ program demonstrating a class that cannot be copied
#include <iostream>

using namespace std;

class NonCopyables {
public:
    NonCopyables() = default;
    // Delete copy constructor
    NonCopyables(const NonCopyables&) = delete;
    // Delete assignment operator
    NonCopyables& operator=(const NonCopyables&) = delete;

    // Member function to display a message
    void showMessage() const
    {
        cout << "This object cannot be copied." << endl;
    }
};

int main()
{
    // Create an instance of the NonCopyables class
    NonCopyables obj1;
    // Call the showMessage method to display a message
    // NonCopyables obj2 = obj1;

    /*
    main.cpp: In function ‘int main()’:
    main.cpp:26:25: error: use of deleted function ‘NonCopyables::NonCopyables(const NonCopyables&)’
    26 |     NonCopyables obj2 = obj1;
       |                         ^~~~
    main.cpp:10:5: note: declared here
    10 |     NonCopyables(const NonCopyables&) = delete;
       |     ^~~~~~~~~~~~
    */
    return 0;
}