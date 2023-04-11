#include<stdlib.h>
#include<stdio.h>
#include "matmul.h"

double* mmul1(const double* A, const double* B, const size_t n){
int i;
int j;
int k;
double* C = (double *)malloc(sizeof(double) * (n * n));
C[0] = 0;
for (i = 0; i<n; i++){

    for (j = 0; j<n; j++){

        for (k = 0; k<n; k++){
            C[i*n+j] = C[i*n+j] + A[i*n+k]*B[k*n+j];
        }
    k = 0;
    }
    j=0;
}
return C;
}

double* mmul2(const double* A, const double* B, const size_t n){
int i;
int j;
int k;
double* C = (double *)malloc(sizeof(double) * (n * n));
C[0] = 0;
for (j = 0; j<n; j++){

    for (i = 0; i<n; i++){

        for (k = 0; k<n; k++){
            C[i*n+j] = C[i*n+j] + A[i*n+k]*B[k*n+j];
        }
    }
}
return C;
}

double* mmul3(const double* A, const double* B, const size_t n){
int i;
int j;
int k;
double* C = (double *)malloc(sizeof(double) * (n * n));
C[0] = 0;
for (i = 0; i<n; i++){

    for (j = 0; j<n; j++){

        for (k = 0; k<n; k++){
            C[i*n+j] = C[i*n+j] + A[i*n+k]*B[j*n+k];
        }
    k = 0;
    }
    j=0;
}
return C;
}

double* mmul4(const double* A, const double* B, const size_t n){
int i;
int j;
int k;
double* C = (double *)malloc(sizeof(double) * (n * n));
C[0] = 0;
for (i = 0; i<n; i++){

    for (j = 0; j<n; j++){

        for (k = 0; k<n; k++){
            C[i*n+j] = C[i*n+j] + A[k*n+i]*B[k*n+j];
        }
    k = 0;
    }
    j=0;
}
return C;
}
