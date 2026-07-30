// Author : Yash Deshpande
// Date : 15-07-2026

// Program to demonstrate the issues with plain (unscoped) enums.
// The fixes (via enum class / scoped enums) are covered in 1c1_enum_classes.cpp.

#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
// ISSUE 3 (shown at file scope): No control over the underlying type (pre-C++11)
// and cannot be forward-declared, because the compiler doesn't know the size.
// A plain enum's underlying type is implementation-defined.
//------------------------------------------------------------------------------

enum Meal { breakfast, lunch, dinner };

// The following line would be a COMPILE ERROR: 'lunch' already declared above.
// The enumerators of Meal leaked into this scope, so they clash here.
// enum Snack { chips, lunch };

// This version is fine because the names are different:
enum Snack { chips, fries, soda };

int main()
{
    //--------------------------------------------------------------------------
    // ISSUE 1: Enumerator names leak into the enclosing scope.
    // We can use 'lunch' directly without qualifying it as Meal::lunch.
    //--------------------------------------------------------------------------
    Meal m1 = lunch;          // no 'Meal::' needed — the name leaked into scope
    cout << "ISSUE 1 - names leak into scope:" << endl;
    cout << "  Wrote 'Meal m1 = lunch;' with no Meal:: qualifier" << endl;

    //--------------------------------------------------------------------------
    // ISSUE 2: Implicit conversion to int.
    // A Meal silently decays to its underlying integer value.
    //--------------------------------------------------------------------------
    cout << "\nISSUE 2 - implicit conversion to int:" << endl;
    cout << "  cout << m1 prints " << m1
         << " (the int, not the word 'lunch')" << endl;

    int x = m1 + 5;           // compiles fine — but what does this mean?
    cout << "  m1 + 5 = " << x << "  (arithmetic on an enum, likely a bug)" << endl;

    if (m1 == 1)              // comparing a Meal to a raw int — allowed
        cout << "  (m1 == 1) is true — Meal compared to a raw int" << endl;

    // Worst of all: two unrelated enums can be compared, since both are ints.
    Snack s1 = fries;
    if (m1 == s1)             // comparing a Meal to a Snack — compiles!
        cout << "  m1 == s1 : a Meal compared equal to a Snack (bug!)" << endl;

    //--------------------------------------------------------------------------
    // ISSUE 4: Enums do not store their names as strings.
    // There is no built-in way to print 'lunch'; you only get the int.
    //--------------------------------------------------------------------------
    cout << "\nISSUE 4 - no name-to-string built in:" << endl;
    cout << "  Printing m1 gives " << m1
         << ", not the text \"lunch\" — you must map it yourself." << endl;

    cout << "\nSee 1c1_enum_classes.cpp for how enum class fixes issues 1-3." << endl;

    return 0;
}

/*

##############################################Extra Notes#####################################################

Issues with plain (unscoped) enums:

1. Names leak into the enclosing scope.
   - Enumerators like 'lunch' become visible in the surrounding scope, so two
     enums that share a name (e.g. a 'lunch' in Meal and in Snack) clash.

2. Implicit conversion to int.
   - A plain enum silently decays to its integer value, allowing meaningless
     arithmetic (m1 + 5) and comparisons (m1 == 1, or even Meal == Snack).

3. No control over the underlying type (pre-C++11) and cannot be forward-declared.
   - A plain enum's size/underlying integer type was implementation-defined, so
     the compiler could not know its size ahead of the full definition.

4. Enums (plain OR scoped) do NOT store their names as strings.
   - Printing the text 'lunch' requires a manual mapping (a switch or a lookup array).
   - This one is NOT fixed by enum class; it applies to both.

--> The fixes for issues 1-3 are demonstrated in 1c1_enum_classes.cpp.

*/
