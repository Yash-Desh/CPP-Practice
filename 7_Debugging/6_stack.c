// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/jVzSBkbfdiw?si=wLPRDLhMAYIVlMId)

#include <stdio.h>
#include <stdlib.h>

int myfunction(int counter) {
    int result = 5;
    printf("myfunction %p %p %p\n", &result, &counter, __builtin_frame_address(0));
    return 0;
}

int main() {
    int i;
    printf("main %p %p\n", &i, __builtin_frame_address(0));

    myfunction(4);
    return 0;
}