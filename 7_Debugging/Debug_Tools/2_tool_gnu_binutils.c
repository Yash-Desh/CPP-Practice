// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/bWMIpHVRFUo?si=G8w5iwZHvqASCrBM)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
How to Inspect Compiled Binaries (binutils) // Sometimes it's useful to examine 
the executables that your compiler (or someone else's compiler) created. 
This video shows you how to inspect your compiled binaries, using gnu binutils, like objdump. 
*/

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