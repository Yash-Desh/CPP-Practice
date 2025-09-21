// Author: Yash Deshpande
// Date  : 16-09-2025
// Tutor : Code with Harry

#include <stdio.h>
#include <stdlib.h>

int main() {

    // // ################# Reading a single character #################
    // FILE *ptr1 = NULL;
    // ptr1 = fopen("read_text_file.txt", "r");

    // char c1 = fgetc(ptr1);
    // printf("Character read from the file is : %c\n", c1);   // T

    // char c2 = fgetc(ptr1);
    // printf("Character read from the file is : %c\n", c2);   // h

    // fclose(ptr1);

    
    // // ################# Reading a single string #################
    // FILE *ptr2 = NULL;
    // ptr2 = fopen("read_text_file.txt", "r");

    // char read_buffer[100]; 
    // int read_size = 4;
    // fgets(read_buffer, read_size, ptr2);
    // printf("String read from the file is : %s\n", read_buffer);   // Thi\0

    // fclose(ptr2);

 
    // // ################# Writing a single character #################
    // FILE *ptr3 = NULL;
    // ptr3 = fopen("write_text_file.txt", "w");

    // char ch = 'a'; 
    // fputc(ch, ptr3);

    // fclose(ptr3);



    // ################# Writing a single string #################
    FILE *ptr4 = NULL;
    ptr4 = fopen("write_text_file.txt", "w");

    char write_buffer[100] = "This is to demonstrate the use of fputs()"; 
    fputs(write_buffer, ptr4);

    fclose(ptr4);


    return 0;
}

/*
################################### NOTES ###################################

Each call to fgetc reads the next char

*/