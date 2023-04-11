#ifndef GLOBAL_H
#define GLOBAL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* This header file defines the struct and declares the variables that are going to be globally referenced throughout this program and NEVER CHANGED
these values are constant and need to be used in multiple places*/
struct segment_const {
    double L;       // Length of the body segment, meters
    double L_com;   // Height of center of Mass, meters
    double I;       // Moment of inertia around center of mass height, meters
    double I_prime; // Moment of inertia around the joint
    double m;       // Mass of body segment
};

struct dynamic_vals {
    
    double theta[2];      //theta[0] is angle of segment1 from vertical; theta[1] is angle of segment 2 from theta[0]
    double thetad[2];     //rate of change of thetas  = angular velocities of segments relative to joints
    double omega2;        //global angular velocity upper segment
    double thetadd[2];    //rate of change of omegas = angular acceleration of segments relative to joints
    double alpha2;        //global angular acceleration of upper segment (dynamic expression)
};

extern struct segment_const lower;
extern struct segment_const upper;
extern double g;

#endif
