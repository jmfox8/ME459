#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

int main(int argc, char *argv[])
{

struct A exA; /* Declare variable of the type structure A*/
struct B exB; /* Declare variable of the type structure B*/


printf("The size of the structure type A is: %lu Bytes\n", sizeof(exA));
printf("The size of the structure type B is: %lu Bytes\n", sizeof(exB));

struct A *pA = (struct A*)malloc(sizeof(exA)); /* Allocate memory for a single A structure*/

(*pA).i = 1882; /* Give value to integer portion of A struct */
(*pA).c = 'S'; /* Give value to char portion of A struct */
(*pA).d = 1; /* Give value to double portion of A struct*/

printf("The value of 'i' in my A structure is: %i\n", pA->i);
printf("The value of 'c' in my A structure is: %c\n", pA->c);
printf("The value of 'd' in my A structure is: %f\n", pA->d);


free(pA); /* Free the memory allocation for the created struct pA */

return 0;

}
