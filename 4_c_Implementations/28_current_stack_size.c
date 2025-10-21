#include <stdio.h>

// A recursive function to demonstrate stack usage
void recursive_function(int depth) {
    char local_var; // A local variable to get its address

    if (depth == 0) {
        printf("Base of recursion: Address of local_var = %p\n", (void*)&local_var);
        return;
    }

    // Print address of local_var in each call
    printf("Depth %d: Address of local_var = %p\n", depth, (void*)&local_var);
    recursive_function(depth - 1);
}

int main() {
    char main_local_var; // A local variable in main

    printf("Address of local_var in main: %p\n", (void*)&main_local_var);
    recursive_function(5); // Call the recursive function

    // You can compare the address of main_local_var with the address in the deepest recursive call
    // to get a rough idea of the stack usage for that call chain.

    return 0;
}