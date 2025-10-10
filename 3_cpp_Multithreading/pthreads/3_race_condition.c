// Author : Yash Deshpande
// Date   : 08-10-2025
// Tutor  : CodeVault YT (https://youtu.be/FY9livorrJI?si=EgcNOK0dIp0A_tD4)

// ----------------------------------------------------------------------
// Compilation command: gcc -lpthread <file_name.c> -o <executable_name>
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mail = 0;

void* routine() {
    for(int i=0; i<1000000; i++) {
        mail++;
    }

    // Generally if you keep the iterations less than 1000,000 then
    // the 1st thread will get created & run all the iterations before 
    // the next thread is created & hence you may not see a thread race.
}

int main(int argc, char *argv[]) {

    // Create 2 threads & run the same routine in both
    pthread_t t1, t2;

    pthread_create(&t1, NULL, routine, NULL);
    pthread_create(&t2, NULL, routine, NULL);

    // Make the parent wait.
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Printing in the parent.
    printf("Number of mails = %d\n", mail);
    return 0;
}