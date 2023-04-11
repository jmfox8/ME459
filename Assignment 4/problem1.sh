#!/usr/bin/env zsh
#SBATCH --job-name=prob1test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="prob1test-%j.txt"

cd $SLURM_SUBMIT_DIR

gcc sort.c task1.c -Wall -O3 -o task1

./task1

