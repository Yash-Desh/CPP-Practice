// Author: Yash Deshpande
// Date  : 29-10-2025
// Tutor : CodeVault (https://youtu.be/Mqb2dVRe0uo?si=o7o_UeQ7S_KpW-Un)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]) {

    int fd[2];

    // pipe
    // return 0 -> if successful
    // return -1 -> if failed

    // fd[0] -> read end
    // fd[1] -> write end
    if(pipe(fd) == -1) {
        printf("Error occurred while opening the pipe\n");
        return 1;
    }

    int id = fork();
    if(id = -1) {
        printf("Error occured with fork()\n");
        return 1;
    }
    if(id == 0) {
        // Child Process.
        close(fd[0]);                       // --> no use of this file.
        int x;
        printf("Input a number : ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));      // Check for errors when read/write
        close(fd[1]);                       // Done using this file.
    }
    else {
        // Parent Process.
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));       // Check for errors when read/write
        close(fd[0]);
        printf("Got %d from child process\n", y);
    }
    return 0;
}

/*
Theory Regarding Pipes
- It is an in-memory file.
- It is a file which is a buffer in memory
- It takes an array of 2 integers as input i.e. 2 file descriptors.
- Calling fork after pd makes sure that we copy over the file descriptors
  from the parent to the child.
- Such file descriptors remain open in the other process if one of them closes it.
- We need 2 file descriptors as each pipe has 2 ends.


*/