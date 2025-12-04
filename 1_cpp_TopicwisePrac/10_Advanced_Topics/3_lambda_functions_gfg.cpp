// Author : Yash Deshpande
// Date   : 21-09-2025
// Tutor  : GFG

// https://www.geeksforgeeks.org/cpp/lambda-expression-in-c/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

int main() {
    
    // Defining a lambda
    auto res = [](int x) {
        return x + x;
    };
    cout << res(5);

    // ##################
    // Capture Clause
    // ##################
    vector<int> v1, v2;

    // Capture v1 and v2 by reference
    auto byRef = [&] (int m) {
        v1.push_back(m);
        v2.push_back(m);
    };

    // Push 20 in both v1 and v2
    byRef(20);

    print(v1);
    print(v2);
    
    return 0;
}