// Author: Yash Deshpande
// Date  : 28-11-2025
// Tutor : Jack Sorber (https://youtu.be/A0A19LQKOjM?si=aax1mUi0ySfRgR4Q)

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

// Suppose you don't give any filename in the cli arguments
// Or you give the name of a non_existant file.
// Then what does this program do ? 

// The part of the code that is commented out is the solution, i.e.
// TO CHECK YOUR RETURN VALUES. 

#define BUFFERSIZE 50

int main(int argc, char **argv) {

    int fd = open(argv[1], O_RDONLY);                       // open returns -1
    char buffer[BUFFERSIZE];
    int bytesread;

    // -------------- Keep Commented -------------- //
    // if(fd == -1) {
    //     printf("file not found or failed to open\n");
    //     exit(1);
    // }
    // -------------------------------------------- //

    while ((bytesread = read(fd, buffer, BUFFERSIZE))) {    // read takes fd = -1 & hence returns -1
        dprintf(STDOUT_FILENO, "Chunk (%d): ", bytesread);
        write(STDOUT_FILENO, buffer, bytesread);
        dprintf(STDOUT_FILENO, "\n");                       // while continues till it gets a 0
    }                                                       // Program reads & prints garbage. 

    close(fd);
}
