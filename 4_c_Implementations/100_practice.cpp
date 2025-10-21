#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define my_sizeof(value) (char*)(&value+1) - (char*)(&value)

int main() {
    int var = 10;
    printf("%ld\n", my_sizeof(var));
    return 0;
}