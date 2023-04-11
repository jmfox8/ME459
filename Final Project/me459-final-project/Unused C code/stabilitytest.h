#ifndef STABILITYTEST_H
#define STABILITYTEST_H
#include <stddef.h>
#include <stdbool.h>
#include "global.h"

/*Function takes in the variable parameters of a double inverted pendulum (position, velocity, acc, torques) and determines the stability of the position */

void stable(struct dynamic_vals input, double t1, double t2, bool *stable_flags);

#endif