#ifndef STEP_H
#define STEP_H
#include <stddef.h>
#include <stdbool.h>
#include "global.h"

// This function takes in conditions of the inverted pendulum and a time step, and calculates the angle, angular velocity and angular acceleration after that timestep

void step(struct dynamic_vals *input, double t1, double t2, double tstep);

#endif