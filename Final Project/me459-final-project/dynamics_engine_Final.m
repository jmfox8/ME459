clear all
close all
clc

ankle= input("Input starting ankle angle from vertical in degrees: ");   %Initial angular offset of the lower segment from vertical, in rad
hip = input("Input starting hip angle from lower segment in degrees: ");   %Initial angular offset of the upper segment from lower segment, in rad
loops = input("Enter the number of torque steps: ");                    %Number of iterations of each torque to try

dynamics_engine_func(ankle,hip,loops);

