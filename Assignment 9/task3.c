#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NSEC_PER_MSEC 1000000

void test1(double* data, int elems, int stride){ /*The test Function*/
    int i;
    double result = 0.0;
    volatile double sink;

    for(i = 0; i < elems; i+= stride){
        result += data[i];
    }
    sink = result; /* So compiler doesn't optimize away the loop */
}

void test2(double* data, int elems, int stride){
    int i;
    volatile double result = 0.0;
    for (i = 0; i < elems; i += stride){
        result += data[i];
    }
}

int main(int argc, char* argv[]){
    struct timespec start1, end1, start2, end2;

        int n_elems = 512*(1024)/sizeof(double);
        double time1avg = 0.0;
        double time2avg= 0.0; 
        int loops = 100;
        double *Array = (double*)malloc(n_elems * sizeof(double));
        int stride[7] = {1,2,4,8,11,15,17};
        int sloop;

        for(int i = 0; i<n_elems; i++){                 // Loop to populate array with random values between -1 and 1
            Array[i]=rand();
            Array[i] = Array[i]/RAND_MAX * 2 - 1;
        }

        test1(Array,n_elems,1);
        for(int j = 0; j<7; j++){
            for(int k = 0; k<loops; k++){
                sloop = stride[j];
                clock_gettime(CLOCK_MONOTONIC, &start1);        // Capture timing for the function
                test1(Array,n_elems,sloop);
                clock_gettime(CLOCK_MONOTONIC, &end1);
                double elapsed_sec_1 = end1.tv_sec - start1.tv_sec; // Get time in seconds of function execution
                long double elapsed_nsec_1 = end1.tv_nsec - start1.tv_nsec; // Get time in nanoseconds of function execution
                double elapsed_msec_1 = elapsed_sec_1 * 1000 + elapsed_nsec_1/(double)NSEC_PER_MSEC; //Convert time of execution to milliseconds
                time1avg += elapsed_msec_1;
            }
            time1avg = time1avg/loops;
            printf("%f ",time1avg);
            time1avg = 0.0;
        }
        printf("\n");
        
        test2(Array,n_elems,1);
        for(int jj = 0; jj<7; jj++){
            for(int kk = 0; kk<loops; kk++){
                sloop = stride[jj];
                clock_gettime(CLOCK_MONOTONIC, &start2);        // Capture timing for the function
                test1(Array,n_elems,sloop);
                clock_gettime(CLOCK_MONOTONIC, &end2);
                double elapsed_sec_2 = end2.tv_sec - start2.tv_sec; // Get time in seconds of function execution
                long double elapsed_nsec_2 = end2.tv_nsec - start2.tv_nsec; // Get time in nanoseconds of function execution
                double elapsed_msec_2 = elapsed_sec_2 * 1000 + elapsed_nsec_2/(double)NSEC_PER_MSEC; //Convert time of execution to milliseconds
                time2avg += elapsed_msec_2;
            }
            time2avg = time2avg/loops;
            printf("%f ",time2avg);
            time2avg= 0.0;
        }
}
