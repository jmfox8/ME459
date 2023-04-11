#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sumArray.h"

#define NSEC_PER_MSEC 1000000

int main(int argc, char* argv[]){
    if (argc != 2){             // If to make sure that a value is passed through command line
        printf("provide dimension for square matrix\n");
        return 1;
    }
    struct timespec start1, end1, start2, end2; // Declare the variables used to capture time values
    int n = atoi(argv[1]);                      // Capture Array size from command line
    double *A = (double*)malloc((n * n) * sizeof(double));  // Allocate memory for array
    
    for(int i = 0; i<n*n; i++){                 // Loop to populate array with random values between -1 and 1
        A[i]=rand();
        A[i] = A[i]/RAND_MAX * 2 - 1;
    }

clock_gettime(CLOCK_MONOTONIC, &start1);        // Capture timing for the first summing function
double* sum1 = sumArray1(A,n);
clock_gettime(CLOCK_MONOTONIC, &end1);

clock_gettime(CLOCK_MONOTONIC, &start2);        // Capture timing for the second summing funciton
double* sum2 = sumArray2(A,n);
clock_gettime(CLOCK_MONOTONIC, &end2);

double elapsed_sec_1 = end1.tv_sec - start1.tv_sec; // Get time in seconds of first function execution
long double elapsed_nsec_1 = end1.tv_nsec - start1.tv_nsec; // Get time in nanoseconds of first function execution

double elapsed_sec_2 = end2.tv_sec - start2.tv_sec;
long double elapsed_nsec_2 = end2.tv_nsec - start2.tv_nsec;

double elapsed_msec_1 = elapsed_sec_1 * 1000 + elapsed_nsec_1/(double)NSEC_PER_MSEC;
double elapsed_msec_2 = elapsed_sec_2 * 1000 + elapsed_nsec_2/(double)NSEC_PER_MSEC;

printf("%f\n %f\n %f\n %f\n",elapsed_msec_1,*sum1,elapsed_msec_2,*sum2);

free(A);

return 0;
}
