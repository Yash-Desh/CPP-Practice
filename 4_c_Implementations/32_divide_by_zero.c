#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 15;
    printf("%d\n", x/0);        // Floating point exception (core dumped)
    return 0;
}