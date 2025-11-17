// Author: Yash Deshpande
// Date  : 15-11-2025
// Tutor : Mike Shah (https://youtu.be/DblCoI8oAfQ?si=7Bna_v4jJ7D2IpYC)

// 4 types of pointer pitfalls ---------------------------
// 1. NULL pointer dereference
// 2. Memory Leaks
// 3. Dangling Pointer
// 4. Double Free
// --------------------------------------------------------

#include <iostream>
using namespace std;

// Utility function for Pitfall-3
// int* returnMemory() {
//     int result = 42;
//     return &result;
// }

int main() {
    // // 1. Dereferencing a Null Pointer
    // // Use gdb to detect this.
    // int* ptr = nullptr;
    // *ptr = 42;                                       // Segmentation fault (core dumped)

    // // 2. Memory Leaks
    // // Use valgrind/address sanitizer to detect the amount of memory lost.
    // // g++ -fsanitize=address 6k_Pointer_Pitfalls.cpp           --> command for address sanitizer.
    // int* array = new int[1000];

    // // 3. Dangling Pointer
    // int *px = returnMemory();
    // std::cout << "*px = " << *px << std::endl;       // Segmentation fault (core dumped)


    // 4. Double Free
    int* x = new int;
    *x = 42;
    
    delete x;
    delete x;                                        // free(): double free detected in tcache 2
                                                     // Aborted (core dumped)


    return 0;
}