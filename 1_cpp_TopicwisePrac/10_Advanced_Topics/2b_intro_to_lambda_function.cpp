// Author : Yash Deshpande
// Date   : 29-11-2025
// Tutor  : The Cherno (https://youtu.be/mWgmBBz0y8c?si=yYOfcdT1-dViJnGG)

/*
Function Pointers are pre-requisite to learn about lambda functions.
This file is an intro to lambda functions & their relation with function pointers. 
Read the 2 files on function pointers before starting with this file.
Function pointers can be replaced with lambda functions.

More in-depth description of lambda functions is in the next file. 
*/

#include <iostream>
#include <vector>
using namespace std;

void printValue(int value) {
    cout<<"value = "<<value<<endl;
}

void forEach(vector<int> vec, void(*func)(int)) {
    for(int num : vec) {
        func(num);
    }
}

int main() {
    vector<int> values = {1, 5, 4, 3, 2};

    // Using function pointers
    forEach(values, printValue);

    // Using lambda functions
    forEach(values, [](int value){ cout << "value = " << value << endl; });
    return 0;
}