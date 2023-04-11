#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int main(int argc, char* argv[]){

int valmaxi = 1;
int valmini = -1;
int bitcount = sizeof(int)*8-1;

for (int i = 0; i < bitcount; i++){
    valmaxi = valmaxi*2;
}
valmaxi = valmaxi - 1;
printf("The maximum value of type int is %i \n",valmaxi);
valmaxi = valmaxi + 1;
printf("When 1 is added to the maximum value the variable returns: %i \n",valmaxi);
for (int j = 0; j< bitcount; j++){
    valmini = valmini*2;
}
printf("The most negative value of type int is %i \n", valmini);
valmini = valmini - 1;
printf("When 1 is subtracted from the most negative value the variable returns: %i \n", valmini);
return(0);
};