// Author: Yash Deshpande
// Date  : 02-11-2025
// Tutor : 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // int arr[10] = {12};
    // arr[50] = 45;
    // printf("%d\n", arr[50]);

    int *arr1 = (int*)malloc(sizeof(int)*10);
    arr1[50] = 45;
    printf("%d\n", arr1[50]);
    return 0;
}