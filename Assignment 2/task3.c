#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int end = atoi(argv[1]);
    for (int count = 0; count <= end; count++)
    {
        printf("%i ",count);
    }
        printf("\n");
}
