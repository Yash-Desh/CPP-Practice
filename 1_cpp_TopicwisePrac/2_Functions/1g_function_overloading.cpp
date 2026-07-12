// Author : Yash Deshpande
// Date : 25-01-2022

#include<iostream>
using namespace std;

int sum(float a, int b){
    cout<<"Using function with 2 arguments"<<endl;
    return a+b;
}

int sum(int a, int b, int c){
    cout<<"Using function with 3 arguments"<<endl;
    return a+b+c;
}

// Calculate the volume of a cylinder
int volume(double r, int h){
    return(3.14 * r *r *h);
}

// Calculate the volume of a cube
int volume(int a){
    return (a * a * a);
}

// Rectangular box
int volume (int l, int b, int h){
    return (l*b*h);
}

/*
=================================================================================
                        RULES FOR FUNCTION OVERLOADING
=================================================================================

The compiler distinguishes overloads using the SIGNATURE, which is:
        function name + parameter list (types, number, order)

--> The RETURN TYPE is NOT part of the signature.

---------------------------------------------------------------------------------
1. FUNCTION NAME  -> Must be IDENTICAL across all overloads.
                     (If the name differs, it is just a different function.)

2. PARAMETERS     -> This is what MUST differ. Overloads can differ by:
                        a) Number of parameters
                        b) Type of parameters
                        c) Order of parameter types

3. RETURN TYPE    -> Cannot be used to overload ON ITS OWN.
                     It may differ, but only when the parameters already differ.
=================================================================================
*/

// ------------------------ 2a) Different NUMBER of parameters ------------------------
void print(int a){
    cout<<"print(int) -> "<<a<<endl;
}
void print(int a, int b){
    cout<<"print(int, int) -> "<<a<<", "<<b<<endl;
}

// ------------------------ 2b) Different TYPE of parameters --------------------------
void show(int x){
    cout<<"show(int) -> "<<x<<endl;
}
void show(double x){
    cout<<"show(double) -> "<<x<<endl;
}
void show(char x){
    cout<<"show(char) -> "<<x<<endl;
}

// ------------------------ 2c) Different ORDER of parameter types --------------------
void mix(int a, double b){
    cout<<"mix(int, double) -> "<<a<<", "<<b<<endl;
}
void mix(double a, int b){
    cout<<"mix(double, int) -> "<<a<<", "<<b<<endl;
}

// ------------------------ 3) RETURN TYPE may differ (only if params differ) ---------
int    process(int x){
    cout<<"process(int) returns int"<<endl;
    return x;
}
double process(double x){
    cout<<"process(double) returns double"<<endl;
    return x;
}

/*
=================================================================================
                    WHAT DOES *NOT* COUNT AS AN OVERLOAD
                (Uncommenting any block below causes a COMPILE ERROR)
=================================================================================

// (i) Differ ONLY by return type -> ERROR
//     Ambiguous: on a call like getValue(); the compiler can't pick one.
int    getValue();
double getValue();          // ERROR: redefinition, differs only by return type


// (ii) Top-level const on a by-value parameter -> IGNORED, same signature
void f(int x);
void f(const int x);        // ERROR: top-level const ignored for by-value params
//   NOTE: const on a POINTER/REFERENCE TARGET *does* count and IS a valid overload:
//         void f(int* p);  vs  void f(const int* p);   // OK


// (iii) Typedef / alias of the same type -> same type, same signature
typedef int MyInt;
void g(int x);
void g(MyInt x);            // ERROR: MyInt IS int


// (iv) Differ ONLY by default arguments -> same signature (+ ambiguous calls)
void h(int a, int b);
void h(int a, int b = 5);   // ERROR: same signature as h(int, int)

=================================================================================
*/

int main(){
    cout<<"The sum of 3 and 6 is "<<sum(3,6)<<endl;
    cout<<"The sum of 3, 7 and 6 is "<<sum(3, 7, 6)<<endl;
    cout<<"The volume of cuboid of 3, 7 and 6 is "<<volume(3, 7, 6)<<endl;
    cout<<"The volume of cylinder of radius 3 and height 6 is "<<volume(3, 6)<<endl;
    cout<<"The volume of cube of side 3 is "<<volume(3)<<endl;

    cout<<"\n--- 2a) Different NUMBER of parameters ---"<<endl;
    print(10);
    print(10, 20);

    cout<<"\n--- 2b) Different TYPE of parameters ---"<<endl;
    show(65);
    show(3.14);
    show('A');

    cout<<"\n--- 2c) Different ORDER of parameter types ---"<<endl;
    mix(1, 2.5);
    mix(2.5, 1);

    cout<<"\n--- 3) RETURN TYPE differs (allowed because params differ) ---"<<endl;
    process(5);
    process(5.5);

    return 0;
}

/*

##############################################Extra Notes#####################################################

                                    SUMMARY TABLE

+-----------------------------------+------------------------------------------------+
| Element                           | Rule for overloading                           |
+-----------------------------------+------------------------------------------------+
| Function name                     | Must be the SAME                               |
| Number of parameters              | May differ                              [YES]  |
| Type of parameters                | May differ                              [YES]  |
| Order of parameter types          | May differ                              [YES]  |
| Return type                       | Ignored - cannot overload on it alone   [NO]   |
| Top-level const on value params   | Ignored - not a valid difference        [NO]   |
| Default arguments                 | Not a valid difference                  [NO]   |
+-----------------------------------+------------------------------------------------+

ONE-LINE TAKEAWAY:
    Overloading depends ONLY on the parameter list (count, types, order).
    The name must match, and the return type is irrelevant to resolution.

*/
