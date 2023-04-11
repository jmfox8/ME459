#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


int main(int argc, char *argv[])
{
	int A[14];
	int length = 14;
	
	for ( int i = 0; i < length; i++ )
	{
		A[i] = rand()%100;
		printf("%i ", A[i]);
	}
	printf("\n");

	sort(A, length);

	for ( int i = 0; i < length; i++ )
        {
                printf("%i ", A[i]);
        }
        printf("\n");
return(0);
}
	
	
