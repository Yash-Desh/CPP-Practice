// Author : Yash Deshpande
// Date   : 10-09-2025
// Tutor  : GFG

#include <stdio.h>

#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

int main() {
    double x;
    printf("%ld", my_sizeof(x));        // ld = long int
    getchar();
    return 0;
}

/*

You can also implement using the function instead of a macro, 
but function implementation cannot be done in C as C doesn't 
support function overloading and sizeof() is supposed to receive parameters of all data types. 

Note that the above implementation assumes that the size of character is one byte.


*/ 