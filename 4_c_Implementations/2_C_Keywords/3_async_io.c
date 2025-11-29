// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/wJGd7tKF2zY?si=hoRqjhXWAwvlc1bf)

/*
This is part-2 on the topic of asynchronous I/O.
This file demonstrates asynchronous I/O.
Part-1 performs the same work, but in synchronous I/O.
1. threads      --> Not the focus of this file.  
2. async I/O    --> our focus for this series.

CHECK out the part-1, for how to do the same thing in an 
asynchronous manner.

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <aio.h>        // for asynchronous I/O
#include <string.h>

#define BUFSIZE 25000

struct aiocb* async_read(FILE* fp, char* buf, int bytes) {
    struct aiocb *aio = malloc(sizeof(struct aiocb));
    if(aio == NULL) {
        return NULL;
    }

    memset(aio, 0, sizeof(*aio));

    aio->aio_buf = buf;
    aio->aio_fildes = fileno(fp);
    aio->aio_nbytes = bytes;
    aio->aio_offset = 0;

    int result = aio_read(aio);
    if(result < 0) {
        // something went wrong;
        free(aio);
        return NULL;
    }
    return aio;
}

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
    // ----------- Changes happen from here ----------- //
    struct aiocb* aio = async_read(fp, buf, BUFSIZE);

    uint64_t counter = 0;
    while(aio_error(aio) == EINPROGRESS) {
        // Represents some useful work happening at the same time as the async I/O
        counter++;
    }
    ret = aio_return(aio);

    fclose(fp);

    printf("While we were reading, we counted up %lu times\n", counter);
    if(ret > 0) {
        printf("Got %d bytes\n", ret);
    }
    else {
        printf("READ FAILED\n");
    }


    return 0;
}