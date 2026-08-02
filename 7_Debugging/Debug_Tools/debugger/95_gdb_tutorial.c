// Author: Yash Deshpande
// Date  : 15-11-2025
// Tutor : Mike Shah (https://youtu.be/MTkDTjdDP3c?si=iMa-ji9BSismO6LG)

// Tip-1: Enable all warnings as errors
// gcc -Wall -Werror file_name.c 

// Tip-2: Enable Degug infor for gdb
// gcc -g file_name.c

// Tip-3: objdump gives symbol table
// objdump -t ./a.out

#include <stdio.h>

int* px = NULL;

void foo() {
    printf("foo\n");
    *px = 7;
}

int main() {
    char* name = "Mike";
    char* name2 = "Shah";
    printf("my name is : %s\n", name);

    foo();
    name = name2;
    return 0;
}