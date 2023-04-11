#!/usr/bin/env zsh
#SBATCH --job-name=prob2test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="prob2.txt"
#SBATCH --mem=16G

cd $SLURM_SUBMIT_DIR

echo $SLURM_JOB_NODELIST

gcc mvmul.c task2.c -Wall -O3 -o task2

./task2 1024

./task2 2048

./task2 4096

./task2 8192

./task2 16384


