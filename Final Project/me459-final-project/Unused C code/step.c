#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "step.h"
#include "global.h"


void step(struct dynamic_vals *input, double t1, double t2, double tstep){
double moment_array[4];
double dynamic_array[4];
double gravity_array[2];
double t_ankle = t1;
double t_hip = t2;

gravity_array[0] = -g*(lower.m*lower.L_com*sin(input->theta[0]) + upper.m*(lower.L*sin(input->theta[0])+lower.L_com*sin(input->theta[0]*input->theta[1])));
gravity_array[1] = -g*upper.m*upper.L_com*sin(input->theta[0]+input->theta[1]);


dynamic_array[0] = upper.m*lower.L*lower.L_com*sin(input->theta[0])*-2*input->thetad[1];
dynamic_array[1] = upper.m*lower.L*lower.L_com*sin(input->theta[0])*-input->thetad[1];
dynamic_array[2] = upper.m*lower.L*lower.L_com*sin(input->theta[0])*input->thetad[0];
dynamic_array[3] = 0;
moment_array[0] = lower.I_prime+upper.I_prime+upper.m*(lower.L*lower.L+2*lower.L*upper.L_com*cos(input->theta[1]));
moment_array[1] = upper.I_prime+upper.m*lower.L*upper.L_com*cos(input->theta[1]);
moment_array[2] = upper.I_prime + upper.m*lower.L*upper.L_com*cos(input->theta[1]);
moment_array[3] = upper.I_prime;  

static_t_hip = -g*upper.m*upper.L_com*sin(input->theta[1]); 
static_t_ankle = -g*(lower.m*lower.L_com*sin(input->theta[0])+upper.m*(lower.L*sin(input->theta[0])+upper.L_com*sin(input->theta[1]+input->theta[0])))+static_t_hip;

}
