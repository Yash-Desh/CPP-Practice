// Author : Yash Deshpande
// Date : 10-02-2022

#include <iostream>
using namespace std;


/*

##################################################
Compile Time (Static Binding) : Method Hiding
##################################################

This file was previously (mis)named "Compile Time Function Overriding".
That is NOT a real concept. Because say() is NOT virtual, a same-name method
in the derived class HIDES (shadows) the base class method. Which function
runs is decided at COMPILE TIME from the STATIC TYPE of the variable.

True function overriding needs 'virtual' and is a RUNTIME polymorphism concept
(resolved via the vtable). See the corrective note at the bottom of this file.

*/

class B{
    public:
        void say(){
            cout<<"Hello world"<<endl;
        }
};

class D: public B{
    int a;
    
    // D's say() HIDES (shadows) the base class's say() -- NOT overriding, since it is not virtual
    public:
        void say()
        {
            cout << "Hello my beautiful people" << endl;
        }
};


int main()
{
    // Ambibuity 2
    B b;
    b.say();

    D d;
    d.say();

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. Both “B” and “D” classes have the same function “say”. When you call say() on a D object, name lookup finds
   D::say() first and STOPS, so B::say() is HIDDEN (shadowed) and never considered. This is method hiding, not
   overriding. (Note: once D declares say(), ALL base say() overloads are hidden, even ones with different parameters.)

2. But if the function “say” was not present in the class “D” then name lookup continues into the base class and
   B::say() is used instead.

3. CORRECTIVE NOTE : this is method hiding, NOT function overriding
   [Note added by Claude Opus 4.8, 11-07-2026]

    - "Compile-time function overriding" is NOT a real C++ concept. The old
      file name was a misnomer, so this file was renamed to
      "63_Method_Hiding_Static_Binding.cpp".

    - What actually happens here: say() is NOT virtual, so D::say() simply
      HIDES (shadows) B::say(). The call is resolved at COMPILE TIME based on
      the STATIC TYPE of the variable (b is a B, d is a D). This is called
      static binding / early binding.

    - This is NOT overriding. True overriding requires 'virtual' and only
      shows through a base pointer/reference, resolved at RUNTIME via the
      vtable (dynamic binding). Proof:

          B* ptr = &d;
          ptr->say();   // prints "Hello world"  -> proves it is NOT overriding
                        // if say() were virtual, it would print D's message

    - Terminology quick map:
          same name, non-virtual, in derived class  --> method hiding (compile time)
          same name, virtual, in derived class       --> overriding (runtime)
          same name, different parameters            --> overloading (compile time)

*/