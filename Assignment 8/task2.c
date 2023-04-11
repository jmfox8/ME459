#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matmul.h"

#define NSEC_PER_MSEC 1000000

int main(int argc, char* argv[]){
    struct timespec start1, end1, start2, end2, start3, end3, start4, end4; // Declare the variables used to capture time values
    int n = 1024;                  
    double *A = (double*)malloc((n * n) * sizeof(double));  // Allocate memory for array
    double *B = (double*)malloc((n * n) * sizeof(double));
    double *A_col = (double*)malloc((n * n) * sizeof(double)); 
    double *B_col = (double*)malloc((n * n) * sizeof(double)); 
    for(int i = 0; i<n*n; i++){                 // Loop to populate array with random values between -1 and 1
        A[i] = rand();
        B[i] = rand();
        A[i] = A[i]/RAND_MAX * 2 - 1;
        B[i] = B[i]/RAND_MAX * 2 - 1;
    }
    for(int ii = 0; ii<n; ii++){
        for(int jj = 0; jj<n; jj++){
            A_col[ii*n+jj] = A[ii+n*jj];
            B_col[ii*n+jj] = B[ii+n*jj];
        }
    }

clock_gettime(CLOCK_MONOTONIC, &start1);        // Capture timing for the first function
double *C1 = mmul1(A,B,n);
clock_gettime(CLOCK_MONOTONIC, &end1);

clock_gettime(CLOCK_MONOTONIC, &start2);        // Capture timing for the second function
double *C2 = mmul2(A,B,n);
clock_gettime(CLOCK_MONOTONIC, &end2);

clock_gettime(CLOCK_MONOTONIC, &start3);        // Capture timing for the third function
double *C3 = mmul3(A,B_col,n);
clock_gettime(CLOCK_MONOTONIC, &end3);

clock_gettime(CLOCK_MONOTONIC, &start4);        // Capture timing for the fourth function
double *C4 = mmul4(A_col,B,n);
clock_gettime(CLOCK_MONOTONIC, &end4);

double elapsed_sec_1 = end1.tv_sec - start1.tv_sec; // Get time in seconds of first function execution
long double elapsed_nsec_1 = end1.tv_nsec - start1.tv_nsec; // Get time in nanoseconds of first function execution

double elapsed_sec_2 = end2.tv_sec - start2.tv_sec;
long double elapsed_nsec_2 = end2.tv_nsec - start2.tv_nsec;

double elapsed_sec_3 = end3.tv_sec - start3.tv_sec;
long double elapsed_nsec_3 = end3.tv_nsec - start3.tv_nsec;

double elapsed_sec_4 = end4.tv_sec - start4.tv_sec;
long double elapsed_nsec_4 = end4.tv_nsec - start4.tv_nsec;

double elapsed_msec_1 = elapsed_sec_1 * 1000 + elapsed_nsec_1/(double)NSEC_PER_MSEC;
double elapsed_msec_2 = elapsed_sec_2 * 1000 + elapsed_nsec_2/(double)NSEC_PER_MSEC;
double elapsed_msec_3 = elapsed_sec_3 * 1000 + elapsed_nsec_3/(double)NSEC_PER_MSEC;
double elapsed_msec_4 = elapsed_sec_4 * 1000 + elapsed_nsec_4/(double)NSEC_PER_MSEC;

printf("%f\n %f\n %f\n %f\n %f\n %f\n %f\n %f\n",elapsed_msec_1,C1[n*n-1],elapsed_msec_2,C2[n*n-1],elapsed_msec_3,C3[n*n-1],elapsed_msec_4,C4[n*n-1]);

free(A);
free(B);
free(A_col);
free(B_col);
free(C1);
free(C2);
free(C3);
free(C4);
}
