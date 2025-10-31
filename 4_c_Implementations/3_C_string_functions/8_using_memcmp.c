// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : GFG (https://www.geeksforgeeks.org/c/memcmp-in-c/)

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int main()
{
    int s1[] = {10, 20, 30, 40};
    int s2[] = {10, 20, 35, 40};

    // Compare first sizeof(s1) bytes of s1 and s2
    int res = memcmp(s1, s2, sizeof(s1));

    if (res == 0)
        printf("Arrays are identical");
    else
        printf("Arrays differ");

    return 0;
}