// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/IZiUT-ipnj0?si=yhLtmT4ZFJTOPHXe)

// Topic: Error Handling using stderr, errno, perror, strerror
// 1. Usage Failure
// 2. Syscall Failure using errno
// 3. Error-handling macros
// Study this file in the above given order.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// Error-Handling Macros
// Macros are able to print Line Numbers & File Names
// Normal Functions will not be able to to do that.
#define CHECK(x) ({int __val = (x); (__val == -1 ? \
                ({fprintf(stderr, "ERROR (" __FILE__ ":%d) -- %s\n", __LINE__, strerror(errno)); \
                exit(-1); -1;}) : __val); })

int main(int argc, char** argv) {

    // 1. Usage Check : Check for the right number of arguments
    if(argc != 2) {
        fprintf(stderr, "usage %s <filename>\n", argv[0]);
        exit(-1);
    }

    // open a file.
    int fd;
    // fd = open(argv[1], O_RDONLY);

    // 2. Check syscall failure
    // if(fd == -1) {
    //     // Option-1
    //     // fprintf(stderr, "errno = %i & error = %s\n", errno, strerror(errno));

    //     // Option-2
    //     perror("open syscall failed");
    //     exit(-1);
    // }

    // Option-3
    CHECK(fd = open(argv[1], O_RDONLY));

    // reads the contents & prints them out to stdout
    char c;
    // while(read(fd, &c, 1) > 0) {
    while(CHECK(read(fd, &c, 1)) > 0) {
        fputc(c, stdout);
    }

    // close the file
    close(fd);
    return 0;
}