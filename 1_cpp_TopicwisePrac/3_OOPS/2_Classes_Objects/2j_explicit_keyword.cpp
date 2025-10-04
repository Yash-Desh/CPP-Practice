// Author : Yash Deshpande
// Date   : 26-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <string>
using namespace std;

// This file is to demonstrate implicit conversions in C++ & the explicit keyword used to prevent them.


// C++ is allowed to do only a single implicit conversion
// for eg. "Chinmay" is a const char * by itself if passed into a function
// C++ then implicitly casts it to string("Chinmay") to make it a string.

class Entity {
private:
    string m_Name;
    int m_Age;

public:
    Entity(const string& name) 
        : m_Name(name), m_Age(-1) {}

    Entity(int age) 
        : m_Name("Unknown"), m_Age(age) {}

    // ********** Prevent implicit conversions **********
    // explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
    // explicit Entity(const string& name) : m_Name(name), m_Age(-1) {}
};

void PrintEntity(const Entity &e) {
    // Printing something
}

int main() {
    // Method-1: Will work with an explicit constructor 
    Entity a1("Cherno");
    Entity b1(22);                  

    // Method-2: Will work with an explicit constructor
    Entity a2 = Entity("Austin");
    Entity b2 = Entity(25);

    // Method-3 : Implicit conversion
    // Entity a3 = "Dhruv"              // --> Not Allowed -> 2 implicit conversions required
    Entity a3 = string("Dhruv");        // --> hence I have explicitly converted it to a string first;
    Entity b3 = 23;                     // Won't work with explicit constructor


    // ************************ print method ************************
    // PrintEntity implicitly converted 22 to type Entity
    PrintEntity(22);                    // Won't work with explicit constructor      
    // PrintEntity("Rajesh");           // Not Allowed -> 2 implicit conversions required
    
    
    PrintEntity(string("Rajesh"));
    PrintEntity(Entity("Rishi"));

    return 0;
}