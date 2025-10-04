// Author : Yash Deshpande
// Date   : 26-09-2025
// Tutor  : The Cherno

// Cherno: "Singletons in C++ are just a way to organize a bunch of global variables & static functions that 
// sometimes may or may not act upon those variables into a single organized blob like a namespace."

#include<iostream>
using namespace std;

class Singleton 
{
public:
    // Delete the copy constructor
    Singleton(const Singleton&) = delete;

    static Singleton& GetInstance() 
    {
        return s_Instance;
    }

    void Function() 
    {

    }
private:
    // Constructors are private.
    Singleton(){}

    float m_Member = 0.0f;

    // Create a static instance of the class
    static Singleton s_Instance;

};

Singleton Singleton::s_Instance;

int main() 
{
    Singleton::GetInstance().Function();

    // Copy constructor deleted so not allowed
    // Singleton instance = Singleton::GetInstance();

    // References are allowed
    Singleton &instance2 = Singleton::GetInstance();    
    return 0;
}

/*
1. Mark the constructor private, so that no object of the class can be instantiated outside the class.
2. Provide a way to access this class statically, so we need some static function that returns either 
a reference or a pointer of this particular type. This function needs to return an instance of the singleton



*/