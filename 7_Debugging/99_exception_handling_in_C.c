// Author: Yash Deshpande
// Date  : 27-11-2025
// Tutor : Jack Sorber (https://youtu.be/eQcRcgOnl9o?si=AxjvHoYn-Mj6H1Eg)

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

// This is a complex topic, I highly recommend you watch the video along.

// C does not have any try-catch exception handling like C++.
// We are going to be handling exceptions here -> the file expects 
// command line arguments in the form of double values.
// Exception is when we don't provide any cli args & then the result 
// of the avg is a nan value. 

// Comment out the "Exception Handling" Blocks to turn of exception handling
// & get the nan output.

// setjmp-longjmp is NOT EXACTLY try-catch, its complicated & should be generally avoided. 

// Run Command: ./a.out 3.5 5.8 1.2
// Run Command to get nan output: ./a.out


jmp_buf savebuf;

double compute_avg(double* values, size_t length) {
    double sum = 0;

    // -- Exception Handling -- //
    if(length <= 0) {
        longjmp(savebuf, 1);
    }
    // ------------------------ // 

    for(int i=0; i<length; i++) {
        sum += values[i];
    }
    return sum/(double)length;
}

int main(int argc, char** argv) { 
    int arrlength = argc - 1;
    double *darr = malloc(sizeof(double) * arrlength);
    for(int i=1; i<argc; i++) {
        darr[i-1] = atof(argv[i]);
    }

    // // ####### No Exception Handling #########
    // double avg = compute_avg(darr, arrlength);
    // printf("Average = %lf\n", avg);
    // // #######################################


    // ####### Exception Handling #######
    if(setjmp(savebuf) == 0) {
        // Similar to a "try" block in C++
        double avg = compute_avg(darr, arrlength);
        printf("Average = %lf\n", avg);
    }
    else {
        printf("ERROR! invalid inputs\n");
    }

    return 0;
}