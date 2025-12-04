// Author: Yash Deshpande
// Date  : 28-11-2025

// I list all the different segmentation faults that I come across

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>         // for INT_MAX

int* getAddress() {
    int local_var = 105;
    return &local_var;
}

int main() {

    // 1. Divide by Zero: Floating point exception (core dumped) 
    // int x = 15;
    // int y = 0;
    // int z = x/y;


    // 2. Dereferencing a NULL Pointer: Segmentation fault (core dumped)
    // int *ptr = NULL;
    // *ptr = 45;


    // Double Free: free(): double free detected in tcache 2
    //                      Aborted (core dumped)
    // int* ptr = malloc(sizeof(int));
    // *ptr = 21;
    // free(ptr);
    // free(ptr);


    // modifying a string literal   -> Segmentation fault (core dumped)
    // char my_str[50] = "Max Verstappen is a 5-time World Champion";
    // char* my_str = "Max Verstappen is a 5-time World Champion";
    // my_str[20] = '4';
    // printf("%s\n", my_str);



    // Dangling Pointer -> Segmentation fault (core dumped)
    // int* ptr = getAddress();
    // printf("Value of local variable = %d\n", *ptr);


    // ##################################### No Problem #####################################

    // 3. Dangling Pointer Use-after-free: No Issues
    // int* ptr = malloc(sizeof(int));
    // *ptr = 55;
    // free(ptr);
    // *ptr = 65;
    // printf("*ptr = %d\n", *ptr);

    // Wild Pointer: No issues
    // int* ptr;
    // *ptr = 26;
    // printf("*ptr = %d\n", *ptr);


    // Buffer Overflow

    // int arr[10] = {12};
    // arr[50] = 45;
    // printf("%d\n", arr[50]);

    // int *arr1 = (int*)malloc(sizeof(int)*10);
    // arr1[50] = 45;
    // printf("%d\n", arr1[50]);


    // Integer Overflow: No issues
    // int stress = INT_MAX;
    // stress++;
    // printf("stress = %d\n", stress);


    // Memory Leak  -> No issues
    // int* ptr = (int*)malloc(10* sizeof(int));

    // printing a null pointer
    int* ptr = NULL;
    printf("%p\n", ptr);


    return 0;
}