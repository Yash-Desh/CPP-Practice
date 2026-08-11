// Author: Yash Deshpande
// Date  : 04-12-2025
// Tutor : Mike Shah (https://youtu.be/2gUqyt5JTtM?si=WbGU3eLV3uKd7rTE)

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Construct a new string. This uses the copy constructor.
    // We have an rvalue on the right & that will be copied into
    // 'myString' using the copy constructor.
    string myString = "copy construct me";
    string newValue;

    cout << "myString: " << myString << endl;                   // myString: copy construct me
    cout << "newValue: " << newValue << endl;                   // newValue: 

    // Option-1 -------------------------------------- //
    // Normal Copy Operation, both newValue & myString 
    // will have their own independent copies. 
    // newValue = myString;
    // ----------------------------------------------- //
    
    // Option-2 -------------------------------------- //
    // std::move allows us to steal or adopt the value 
    newValue = std::move(myString);
    // ----------------------------------------------- //

    // Option-3 -------------------------------------- //
    // Could more explicitly call static_cast here to move
    // the value of myString into newValue.
    // newValue = static_cast<std::string&&>(myString);
    // ----------------------------------------------- //

    // NOTE: myString is still some valid value.
    // Maybe it stores nullptr in the data in the string.
    // But it stil exists.
    cout << "myString: " << myString << endl;                   // myString: 
    cout << "newValue: " << newValue << endl;                   // newValue: copy construct me

    return 0;
}