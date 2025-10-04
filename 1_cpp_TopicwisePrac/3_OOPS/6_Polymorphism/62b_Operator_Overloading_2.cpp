// Author : Yash Deshpande
// Date   : 28-09-2025
// Tutor  : The Cherno

#include <iostream>
#include <string>
using namespace std;

struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}


    // --------------- Utility Functions --------------------- //

    // To add 2 object
    Vector2 Add(const Vector2& other) const 
    {
        return Vector2(x + other.x, y + other.y);
    }

    // To multiply 2 object
    Vector2 Multiply(const Vector2& other) const 
    {
        return Vector2(x * other.x, y * other.y);
    }

    // --------------- Operator Overloading --------------------- //
    Vector2 operator+ (const Vector2& other) const 
    {
        return Add(other);
    }

    Vector2 operator* (const Vector2& other) const 
    {
        return Multiply(other);
    }

    bool operator== (const Vector2& other) const 
    {
        return x == other.x  && y == other.y;
    }

    bool operator!= (const Vector2& other) const 
    {
        return !(*this == other);
    }

};

// Overloading the cout operator
std::ostream& operator<< (std::ostream& stream, const Vector2& other) 
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main() {

    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    // We want result = position + speed * powerup

    // Complicated way of doing things 
    Vector2 result1 = position.Add(speed.Multiply(powerup));

    // Easy way
    Vector2 result2 = position + speed * powerup;

    // Overloading the cout <<
    std::cout << result2 << std::endl;              // 4.55, 5.65

    // Overloading the == operator
    if(result1 == result2) {
        std::cout << "Passed" << std::endl;
    }

    return 0;
}
