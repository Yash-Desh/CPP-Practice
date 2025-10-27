// Author: Yash Deshpande
// Date  : 19-10-2025
// Tutor : CodeVault (https://youtu.be/ln3el6PR__Q?si=gAav6THmIYTVdeTM)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// Parent thread exits after creating children, but the children should keep executing.
// This is done using pthread_exit(), it exits the parent thread, but the process doesn't terminate.
// The process waits till all the threads have finished execution.

void *roll_dice() {
    // local variable for the roll_dice function
    // we cannot return a reference to a local variable
    int value = (rand() % 6) + 1;
    printf("%d\n", value);

    int *result = malloc(sizeof(int));
    *result = value;

    // Confirm that this thread & main thread point to the same memory location
    printf("thread result = %p\n", result);

    // Remember pthread_exit is not a necessary requirement. It can be called if needed by the programmer.
    // Or else you can always return the value.
    pthread_exit((void *)result);
}

int main(int argc, char* argv[]) {
    srand((time(NULL)));
    
    pthread_t th;
    pthread_create(&th, NULL, roll_dice, NULL);

    // return 0;
    // exit(0);
    pthread_exit(0);
    
    // Get the result of the thread function.
    int *res;
    pthread_join(th, (void **)&res);

    printf("main thread res = %p\n", res);

    // free the dynamic allocation
    free(res);

    return 0;
}