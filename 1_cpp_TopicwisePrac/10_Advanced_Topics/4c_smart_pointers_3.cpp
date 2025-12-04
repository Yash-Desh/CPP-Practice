// Author : Yash Deshpande
// Date   : 21-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <string>
#include <memory>       // --> for smart pointers
using namespace std;

class Entity {
    public:
    Entity() {
        cout<<"Entity created!"<<endl;
    }

    ~Entity() {
        cout<<"Entity destroyed!"<<endl;
    }

    void print() {
        cout<<"Accessing member function print()\n";
    }
}; 

int main() {

    // weak_ptr : can be copied but doesn't impact the ref count
    {
        // Method-2 : 
        shared_ptr<Entity> shared_entity2 = make_shared<Entity>();

        // Multiple pointers to the same memory
        weak_ptr<Entity> weak_entity1 = shared_entity2;
    }

    return 0;
}