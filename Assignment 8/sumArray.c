#include<stdlib.h>
#include<stdio.h>
#include "sumArray.h"

double arraysum1, arraysum2;
double* sumArray1(const double* A, const size_t n){
int i;              // Initialize counter ints
int j;              // Initialize counter ints
double* returnval;  // Initialize pointer to return value
for (i = 0; i<n; i++){      //For loop to sum the various parts of the Array
    for (j = 0; j<n; j++){
        arraysum1 = arraysum1+ A[i*n+j];
    }
j=0;
}
returnval = &arraysum1; // Assign array sum value to the locaiton of the pointer
return returnval;      // Return Pointer
}

double* sumArray2(const double* A, const size_t n){
int i;
int j;
double* returnval;
for (j = 0; j<n; j++){
    for (i = 0; i<n; i++){
        arraysum2 = arraysum2 + A[i*n+j];
    }
i=0;
}
returnval = &arraysum2;
return returnval;
}