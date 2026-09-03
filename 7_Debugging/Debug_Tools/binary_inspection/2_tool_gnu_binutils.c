// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/bWMIpHVRFUo?si=G8w5iwZHvqASCrBM)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
The following program is just a hello world program with a few modifications
- A global variable
- A different print statement
- A conditional 'if' statement that checks the programs first argument
- A check for a preset password

=> compile with debug symbols: gcc -g 2_tool_gnu_binutils.c

This creates a binary file, cannot be opened with a normal text editor 
But can be opened with a hex editor: bless a.out

*/


int myValue = 47;

int main(int argc, char** argv) {
    if(argc <= 1) { return -1; }
    if(strcmp(argv[1], "FEEDBEEF") == 0) {
        printf("Correct\n");
    }
    else {
        printf("Incorrect\n");
    }
    return 0;
}

// Tools Discussed in this tutorial
// Hex Editor: Bless            --> can't download on WSL 
// GNU Binutils
// 1) Strings                   --> Goes through the binary, Grabs all the printable strings 
// Usage: strings ./a.out 

// 2) Symbol Table              --> Gets all the symbols/identifiers defined inside this program
// Usage: readelf --symbols ./a.out

// 3) Object Dump               --> Same as symbol table
// Usage: objdump -t ./a.out 
// Usage: objdump -s ./a.out
// Usage: objdump -d ./a.out

// 4) Individual Segments
// Usage: readelf --segments ./a.out

// 5) Strip                     --> removes symbols from your binary
// Usage: strip ./a.out