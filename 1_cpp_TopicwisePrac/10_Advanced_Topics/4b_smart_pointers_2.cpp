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
    cout<<"Outside all the scopes\n";
    return 0;
}