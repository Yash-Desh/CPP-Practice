// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/tEbV21aPSKw?si=bWeLXZRKXdLItddI)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Here we use AddressSanitizer to detect a buffer overflow.

// Compilation Command: gcc -fsanitize=address ./6_tool_address_sanitizer.c

#define NUMLETTERS 26

int main() {
    
    // Static Allocation. 
    char somechars[NUMLETTERS];
    for(int i=0; i<NUMLETTERS; i++) {
        somechars[i] = 'a' + i;
    }

    // Smart compilers like clang will warn you about the buffer overflow.
    // printf("An element: %c\n", somechars[50]);

    // Even clang will not detect this.
    int idx = 50;
    printf("An element: %c\n", somechars[idx]);

    return 0;
}

/*

=================================================================
==136200==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x76aafa900052 at pc 0x60cf5f9843a2 bp 0x7fff40fd0860 sp 0x7fff40fd0850
READ of size 1 at 0x76aafa900052 thread T0
    #0 0x60cf5f9843a1 in main (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x13a1) (BuildId: b77391d676e7dff3981edffa80d5de773430b368)
    #1 0x76aafc82a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #2 0x76aafc82a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #3 0x60cf5f984184 in _start (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x1184) (BuildId: b77391d676e7dff3981edffa80d5de773430b368)

Address 0x76aafa900052 is located in stack of thread T0 at offset 82 in frame
    #0 0x60cf5f984258 in main (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x1258) (BuildId: b77391d676e7dff3981edffa80d5de773430b368)

  This frame has 1 object(s):
    [32, 58) 'somechars' (line 18) <== Memory access at offset 82 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x13a1) (BuildId: b77391d676e7dff3981edffa80d5de773430b368) in main
Shadow bytes around the buggy address:
  0x76aafa8ffd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa8ffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa8ffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa8fff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa8fff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x76aafa900000: f1 f1 f1 f1 00 00 00 02 f3 f3[f3]f3 00 00 00 00
  0x76aafa900080: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa900100: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa900180: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa900200: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x76aafa900280: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==136200==ABORTING


*/