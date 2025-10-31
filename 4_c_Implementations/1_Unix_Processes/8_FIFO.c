// Author: Yash Deshpande
// Date  : 29-10-2025
// Tutor : CodeVault (https://youtu.be/2hba3etpoJg?si=c6tPZfPSvXbb-31F)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                 // for POSIX system calls.
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>                  // for errrno
#include <fcntl.h>                  // for the open() syscall

int main(int argc, char* argv[]) {
    // Parameters
    // FIFO filename
    // Permission -> 0777 = read/write/execute by all processes in the system
    if(mkfifo("myfifo1", 0777) == -1) {
        if(errno != EEXIST) {
            printf("Error in creating a FIFO\n");
            return 1;
        }
        // mkfifo will return -1 even if the file is already present in the system
        // we only consider the case where mkfifo return -1 & the file is not present
        // in the system as an error i.e. errorno != EEXIST
    }

    printf("Opening FIFO file...\n");
    int fd = open("myfifo1", O_WRONLY);

    // The program execution will hang on after ther opening file...
    // cat myfifo1 in a separate terminal
    // Then this process will continue
    // The process that opens the fifo to write blocks till some other process opens it for reading.
    // The same is true in the opposite order as well.


    printf("Opened FIFO file\n");
    int x = 97;                                 // char value = a
    write(fd, &x, sizeof(x));
    printf("Writing Complete\n");

    printf("Closing FIFO file\n");
    close(fd);

    return 0;
}