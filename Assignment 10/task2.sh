#!/usr/bin/env zsh
#SBATCH --job-name=task2test
#SBATCH --partition=wacc
#SBATCH --ntasks=1 --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="task2.txt"

cd $SLURM_SUBMIT_DIR

gcc task2.c math_utils.c -Wall -03 -o task2

./task2
