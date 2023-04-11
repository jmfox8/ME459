#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>

int main(int argc, char* argv[]){
    float xf = 0.0006;
    double xd = 0.00000003;
    float factor = 0.99999997;
    double factord = 0.9999999;    
float test = 1.0;
double testd = 1.0;
    int sample_size = 10000000;
    for (int i = 0; i < sample_size; i++){
       test = sinf(xf)/xf;
       if(test >= 1.0){
    printf("%.36f \n",xf);
break;
       }
       xf = xf * factor;
    }
    for (int j = 0; j < sample_size; j++){
       testd = sin(xd)/xd;
       if(testd >= 1.0){
        printf("%.36f \n",xd);
        break;
       }
       xd = xd * factord;
}
return(0);
}
