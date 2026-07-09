// Author : Yash Deshpande
// Date : 01-04-2022

#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize (struct Rectangle *ptr1, int l , int b)   // sets the length & breadth of the struct Rectangle
{
    ptr1->length = l;
    ptr1->breadth = b;
}

int area (struct Rectangle r)   // Calculates the area of the rectangle
{
    return r.length * r.breadth;
}

void changeLength (struct Rectangle *ptr2, int len)  // Changes the length of the struct
{
    ptr2->length = len;
}
int main()
{
    struct Rectangle r;
    // Note (added 08-07-2026, Claude Opus 4.8): 'r' is a local (automatic) variable with no
    // constructor, so its members 'length' and 'breadth' are NOT default-initialized here.
    // They hold indeterminate (garbage) values until initialize() assigns them below.
    // (Use 'struct Rectangle r{};' to zero-initialize, or 'struct Rectangle r{15, 10}' to set explicit values.)
    initialize(&r, 15,10);
    area(r);
    changeLength(&r, 20);
    
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. main() has no instructions of itself apart from calling other functions. This is the style of programming in
   the C language.

2. passed by value where values inside the struct are not modified and passed by address when values inside the 
   struct are to be modified by the function.  

3. Initialization of 'struct Rectangle r' (members 'length' & 'breadth'):

   Declaration                    | length  | breadth
   -------------------------------|---------|---------
   struct Rectangle r;            | garbage | garbage
   struct Rectangle r{};          | 0       | 0
   struct Rectangle r{15, 10};    | 15      | 10

   - A local (automatic) variable like 'struct Rectangle r;' is NOT default-initialized, so its
     members hold indeterminate (garbage) values until assigned.
   - However, if 'r' were declared as a GLOBAL variable instead, both members would be automatically
     zero-initialized (length = 0, breadth = 0). This is because objects with static storage duration
     are zero-initialized by default, unlike automatic (stack) variables.


*/