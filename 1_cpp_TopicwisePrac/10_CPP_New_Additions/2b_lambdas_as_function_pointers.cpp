// Author : Yash Deshpande
// Date   : 28-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Note: const is important here
void forEach(vector<int> &vec, const std::function<void(int)> &func) {
    for(int num : vec) {
        func(num);
    }
}

int main() {
    vector<int> values = {1, 5, 4, 3, 2};

    int a = 5;

    // Declaring a lambda function -> using outside variable

    // By Value
    // auto lambda = [=](int value){cout<<"value = "<<a<<endl;};

    // By Reference
    // auto lambda = [=](int value){cout<<"value = "<<a<<endl;};

    // mutable lambda
    // allows modifying the capture variables
    auto lambda = [=](int value) mutable {
        a = a + value;
        cout<<"value = "<<a<<endl;
    };

    // Using lambda functions
    forEach(values, lambda);
    return 0;
}