// Author : Yash Deshpande
// Date   : 08-10-2025
// Tutor  : CodeVault YT (https://youtu.be/IKG1P4rgm54?si=8zVAb-UhGlzHrPRF)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// Compare this program & output with program 2b_thread.c

int main(int argc, char *argv[]) {
    int x = 2;
    
    int pid = fork();

    if(pid == -1) {
        // return error
        return 1;
    }

    if(pid == 0) {
        x++;
    }
    sleep(2);
    printf("Value of x is %d\n", x); 

    if(pid != 0) {
        // Inside the parent
        wait(NULL);
    }

    /*
    ################### Output of the program ###################
    Value of x is 3
    Value of x is 2
    
    */
    return 0;
}