#!/usr/bin/env zsh
#SBATCH --job-name=task1test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="task1.txt"
#SBATCH --mem=8G

cd $SLURM_SUBMIT_DIR

gcc task2.c matmul.c -Wall -O3 -o task2

