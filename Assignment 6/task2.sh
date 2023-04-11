#!/usr/bin/env zsh
#SBATCH --job-name=prob3test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="prob2f.txt"

cd $SLURM_SUBMIT_DIR

gcc dll_alloc.c task2.c traversal.c -Wall -O3 -o task2


