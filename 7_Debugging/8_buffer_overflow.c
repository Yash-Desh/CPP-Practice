// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/7mKfWrNQcj0?si=Dnie0iZ10v7hwIqn)

// Run Commands
// 1) ./a.out wrong Jacob                   --> Password Error
// 2) ./a.out passw0rd 0123456789abcd       --> Password Correct
// 3) ./a.out passw0rd 0123456789abcdef     --> Password Error!!!
// 4) ./a.out Jacob 0123456789abcdefJacob   --> Password Correct!!!

// Use: objdump -t ./a.out      --> To check the symbol table, determine the addresses of the variables

// Solution to Buffer Overflows: Check the input that is provided to your program
// Replace strcpy to strncpy
// Check the length of the string before copying. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 10

char buffer[BUFFERSIZE] = "message";
char password[BUFFERSIZE] = "passw0rd";

int main(int argc, char** argv) {
    
    if(argc != 3) {
        printf("usage %s <password> <string_to_compare>", argv[0]);
        exit(1);
    }

    // Copy message into the buffer. 
    strcpy(buffer, argv[2]);

    // Compare Password. 
    if(strcmp(argv[1], password) == 0) {
        printf("Password Correct\n");
        printf("MSG: %s\n", buffer);
    }
    else {
        printf("Password Error\n");
    }
    return 0;
}