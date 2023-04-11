#include <stdlib.h>
#include <stdio.h>


int sortfunc(const void *a, const void *b)
{
	return( *(int*)a + *(int*)b);
}


int main(int argc, char *argv[])
{
	int arg1 = atoi(argv[1]); /* Capture the input variable from the command line as an integer*/
	float floatcheck = atof(argv[1]); /* Capture the input variable from the command line as a float */

	if (floatcheck > arg1 || arg1 <= 0)	/* Run check to determine if the input was actually a positive integer and exit program if not */
	{
		exit(0);
	}

	int *argarray = (int *)malloc(sizeof(int)*(arg1+1)); /* allocate an array of ints in the heap the size of the input +1 */

	for (int i = 0; i<= arg1; i++) /* populate and print the array values from 0 to the input */
	{
		argarray[i] = i;
		printf("%i ",argarray[i]);
	}
	printf("\n");

	qsort(argarray, arg1+1, sizeof(int), sortfunc); /*sort the array in descending order */

	for (int i  = 0; i<=arg1; i++) /* Print the newly sorted array */
	{
		printf("%i ", argarray[i]);
	}
	printf("\n");

	free(argarray); /* Free the allocated memory for the int array*/
}
