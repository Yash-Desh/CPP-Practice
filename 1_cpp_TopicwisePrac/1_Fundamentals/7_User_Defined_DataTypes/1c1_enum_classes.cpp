// Author : Yash Deshpande
// Date : 17-07-2026

// Program to demonstrate how enum class (scoped enumerations, C++11) fixes the
// problems of plain (unscoped) enums shown in 1c_enums_issues.cpp.

#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
// FIX for ISSUE 3: control over the underlying type + forward declaration.
// 'enum class Name : type' fixes the size, so the type can be forward-declared.
//------------------------------------------------------------------------------

// Forward declaration is legal because the underlying type is known:
enum class Drink : unsigned char;

// Two scoped enums can share an enumerator name — no clash, because the names
// are scoped to their own enum (Meal::lunch vs Snack::lunch).
enum class Meal  { breakfast, lunch, dinner };
enum class Snack { chips, lunch, soda };      // 'lunch' here does NOT clash

// Full definition of the forward-declared enum:
enum class Drink : unsigned char { water, juice, tea };

int main()
{
    //--------------------------------------------------------------------------
    // FIX for ISSUE 1: names are scoped, so they no longer leak.
    //--------------------------------------------------------------------------
    cout << "FIX 1 - names are scoped (no leak):" << endl;
    Meal  m1 = Meal::lunch;        // MUST qualify with Meal::
    Snack s1 = Snack::lunch;       // Snack::lunch is a different, unrelated value
    cout << "  Meal::lunch  as int = " << static_cast<int>(m1)
         << ", Snack::lunch as int = " << static_cast<int>(s1)
         << "  (same name, different scopes, no clash)" << endl;

    //--------------------------------------------------------------------------
    // FIX for ISSUE 2: no implicit conversion to int -> type safety.
    //--------------------------------------------------------------------------
    cout << "\nFIX 2 - no implicit int conversion:" << endl;
    // int bad = m1;               // ERROR: no implicit conversion to int
    // int y   = m1 + 5;           // ERROR: cannot do arithmetic on a scoped enum
    // if (m1 == 1) {}             // ERROR: cannot compare Meal to a raw int
    // if (m1 == s1) {}            // ERROR: cannot compare Meal to a Snack

    // When you genuinely need the integer, ask for it explicitly:
    cout << "  static_cast<int>(m1) = " << static_cast<int>(m1) << endl;
    cout << "  Meal vs Snack, Meal vs int comparisons now fail to compile" << endl;

    //--------------------------------------------------------------------------
    // FIX for ISSUE 3: explicit underlying type controls size.
    //--------------------------------------------------------------------------
    cout << "\nFIX 3 - explicit underlying type controls size:" << endl;
    Drink d1 = Drink::juice;
    cout << "  sizeof(Meal)  = " << sizeof(Meal)  << " (default underlying int -> 4)" << endl;
    cout << "  sizeof(Drink) = " << sizeof(Drink) << " (declared ': unsigned char' -> 1)" << endl;
    cout << "  static_cast<int>(d1) = " << static_cast<int>(d1) << endl;

    //--------------------------------------------------------------------------
    // NOT fixed by enum class (ISSUE 4): still no name-to-string.
    // You must map the value to text yourself.
    //--------------------------------------------------------------------------
    cout << "\nStill not fixed - name-to-string needs a manual map:" << endl;
    const char* name;
    switch (m1) {
        case Meal::breakfast: name = "breakfast"; break;
        case Meal::lunch:     name = "lunch";     break;
        case Meal::dinner:    name = "dinner";    break;
        default:              name = "unknown";   break;
    }
    cout << "  m1 as text (via switch) = " << name << endl;

    return 0;
}

/*

##############################################Extra Notes#####################################################

How enum class (scoped enum, C++11) fixes the plain-enum issues from 1c_enums_issues.cpp:

1. Names no longer leak.
   - Enumerators are scoped to the enum, so you write Meal::lunch, Snack::lunch.
   - Two scoped enums can reuse the same enumerator name without clashing.

2. No implicit conversion to int (type safety).
   - A scoped enum will NOT silently become an int, so meaningless arithmetic
     (m1 + 5) and cross-type comparisons (Meal == int, Meal == Snack) fail to compile.
   - Use static_cast<int>(x) when you deliberately want the integer value.

3. Control over the underlying type + forward declaration.
   - 'enum class Name : type { ... }' fixes the size (e.g. unsigned char -> 1 byte).
   - Because the size is known, a scoped enum can be forward-declared.
   - Note: plain enums in C++11 can ALSO specify an underlying type; the scoping
     behaviour is the part unique to enum class.

What enum class does NOT fix:

4. No name-to-string. Neither plain nor scoped enums store their enumerator names
   as strings. Converting a value to text still needs a manual switch/lookup, or
   (C++ later) reflection-style libraries / std::to_underlying (C++23) for the int.

*/
