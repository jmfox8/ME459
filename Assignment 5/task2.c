#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mvmul.h"

#define NSEC_PER_SEC 1000000000

int main(int argv, char *argc[])
{
	struct timespec start, end;	/* Define struct for time capture */
	
	int n = atoi(argc[1]); 		/* Get the input integer from the command line */
    
    	double *A = (double *)malloc(sizeof(double)*(n * n)); 	/* Initialize the double array A with n*n entries*/
    	double *b = (double *)malloc(sizeof(double)*n); 	/* Initialize the double array b with n entries*/
    	double *c = (double *)malloc(sizeof(double)*n); 	/* Initialize the double array c with n entries*/
    
    	for (int i = 0; i < (n*n); i++)		/* Populate the A array with random numbers between -1 and 1 */
    	{
        	A[i] = (double)rand() / RAND_MAX * 2 -1;
    	}
    	for (int j = 0; j < n; j++)	/* Populate the b array with 1.0's*/
    	{
        	b[j] = 1.0;
    	}
	
	clock_gettime(CLOCK_MONOTONIC, &start); /* Start timer */
    	mvmul(A, b, c, n);		/* Call the provided mvmul function to preform matrix multiplication on A and B and populate c with the results*/
	clock_gettime(CLOCK_MONOTONIC, &end);   /* End timer */

    	printf("%f\n",c[n-1]);	/* Print the last entry in array c */
	
	free(A);	/* Free the allocated memory for all three dynamic arrays */
	free(b);
	free(c);
	
    	time_t elapsed_sec = end.tv_sec - start.tv_sec;
	long elapsed_nsec = end.tv_nsec - start.tv_nsec;
	double elapsed_total = elapsed_sec + (double)elapsed_nsec / (double)NSEC_PER_SEC;

	printf("%g\n", elapsed_total);
    
    	return 0;
}    
