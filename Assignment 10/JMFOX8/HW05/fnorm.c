#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>

#include "fnorm.h"

double fnorm(double *A, size_t n_rows, size_t n_cols)
{
	double frob = 0;

	for (int i =0; i < n_rows; i++)
	{	
		for (int j = 1; j <= n_cols; j++)
		{	
			frob = frob + pow(A[i * n_cols + j],2);
		}
	}

	frob = sqrt(frob);

	return frob;
}	
