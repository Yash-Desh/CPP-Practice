// Author : Yash Deshpande
// Date   : 28-09-2025
// Tutor  : The Cherno

#include <iostream>
using namespace std;

// Create a Smart Pointer
// Create a pointer to the Entity object that gets destroyed after going out of scope


class Entity {
public:
    Entity() {
        cout<<"Created Entity!\n";
    }

    ~Entity() {
        cout<<"Destroyed Entity!\n";
    }
};

class ScopedPtr {
private:
    Entity* m_Ptr;
    
public:
    ScopedPtr(Entity* ptr) : m_Ptr(ptr) 
    {
    }

    ~ScopedPtr() {
        delete m_Ptr;
    }

};

int main() {

    // Method-1: Implicit Conversion
    {
        ScopedPtr e = new Entity;
    }

    // // Method-2
    // {
    //     ScopedPtr e(new Entity);
    // }
    return 0;
}