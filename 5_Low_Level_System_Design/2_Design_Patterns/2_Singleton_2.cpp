// Author : Yash Deshpande
// Date   : 26-09-2025
// Tutor  : The Cherno

// Random Number Generator Class to demonstrate Singletons

#include<iostream>
using namespace std;

class Random 
{
public:
    // Delete the copy constructor
    Random(const Random&) = delete;

    static Random& GetInstance() 
    {
        return s_Instance;
    }

    // Assume that we have written all the logic such that this function
    // returns a random number on being called.
    float Float() 
    {
        return m_RandomGenerator;
    }

    static float Float2() 
    {
        return GetInstance().IFloat2();
    }

private:
    // Constructors are private.
    Random(){}

    float m_RandomGenerator = 0.5f;

    // Create a static instance of the class
    static Random s_Instance;

    // Internal implementation of the Float() function
    float IFloat2() 
    {
        return m_RandomGenerator;
    }

};

Random Random::s_Instance;

int main() 
{
    // Method-1
    auto &random = Random::GetInstance();
    float num = random.Float(); 

    // Method-1 : Kind of annoying to keep writing GetInstance
    float random_num = Random::GetInstance().Float();

    // Method-2: Write a static wrapper around the main function.
    float random_num2 = Random::Float2();
    cout<<random_num2<<endl;
    
    return 0;
}

/*
1. Mark the constructor private, so that no object of the class can be instantiated outside the class.
2. Provide a way to access this class statically, so we need some static function that returns either 
a reference or a pointer of this particular type. This function needs to return an instance of the singleton



*/