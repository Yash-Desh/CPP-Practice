// Author: Yash Deshpande
// Date  : 17-11-2025
// Tutor : Jack Sorber (https://youtu.be/Sddn1UjzSAo?si=64pK9te6KxL-jbYY)

// Compilation: gcc -g 3_valgrind_buffer_overflow.c
// Execution  : valgrind ./a.out

// This code is used to demonstrate the use of valgrind for detecting
// 1. Memory Leaks 
// 2. Buffer Overflows

#include <stdio.h>
#include <stdlib.h>

#define NUMINTS 100

int main() {
    int* myarray = malloc(sizeof(int) * NUMINTS);   // --> memory never freed

    for(int i=0; i <= NUMINTS; i++) {               // --> buffer overflow
        myarray[i] = i;                         
    }

    printf("Done\n");
}

/*

OUTPUT

==191907== Memcheck, a memory error detector
==191907== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==191907== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==191907== Command: ./a.out
==191907== 
==191907== Invalid write of size 4
==191907==    at 0x1091A3: main (in /home/yash-desh/Code_Repos/CPP-Practice/1_cpp_TopicwisePrac/11_Debugging/a.out)
==191907==  Address 0x4a761d0 is 0 bytes after a block of size 400 alloc'd
==191907==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==191907==    by 0x10917E: main (in /home/yash-desh/Code_Repos/CPP-Practice/1_cpp_TopicwisePrac/11_Debugging/a.out)
==191907== 
Done
==191907== 
==191907== HEAP SUMMARY:
==191907==     in use at exit: 400 bytes in 1 blocks
==191907==   total heap usage: 2 allocs, 1 frees, 1,424 bytes allocated
==191907== 
==191907== LEAK SUMMARY:
==191907==    definitely lost: 400 bytes in 1 blocks
==191907==    indirectly lost: 0 bytes in 0 blocks
==191907==      possibly lost: 0 bytes in 0 blocks
==191907==    still reachable: 0 bytes in 0 blocks
==191907==         suppressed: 0 bytes in 0 blocks
==191907== Rerun with --leak-check=full to see details of leaked memory
==191907== 
==191907== For lists of detected and suppressed errors, rerun with: -s
==191907== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

*/