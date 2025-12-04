// Author : Yash Deshpande
// Date   : 21-09-2025
// Tutor  : The Cherno (https://youtu.be/p4sDgQ-jao4?si=wyLWfSITXLxSmkVo)

/*
Function Pointers are pre-requisite to learn about lambda functions.
This file is a part-2 to learn about function pointers.
Function pointers can be replaced with lambda functions. 
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