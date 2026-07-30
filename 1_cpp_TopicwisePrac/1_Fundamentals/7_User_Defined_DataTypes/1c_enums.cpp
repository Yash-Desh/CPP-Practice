// Author : Yash Deshpande
// Date : 27-01-2022

// Program to demonstrate the use of enums

#include <iostream>
using namespace std;

//Enums are user-defined types which consist of named constants.

// Method-1: Globally declared enum
// enum Meal_global {
//     breakfast,
//     lunch,
//     dinner
// };

int main()
{
    // Method-2: Locally declared enum
    enum Meal {
        breakfast,
        lunch,
        dinner
    };
    Meal m1 = lunch;   // m1 is of type Meal   -> restricted to Meal values only
    cout << m1<<endl;
    cout<<dinner<<endl;

    int m2 = lunch;    // m2 is a plain int    -> enum decayed to its int value (1)
    cout << m2 << endl;
    // int m3 = 5 would compile, but "Meal m3 = 5" would NOT (int does not auto-convert back to enum)

    // ------------------------------- sizeof(enum) ------------------------------- //
    cout << "sizeof(Meal) = "  << sizeof(Meal)  << endl;                // 4
    cout << "sizeof(lunch) = " << sizeof(lunch) << endl;                // 4
    cout << "sizeof(m1) = "    << sizeof(m1)    << endl;                // 4

    cout << "sizeof(int) = "   << sizeof(int)   << endl;                // 4
    cout << "sizeof(m2) = "    << sizeof(m2)    << endl;                // 4


    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Enums are used to make the program more readable.

2. (breakfast, lunch, dinner) are constants.
   The value for “breakfast” is “0”, the value for “lunch” is “1” and the value for “dinner” is “2”.

3. [Disclaimer: Note 3 was generated with the help of an LLM (Claude Opus 4) on 2026-07-17.]

   Declaring "m1" as type Meal is a choice, not a requirement.
   - "Meal m1 = lunch;" makes m1 type-safe: only Meal values can be assigned. "Meal m1 = 5;" is an ERROR.
   - "int m2 = lunch;" also works, because an unscoped enum implicitly converts (decays) to int, so m2 holds 1.
   - The conversion is one-way: enum -> int is automatic, but int -> enum is NOT.
     So "int x = lunch;" is fine, while "Meal x = 1;" needs an explicit cast.
   - Prefer the enum type (Meal) for readability and to let the compiler catch invalid values.

4. [Disclaimer: Note 4 was generated with the help of an LLM (Claude Opus 4) on 2026-07-17.]

   The enum is declared INSIDE main(), which makes it a local (block-scoped) type.
   - This is legal C++ and compiles fine; "Meal" simply only exists within main().
   - It is acceptable here because only main() uses "Meal".
   - Conventionally, an enum is declared OUTSIDE main() (at file scope) so that other
     functions can also use it, e.g. "void serve(Meal m)" or "Meal nextMeal()".
   - Rule of thumb: declare the enum where it needs to be visible. Only one function
     uses it -> local is okay. Multiple functions need it -> declare it at file scope.

5. [Disclaimer: Note 5 was generated with the help of an LLM (Claude Opus 4) on 2026-07-17.]

   Size of an enum:
   - The enum TYPE declaration ("enum Meal {...};") itself allocates NO runtime memory.
     The enumerators are compile-time constants baked into the code (like typed #defines).
   - sizeof does NOT measure the declaration; it reports how many bytes ONE VARIABLE of
     that type would occupy. So sizeof(Meal) == sizeof(m1).
   - That size equals the enum's underlying integral type. With no explicit type, the
     compiler picks one big enough to hold all enumerators; for small values like {0,1,2}
     it defaults to int -> 4 bytes on typical platforms.
   - sizeof is never 0: the standard guarantees sizeof(T) >= 1 so that distinct objects
     always have distinct addresses.
   - You can shrink it by fixing the underlying type, e.g. "enum Meal : unsigned char {...};" -> 1 byte.
   - Local vs global does NOT change sizeof; it only affects scope (and, for variables,
     storage duration: local -> stack, global -> static storage).

*/