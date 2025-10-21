// Tutor : Gemini


#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

// Global variable to store the stack base address (approximated)
static void *stack_base_address = NULL;
// Global variable to store the number of recursive calls
static volatile int recursion_depth = 0;
// Jump buffer for longjmp to recover from the signal
static jmp_buf jump_buffer;

// Signal handler for SIGSEGV (segmentation fault)
void segv_handler(int signum) {
    if (signum == SIGSEGV) {
        printf("Stack Overflow detected after %d recursive calls.\n", recursion_depth);
        // Estimate stack size: (recursion_depth * size_of_stack_frame)
        // This is a rough estimation as stack frame size can vary.
        // For a simple function with minimal local variables, it might be
        // a few bytes (e.g., return address, saved registers, local variable).
        // Let's assume a typical frame size of 64 bytes for estimation.
        size_t estimated_stack_size = (size_t)recursion_depth * 64;
        printf("Estimated stack size: %zu bytes (assuming ~64 bytes per frame).\n", estimated_stack_size);
        longjmp(jump_buffer, 1); // Jump back to main
    }
}

// Recursive function to consume stack space
void recursive_overflow(int depth) {
    volatile char local_var[1]; // Allocate a small local variable to ensure stack frame
    recursion_depth = depth;
    recursive_overflow(depth + 1);
}

int main() {
    // Set up the signal handler for segmentation faults
    signal(SIGSEGV, segv_handler);

    // Get an approximate stack base address (address of a local variable in main)
    volatile char main_local_var;
    stack_base_address = (void *)&main_local_var;

    // Use setjmp to create a recovery point after the signal
    if (setjmp(jump_buffer) == 0) {
        printf("Attempting to overflow the stack...\n");
        recursive_overflow(0); // Start the recursive calls
    } else {
        printf("Program recovered from stack overflow.\n");
    }

    return 0;
}

/*
Determining the exact stack size programmatically in C by overflowing it is an indirect and platform-dependent approach, often leading to a program crash (segmentation fault) rather than a precise measurement. This method leverages the fact that a stack overflow occurs when the stack pointer attempts to write beyond the allocated stack memory region.
Here's a conceptual approach using a recursive function to cause a stack overflow and estimate the stack size:

Explanation:
segv_handler: This function is registered as a signal handler for SIGSEGV (segmentation fault), which is typically triggered by a stack overflow. When a stack overflow occurs, this handler will be invoked.
recursive_overflow: This function calls itself recursively, allocating a small local variable in each call. This consumes stack space with each invocation. The volatile keyword prevents the compiler from optimizing away the local variable, ensuring a stack frame is created.
main function:
It registers the segv_handler for SIGSEGV.
It uses setjmp to create a jump point. If a SIGSEGV occurs within recursive_overflow, longjmp in the signal handler will transfer control back to this setjmp point.
It calls recursive_overflow(0) to initiate the stack overflow process.
When the overflow happens, segv_handler is called, prints the estimated stack size based on the recursion_depth, and then uses longjmp to return to main.


Limitations and Considerations:
Estimation, Not Exact Measurement: This method provides an estimation of the stack size. The actual stack frame size for each function call can vary depending on the compiler, optimization levels, and the architecture. The assumption of "64 bytes per frame" is a rough guess.
Platform Dependence: Stack size and how it's handled are highly platform and OS-dependent. The default stack size can be configured by the operating system or linker settings.
Program Crash: This method relies on causing a program crash (segmentation fault) to detect the overflow. While setjmp/longjmp can help recover, it's not a standard or recommended way to determine stack size in production code.
Alternative Methods: For more accurate stack size determination, especially in embedded systems or specific environments, tools provided by the operating system (e.g., ulimit -s on Linux) or compiler-specific extensions might be more appropriate. In some cases, analyzing the compiled assembly code can reveal stack frame sizes.

*/