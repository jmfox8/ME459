#include <stdio.h>
#define N 8

int main(int argc, char* argv[]) {
    printf("Hello world!\n");

    for (size_t i = 0; i < N; i++) {
        printf("%zu ", i);
        printf("%zu ", i+1);
    }
    printf("\n");
   
    size_t sum = 0;
    for (size_t i = 0; i < N; i++) {
        sum += i;
    }
    printf("sum: %zu\n", sum);
   
    int acc = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2) {
            acc += i;
        }
        else {
            acc -= i;
        }
    }

    printf("acc: %d\n", acc);




    return 0;
}
