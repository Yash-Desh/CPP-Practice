// Author: Yash Deshpande
// Date  : 05-08-2026
// Tutor : Claude Opus 5

// #############################################################################
// Test: Will ASAN detect a buffer overflow if user inputs a size less than 20 ? 
// #############################################################################

// Compile with ASAN: gcc asan_test.c -fsanitize=address
// Run: ./a.out

#include <stdio.h>
#include <stdlib.h>

int main() {

    int arrSize;
    printf("Enter an size of array: ");
    scanf("%d", &arrSize); // Takes integer input

    int* arr = (int*)malloc(arrSize * sizeof(int));

    for(int i = 0; i < 20; i++) {
        arr[i] = 2* i;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}

/*

YES -> How ? 

Enter an size of array: 15
arr[0] = 0
arr[1] = 2
arr[2] = 4
arr[3] = 6
arr[4] = 8
arr[5] = 10
arr[6] = 12
arr[7] = 14
arr[8] = 16
arr[9] = 18
arr[10] = 20
arr[11] = 22
arr[12] = 24
arr[13] = 26
arr[14] = 28
=================================================================
==206841==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x50600000005c at pc 0x576bb9e17412 bp 0x7ffc1a07aef0 sp 0x7ffc1a07aee0
WRITE of size 4 at 0x50600000005c thread T0
    #0 0x576bb9e17411 in main (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x1411) (BuildId: 8fee4309b74b28c6bef67fcb04ab6832296808ef)
    #1 0x723b6ec2a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #2 0x723b6ec2a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #3 0x576bb9e171e4 in _start (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x11e4) (BuildId: 8fee4309b74b28c6bef67fcb04ab6832296808ef)

0x50600000005c is located 0 bytes after 60-byte region [0x506000000020,0x50600000005c)
allocated by thread T0 here:
    #0 0x723b6f0fd9c7 in malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:69
    #1 0x576bb9e1739f in main (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x139f) (BuildId: 8fee4309b74b28c6bef67fcb04ab6832296808ef)
    #2 0x723b6ec2a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x723b6ec2a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x576bb9e171e4 in _start (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x11e4) (BuildId: 8fee4309b74b28c6bef67fcb04ab6832296808ef)

SUMMARY: AddressSanitizer: heap-buffer-overflow (/home/ydeshpan/my_repos/personal/CPP-Practice/7_Debugging/Debug_Tools/memory_error_detectors/a.out+0x1411) (BuildId: 8fee4309b74b28c6bef67fcb04ab6832296808ef) in main
Shadow bytes around the buggy address:
  0x505ffffffd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x505ffffffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x505ffffffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x505fffffff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x505fffffff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x506000000000: fa fa fa fa 00 00 00 00 00 00 00[04]fa fa fa fa
  0x506000000080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x506000000100: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x506000000180: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x506000000200: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x506000000280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
==206841==ABORTING


*/ 

