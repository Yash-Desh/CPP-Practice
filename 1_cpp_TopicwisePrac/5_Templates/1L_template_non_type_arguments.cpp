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