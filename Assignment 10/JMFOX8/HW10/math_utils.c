#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "math_utils.h"

// Returns the sum of all entries of arr
// Uses a normal for loop, adding one value at each iteration to an accumulator
float Sum(const float* arr, size_t count){
    float total = 0;
    for(int i = 0; i < count; i++){
        total = total + arr[i];
    }
    return(total);
}

// Returns the sum of the sine of each entry of arr
// Uses a normal for loop, adding one sine value at each iteration to an
// accumulator
float SumSines(const float* arr, size_t count){
    float total = 0;
    float sinval;
    for(int i = 0; i < count; i++){
        total = total + sin(arr[i]);
    }
    return(total);
}

// Returns the sum of entries of arr in the value pointed to by sum and the sum
// of the sines of the entries of arr the value pointed to by sum_sines
// There should only be a single for loop in this function, which calculates
// both quantities simultaneously.
void Fusion(const float* arr, size_t count, float* sum, float* sum_sines){
    float total = 0;
    float sinval;
    float total_sines = 0;
    for(int i = 0; i < count; i++){
        total = total + arr[i];
        total_sines = total_sines + sin(arr[i]);
    }
    *sum = total;
    *sum_sines = total_sines;
}