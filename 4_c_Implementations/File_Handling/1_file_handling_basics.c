// Author: Yash Deshpande
// Date  : 16-09-2025
// Tutor : Code with Harry

#include <stdio.h>
#include <stdlib.h>

int main() {

    // // ################# Reading a file #################
    // // Open a text file to read.
    // FILE *ptr = NULL;
    // ptr = fopen("read_text_file.txt", "r");
    
    // // Read from file.
    // char read_buffer[34];
    // fscanf(ptr, "%s", read_buffer);
    // printf("Content Read from file : %s", read_buffer);   

    // /*
    // Program Output :
    // Content Read from file : This
    // */

    // fclose(ptr);

    // // ################# Writing to a file #################
    // FILE *ptr2 = NULL;
    // ptr2 = fopen("write_text_file.txt", "w");

    // char write_buffer[100] = "This line will be written to a file.\n";
    // fprintf(ptr2, "%s", write_buffer);

    // // Write once more
    // char write_buffer2[100] = "This is the 2nd line.\n";
    // fprintf(ptr2, "%s", write_buffer2);

    // fclose(ptr2);

    // /*
    // Program Output :
    // This line will be written to a file.
    // This is the 2nd line.
    // */

    
    // ################# Appending to a file #################
    FILE *ptr3 = NULL;
    ptr3 = fopen("append_text_file.txt", "a");

    char append_buffer[100] = "NEW CONTENT: This line is newly written to a file.";
    fprintf(ptr3, "%s", append_buffer);

    fclose(ptr3);

    return 0;
}

/*
################################### NOTES ###################################


*/