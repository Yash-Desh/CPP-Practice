// Author: Yash Deshpande
// Date  : 16-10-2025
// Tutor : ChatGPT

#include <stdio.h>
#include <stdlib.h>

struct student {
  int roll;             // 4B
  char name[100];       // 100B
  float marks;          // 4B
};

int main() {

    // 
    struct student tom;
    printf("sizof(tom) = %ld\n", sizeof(tom));

    // without using the sizeof() operator
    struct student *ptr = &tom;
    printf("sizof(tom) = %ld\n", (char*)(ptr+1)-(char*)ptr);
    return 0;
}