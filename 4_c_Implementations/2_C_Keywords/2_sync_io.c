// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/wJGd7tKF2zY?si=hoRqjhXWAwvlc1bf)

/*
This is part-1 on the topic of asynchronous I/O.
This file demonstrates synchronous I/O.
This I/O could be made asynchronous using
1. threads 
2. async I/O   --> our focus for this series.

CHECK out the part-2, for how to do the same thing in an 
asynchronous manner.

*/

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 25000

int main(int argc, char** argv) {
    int ret;
    FILE* fp;

    if(argc < 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buf[BUFSIZE];
    ret = fread(buf, sizeof(char), BUFSIZE, fp);
    fclose(fp);

    if(ret > 0) {
        printf("Got %d bytes\n", ret);
    }
    else {
        printf("READ FAILED\n");
    }


    return 0;
}