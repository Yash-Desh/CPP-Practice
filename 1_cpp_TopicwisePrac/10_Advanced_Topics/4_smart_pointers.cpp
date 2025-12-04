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
    // unique_ptr : cannot be copied
    {
        // Method-1
        std::unique_ptr<Entity> entity1(new Entity());

        // Not Allowed
        // unique_ptr<Entity> entity1 = new Entity();

        // Method-2 : For exception safety
        // Easier to handle case where dynamic memory allocation fails.
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();

        // Not Allowed
        // std::unique_ptr<Entity> eCopy = entity2;

        // Member functions are called similar to a normal pointer.
        entity1->print();
    }
    return 0;
}





/*

// shared_ptr : can be copied & maintains ref counts to the memory
    {
        std::shared_ptr<Entity> se;
        {
            // Method-1 : DON'T USE!! this method as there will be 2 allocations for the control block
            // shared_ptr<Entity> shared_entity1(new Entity());

            // Method-2 : 
            std::shared_ptr<Entity> shared_entity2 = std::make_shared<Entity>();

            // Multiple pointers to the same memory
            se = shared_entity2;
        }
    }

    // weak_ptr : can be copied but doesn't impact the ref count
    {
        // Method-2 : 
        shared_ptr<Entity> shared_entity2 = make_shared<Entity>();

        // Multiple pointers to the same memory
        weak_ptr<Entity> weak_entity1 = shared_entity2;
    }
*/