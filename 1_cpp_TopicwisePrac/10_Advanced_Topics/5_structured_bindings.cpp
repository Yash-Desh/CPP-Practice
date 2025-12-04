// Author : Yash Deshpande
// Date   : 23-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <string>
#include <tuple>
using namespace std;

tuple<string, int> createPerson() {
    return {"Cherno", 24};
}

int main() {
    auto [name, age] = createPerson();
    cout<<"Name = "<<name<<endl;
    cout<<"Age = "<<age<<endl;
    return 0;
}