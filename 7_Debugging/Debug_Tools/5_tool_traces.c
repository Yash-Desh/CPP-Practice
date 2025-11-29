// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/2AmP7Pse4U0?si=gg4BTFK-XSJIYCjt)

// strace Usage: strace ./a.out
// ltrace Usage: ltrace ./a.out

// System Call: When a process requests something from the OS.
// Library Call: Calls that a process makes into an existing library. 
//               A library call could call a system call, but that is based on its functionality.
//               libc is the standard c library


#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello World\n");
    return 0;
}