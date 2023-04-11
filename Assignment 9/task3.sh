#!/usr/bin/env zsh
#SBATCH --job-name=task3test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="task3.txt"

cd $SLURM_SUBMIT_DIR

gcc task3.c -Wall -O3 -o task3

./task3