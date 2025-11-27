// Author: Yash Deshpande
// Date  : 16-11-2025
// Tutor : Mike Shah (https://youtu.be/8JEEYwdrexc?si=ABZBol-EHC9sCxpX)

// Always use -g to help the compiler insert extra information
// Compile with: gcc -g 2_valgrind_gdb_tutorial.c -o prog
// Run with: ./prog
//
// Find Errors with: valgrind ./prog
// Debug with: gdb ./prog --tui

#include <stdlib.h>
#include <stdio.h>

void bar() {
    int* p = NULL;
    p = malloc(sizeof(int));
    *p = 42;        // Expect a seg fault here
}

void foo() {
    bar();
}

int main() {
    foo();          // Segmentation fault (core dumped)
    return 0;
}