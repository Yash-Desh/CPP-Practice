// Author: Yash Deshpande
// Date  : 29-10-2025
// Tutor : CodeVault (https://youtu.be/6u_iPGVkfZ4?si=BpUJMsQbPJAVjOPz)

// Q You have to find the sum of an array using 2 processes. Both the processes
// sum half the array elements, then one process writes its sum to the pipe, &
// the other process reads it & adds it to its sum.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 1, 2};
    int arrSize = sizeof(arr)/sizeof(int);

    // Each process needs a start & end index for reading from the array
    int start, end;

    int fd[2];
    if(pipe(fd) == -1) {
        printf("Error while opening the pipe\n");
        return 1;
    }

    int id = fork();
    if(id == -1) {
        printf("Error occurred while fork()\n");
        return 1;
    }
    else if(id == 0) {
        // Child Process.
        start = 0;
        end = start + arrSize/2;
    }
    else {
        // Parent Process.
        start = arrSize/2;
        end = arrSize;
    }

    int sum = 0;
    for(int i=start; i<end; i++) {
        sum += arr[i];
    }
    printf("Calculated Partial Sum = %d\n", sum);


    if(id == 0) {
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else {
        int sumFromChild;
        close(fd[1]);
        read(fd[0], &sumFromChild, sizeof(sumFromChild));
        close(fd[0]);

        int total = sum + sumFromChild;
        printf("Total = %d\n", total);
    }
    return 0;
}   