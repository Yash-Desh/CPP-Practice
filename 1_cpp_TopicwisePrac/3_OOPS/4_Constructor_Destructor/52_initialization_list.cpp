// Author : Yash Deshpande
// Date : 10-02-2022

#include <iostream>
using namespace std;

/*

Syntax for initialization list in constructor:

constructor (argument-list) : initilization-section
{
    assignment + other code;
}


*/
class Test
{
    int a; // a is declared 1st & hence will be initialized first
    int b; // b is declared 2nd & hence will be initialized later

public:

    // Test(int i, int j) : a(i), b(j) --> This works perfectly
    // Test(int i, int j) : a(i), b(2 * j) --> This works perfectly

    Test(int i, int j) : b(j), a(i+b) // -->This will give a garbage value to a since a is initialized first 
                                           //irrespective of the order in which it is written here 
    
    // Test(int i, int j) : a(i), b(a + j) --> This works perfectly
    
    // Test(int i, int j) : a(i), b(j)  //Standard declaration
    {
        cout << "Constructor executed"<<endl;
        cout << "Value of a is "<<a<<endl;
        cout << "Value of b is "<<b<<endl;
    }
};

int main()
{
    Test t(4, 6);

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. The initialization list in constructors is another concept of initializing the data members of the class. 

2. A constructor is written first and then the initializations section is written

4. In the initialization section, the data members are initialized

5. To note here is that if we use the code shown to initialize data members --> Test(int i, int j) : b(j), a(i+b)
   the compiler will throw an error because the data member “a” is being initialized first and the “b” is being 
   initialized second so we have to assign the value to “a” data member first.

*/

/*
################################################################################################################
INITIALIZER LIST vs. NORMAL (BODY ASSIGNMENT) - SUMMARY NOTES
Model : Claude Opus 4.8
Date  : 02-07-2026
(All points below were verified by compiling & running example code with g++ 13.3.0)
################################################################################################################

The two styles:

    // Style 1 - assignment inside the body (the "normal" way)
    Test(int i, int j) {
        a = i;      // assignment
        b = j;
    }

    // Style 2 - initializer list (the part between ':' and '{')
    Test(int i, int j) : a(i), b(j) {
        // body can be empty
    }

----------------------------------------------------------------------------------------------------------------
KEY IDEA: Members are ALWAYS built BEFORE the constructor body's first line runs.
The only question is HOW they get built:
    - Initializer list  -> the member is built DIRECTLY with your value          (ONE step)
    - Body assignment   -> the member is first built with a DEFAULT value,
                           then OVERWRITTEN by the assignment                     (TWO steps)

So body assignment can do wasted work. For int/pointers this waste is negligible,
but for heavy members (std::string, std::vector, other classes) the list is faster.

----------------------------------------------------------------------------------------------------------------
WHEN THE INITIALIZER LIST IS REQUIRED (body assignment simply won't compile):
    1. const members        -> can never be changed, so assignment is illegal.
    2. reference members    -> a reference must be bound when created; can't be reseated later.
    3. members with NO default constructor -> can't be default-built first.

----------------------------------------------------------------------------------------------------------------
GOTCHA - INITIALIZATION ORDER (demonstrated above with a(i+b)):
    Members are initialized in the order they are DECLARED in the class,
    NOT the order written in the initializer list.
    => Always write the list in the same order the members are declared.

----------------------------------------------------------------------------------------------------------------
QUICK COMPARISON:

    Aspect                          | Body assignment        | Initializer list
    --------------------------------|------------------------|-------------------------
    How members get values          | default-built, then    | built directly (1 step)
                                    | overwritten (2 steps)  |
    Efficiency for heavy members    | slower                 | faster
    Works for const members         | No (compile error)     | Yes
    Works for reference members     | No                     | Yes
    Works w/o a default constructor | No                     | Yes
    Order of execution              | order of statements    | order of DECLARATION

----------------------------------------------------------------------------------------------------------------
TAKEAWAY: Prefer the initializer list by default. It is the only style that works in
ALL situations (const, references, no-default-ctor members) and is never slower.
################################################################################################################
*/

