// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/MruzHlXqspU?si=81iPKYeiVNL9UQtD)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MSGLENGTH 1024
#define BUFFERLENGTH 100
#define REPEATS 3

// QUIZ: What happens when you delete an open file from which you are reading data ? 
// 1. Error
// 2. OS intervenes & prevent the delete since we are reading the file.

// ANS: The file got deleted on calling the remove() call, but we were still able to
// print the 2nd chunk. 
// Explanation: Once you call the delete, the directory entry is cleared & the file is marked
// for deletion. But until some process has the file open, it has an entry in the open file table
// Thus until there's a file table entry for the file, the data blocks are not deleted from the 
// disk. As soon as the last process closes the file, the file handle/file table entry gets cleared
// & the data blocks are physically deleted from the disk. 

// The same mechanism can be seen, if you modify the contents of the file, in the middle of an operation.

int main() {

    char msg[MSGLENGTH] = "This is a very long message "
    "that keeps going and going and I really don't have "
    "much to say so I'm just going to say whatever I feel "
    "because I can. Hey, while I'm at it, why not say "
    "congrats to the Clemson Tigers on their National "
    "Football Championship. Definitely provided some nice "
    "entertainment. Sorry you had to eat fast food at the "
    "White House, but...well, stuff happens.";

    char readbuffer[BUFFERLENGTH];

    FILE* fp = fopen("deltest.txt", "w");

    // write message to the file.
    // repeat to make sure we have enough

    int bytes = 0;
    while(bytes < BUFFERLENGTH * REPEATS) {
        bytes += fwrite(msg, 1, strlen(msg), fp);
    }
    fclose(fp);
    printf("wrote %d bytes\n", bytes);


    // Time for you to see the file got created in the VS Code directory
    sleep(5);


    // --------------------------------------------- //
    fp = fopen("deltest.txt", "r");

    // read & print chunk #1
    memset(readbuffer, 0, BUFFERLENGTH);
    bytes = fread(readbuffer, 1, BUFFERLENGTH, fp);
    printf("read first %d bytes\n\n%s\n\n", bytes, readbuffer);


    // now halfway through delete the file
    remove("deltest.txt");

    // read & print chunk #2
    memset(readbuffer, 0, BUFFERLENGTH);
    bytes = fread(readbuffer, 1, BUFFERLENGTH, fp);
    printf("read first %d bytes\n\n%s\n\n", bytes, readbuffer);

    fclose(fp);

    return 0; 
}