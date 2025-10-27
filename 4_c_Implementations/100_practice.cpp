#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define my_sizeof(value) (char*)(&value+1) - (char*)(&value)

int main() {
    int var = 10;
    if(0xFF == 0x00FF) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    return 0;
}