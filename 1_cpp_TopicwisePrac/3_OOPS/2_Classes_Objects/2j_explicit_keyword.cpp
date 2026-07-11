// Author : Yash Deshpande
// Date   : 26-09-2025
// Tutor  : The Cherno

// ============================ THE 'explicit' KEYWORD ============================
// Disclaimer : This note was written with the assistance of an AI model
//              (Opus 4.8) on 10-07-2026.
//
//   'explicit' is applied to a constructor (or a conversion operator) to tell the
//   compiler NOT to use it for implicit conversions.
//
//   A constructor that can be called with a single argument normally doubles as an
//   implicit "conversion recipe": the compiler may silently convert that argument
//   into the class type wherever the class type is expected. 'explicit' turns this
//   off, so the type can only be built when you ask for it directly.
//
//   With 'explicit':
//     - Direct-initialization   T obj(arg);   -> still ALLOWED (direct ctor call)
//     - Copy-initialization     T obj = arg;  -> BLOCKED (needs implicit conversion)
//     - Implicit argument pass   f(arg);      -> BLOCKED (arg would be converted)
//   (Special case: 'explicit operator bool()' still works in boolean contexts
//    such as if / while / && / ||.)
//
//   Rule of thumb: prefer making single-argument constructors 'explicit' unless you
//   genuinely want the type to be implicitly convertible. This prevents accidental,
//   hard-to-spot conversions.
// ===============================================================================

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
    // Method-1: Direct Initialization --> Will work with an explicit constructor 
    Entity a1("Cherno");
    Entity b1(22);

    // ----------------------------------------------------------------------------
    // Disclaimer : This explanation was written with the assistance of an AI
    //              model (Opus 4.8) on 10-07-2026.
    //
    // ----- Why does Method-1 work even when the constructors are 'explicit'? -----
    // Both lines use DIRECT-INITIALIZATION (type name + parentheses), which calls
    // the constructor directly. Direct-initialization considers ALL constructors,
    // including 'explicit' ones, so it is never blocked by 'explicit'. ('explicit'
    // only blocks copy-initialization -- the "= value" form -- and the implicit
    // conversions done when passing arguments to a function.)
    //
    //   Entity a1("Cherno"):
    //     "Cherno" (const char*) --> std::string is ONE implicit conversion, and
    //     it is performed by std::string, NOT by Entity. Entity's constructor is
    //     then called directly, so 'explicit' on Entity does not apply here.
    //
    //   Entity b1(22):
    //     22 is already an int -> exact match for Entity(int); a direct call that
    //     needs ZERO conversions.
    // ----------------------------------------------------------------------------

    // Method-2: Will work with an explicit constructor
    Entity a2 = Entity("Austin");
    Entity b2 = Entity(25);

    // ----------------------------------------------------------------------------
    // Disclaimer : This explanation was written with the assistance of an AI
    //              model (Opus 4.8) on 10-07-2026.
    //
    // ----- Why does Method-2 work even when the constructors are 'explicit'? -----
    // Each line hides TWO steps, and the '=' here is NOT a cross-type conversion:
    //
    //   Step 1 (right side)  Entity("Austin") / Entity(25):
    //     This is a DIRECT constructor call (functional-cast form), just like
    //     Method-1. It builds a temporary Entity directly, so 'explicit' does not
    //     block it. (For "Austin", const char* --> std::string is the one implicit
    //     argument conversion, done by std::string; 25 is an exact int match.)
    //
    //   Step 2 (the '=')  Entity a2 = <temporary Entity>:
    //     The right side is ALREADY an Entity, so '=' only copies Entity --> Entity
    //     via the copy constructor (which is never 'explicit'). No converting
    //     constructor is needed here, so 'explicit' is irrelevant.
    //
    // Contrast with Method-3 (Entity a3 = string("Dhruv")): there the right side
    // stays a string, so '=' must implicitly convert string --> Entity, which needs
    // a NON-explicit constructor -- exactly what 'explicit' removes.
    //
    // Note: since C++17, guaranteed copy elision builds a2 directly from the
    // Entity(...) call, making this effectively identical to Method-1.
    // ----------------------------------------------------------------------------

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


// ================================ 'explicit': WHAT COMPILES? =================================
// Disclaimer : This table was written with the assistance of an AI model (Opus 4.8) on 10-07-2026.
//
// Line | Code                           | Without explicit | With explicit
// -------------------------------------------------------------------------------------------
//   63 | Entity a1("Cherno");           | YES              | YES  (direct init)
//   64 | Entity b1(22);                 | YES              | YES  (direct init)
//   88 | Entity a2 = Entity("Austin");  | YES              | YES  (explicit call)
//   89 | Entity b2 = Entity(25);        | YES              | YES  (explicit call)
//  118 | Entity a3 = "Dhruv";           | NO               | NO   (needs 2 implicit conversions)
//  119 | Entity a3 = string("Dhruv");   | YES              | NO   (copy-init needs implicit conv.)
//  120 | Entity b3 = 23;                | YES              | NO
//  125 | PrintEntity(22);               | YES              | NO
//  126 | PrintEntity("Rajesh");         | NO               | NO   (needs 2 implicit conversions)
//  129 | PrintEntity(string("Rajesh")); | YES              | NO
//  130 | PrintEntity(Entity("Rishi"));  | YES              | YES  (explicit call)
// ============================================================================================