// Author: Yash Deshpande
// Date  : 30-10-2025
// Tutor : CodeVault (https://youtu.be/5We_HtLlAbs?si=3QMQo-wkHn1jW_bZ)

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                 
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if(pid == -1) {
        return 1;
    }

    if(pid == 0) {
        // Child Process.
        while(1) {
            printf("Some text goes here.\n");
            usleep(50000);
        }
    }
    else {
        // Parent Process.
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
    }


    return 0;
}