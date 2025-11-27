// Author : Yash Deshpande
// Date   : 25-09-2025
// Tutor  : Neso Academy, https://www.geeksforgeeks.org/c/structure-member-alignment-padding-and-data-packing/

#include <stdio.h>
#include <stdlib.h>

// Assumption : We have 32-bit architecture hence word size = 4 bytes
// The struct’s size must be a multiple of the largest alignment requirement (eg 8 bytes for double, 4-bytes for int).

struct abc1 {
    char a;         // 1 byte
    char b;         // 1 byte
    int c;          // 4 bytes
};

struct abc2 {
    char a;         // 1 byte
    int c;          // 4 bytes
    char b;         // 1 byte
};

struct abc3 {
    char a;         // 1 byte
};

typedef struct structc_tag {
    char c;
    double d;
    int s;
} structc_t;


// NVIDIA
struct test_struct {
    char a;
    char *p;
    int i;
};

// NVIDIA Mod
struct test_struct_mod {
    char a;
    int b;
    int i;
    char *p;
};

int main() {
    struct abc1 s1;
    printf("Size of struct abc1 is %ld bytes\n", sizeof(s1));       // 8 bytes

    struct abc2 s2;
    printf("Size of struct abc2 is %ld bytes\n", sizeof(s2));       // 12 bytes

    struct abc3 s3;
    printf("Size of struct abc2 is %ld bytes\n", sizeof(s3));       // 1 Byte

    // 8-byte alignmnet due to double
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));         // 24 bytes

    struct test_struct Nvidia;
    printf("Size of struct abc2 is %ld bytes\n", sizeof(Nvidia));   // 24 Bytes (64-bit addresses)

    struct test_struct_mod Nvidia_mod;
    printf("Size of struct abc2 is %ld bytes\n", sizeof(Nvidia_mod));   // 24 Bytes (64-bit addresses)
    printf("%p\n", &Nvidia_mod.a);
    printf("%p\n", &Nvidia_mod.b);
    printf("%p\n", &Nvidia_mod.i);

    return 0;
}