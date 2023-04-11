#!/usr/bin/env zsh
#SBATCH --job-name=prob4test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="prob4test.txt"

cd $SLURM_SUBMIT_DIR

gcc task4.c -Wall -O3 -o task4

./task4 5
