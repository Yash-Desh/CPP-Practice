// Author : Yash Deshpande
// Date   : 28-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


void forEach(vector<int> &vec, const std::function<void(int)> &func) {
    for(int num : vec) {
        func(num);
    }
}

int main() {
    vector<int> values = {1, 5, 4, 3, 2};

    // Q Get an iterator to the 1st element in the array that is greater than 3
    auto it = std::find_if(values.begin(), values.end(), [](int val) { return val > 3;});
    std::cout << *it << std::endl;

    return 0;
}