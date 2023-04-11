#include <stdlib.h>
#include <stdio.h>

#include "sort.h"

void sort(int* A, size_t n_elements)
{
	int arraysize = n_elements;
	int val;
	int inspoint;
	int i;
	for (i = 1; i < arraysize; i++)
	{
		val = A[i];
		inspoint = i-1;
		while (inspoint >= 0 && A[inspoint] > val)
		{
			A[inspoint + 1] = A[inspoint];
			inspoint = inspoint - 1;
		}
		A[inspoint + 1] = val;
	}
}
	
