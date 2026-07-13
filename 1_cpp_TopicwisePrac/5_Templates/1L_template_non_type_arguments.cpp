// Author : Yash Deshpande
// Date   : 27-09-2025
// Tutor  : Cherno

#include <iostream>
#include <string>
using namespace std;

template<typename T, int N>
class Array {
private:
    T m_Array[N];

public:
    int GetSize() const {
        return N;
    }

};

int main() {
    Array<int, 5> array;
    cout<<array.GetSize()<<endl;
    return 0;
}

/*

Template non-type arguments are passed during compile-time. 
Thus they are compile time constants. 
You cannot pass run-time values as template non-type arguments.

Constructor Arguments on the other hand are run-time entities.
Hence they both are different & used for different purposes.

*/