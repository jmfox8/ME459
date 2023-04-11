#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include "fnorm.h"

int main(int argc, char **argv)
{
	FILE *fnmat1;		// Declare pointer to file included in command line
	fnmat1 = fopen(argv[1], "r"); // open file in command line for read acces only
	int rows = 0;
	int cols = 1;
	char colstep;
	char rowstep;
	char com = ',';
	for (colstep = getc(fnmat1); colstep != '\n'; colstep = getc(fnmat1))  // Loop to read through file and determine number of columns
	{
		if (colstep == com)
		{
			cols = cols + 1;
		}
	}
	rewind(fnmat1);		//Restart pointer to beginning of file
	for (rowstep = getc(fnmat1); !feof(fnmat1); rowstep = getc(fnmat1))  // Loop to read through file and detemrine number of rows
	{
		if (rowstep == '\n')
		{
			rows = rows +1;
		}
	}
	rewind(fnmat1);
	double A[cols*rows];
	char fillcheck;
	char *fillcheckloc = &fillcheck;
	double dfill;
	int fillset = 0;
	for (fillcheck = getc(fnmat1); !feof(fnmat1); fillcheck = getc(fnmat1)) //Loop to parse through file and determine if char is a number, if so include in array A
	{
		dfill = strtod(fillcheckloc,NULL);
		if (fillcheck != ',' && fillcheck != '\n')
		{
		A[fillset] = dfill;
		fillset = fillset +1;
		}
	}
	double frobmat = fnorm(A, rows, cols); // call fnorm function to get frobenius norm

	printf("%f \n", frobmat);	// print frobenius norm
return(0);
}
