// Author : Yash Deshpande
// Date   : 08-10-2025
// Tutor  : CodeVault YT (https://youtu.be/IKG1P4rgm54?si=8zVAb-UhGlzHrPRF)

// ----------------------------------------------------------------------
// Compilation command: gcc -lpthread <file_name.c> -o <executable_name>
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Compare this program & output with program 2a_process.c

int x = 2;

void* routine() {
    // Example-1 ///////////////////////////////
    // printf("Hello from process %d\n", getpid());

    // Example-2 //////////////////////////////
    x++;
    sleep(2);
    printf("Value of x = %d\n", x);
}

void* routine2() {

    // Example-2 //////////////////////////////
    sleep(2);
    printf("Value of x = %d\n", x);
}

int main(int argc, char *argv[]) {
    // Perform error handling on thread creation & joining as needed.

    // Create 2 threads & run the same routine in both
    pthread_t t1, t2;

    pthread_create(&t1, NULL, routine, NULL);
    // pthread_create(&t2, NULL, routine, NULL);
    pthread_create(&t2, NULL, routine2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    
    return 0;
}