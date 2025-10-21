// Author: Yash Deshpande
// Date  : 13-10-2025
// Tutor : GFG (https://www.geeksforgeeks.org/c/c-program-find-direction-growth-stack/), Gemini

// C program to check whether stack grows
// downward or upward.
#include<stdio.h>

void fun(int *main_local_addr)
{
    int fun_local;
    if (main_local_addr < &fun_local)
        printf("Stack grows upward, address increases\n");
    else
        printf("Stack grows downward, address decreases\n");
}

int main()
{
    // fun's local variable
    int main_local;

    fun(&main_local);
    return 0;
}

/*
Important Considerations:

1. Compiler Optimizations: 
While this method is generally effective, aggressive compiler optimizations 
(like inlining) might sometimes alter the expected stack behavior, potentially 
leading to inaccurate results. For critical analysis, disabling optimizations might be necessary.

2. Platform Dependence: 
The direction of stack growth is platform-dependent. Running this code on 
different architectures or operating systems may yield different results.

*/