#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "global.h"

struct segment_const lower = { .L = 0.867, .L_com = 0.589, .m = 26.30, .I = 1.400, .I_prime = 10.524}; 
struct segment_const upper = {.L = 0.851, .L_com = 0.332, .I = 2.227,.m = 42.88, .I_prime = 6.9534};
double g = 9.81;