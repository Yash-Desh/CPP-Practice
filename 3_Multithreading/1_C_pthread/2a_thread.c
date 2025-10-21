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
    printf("Hello from thread %d\n", getpid());
}

int main(int argc, char *argv[]) {
    // Perform error handling on thread creation & joining as needed.

    // Create 2 threads & run the same routine in both
    pthread_t t1, t2;

    pthread_create(&t1, NULL, routine, NULL);
    pthread_create(&t2, NULL, routine, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    
    return 0;
}