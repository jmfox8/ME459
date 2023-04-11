#!/usr/bin/env zsh
#SBATCH --job-name=task1test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="task1.txt"
#SBATCH --mem=8G

cd $SLURM_SUBMIT_DIR

gcc task1.c sumArray.c -Wall -O3 -o task1

echo $SLURM_JOB_NODELIST
./task1 2^9
echo $SLURM_JOB_NODELIST
./task1 2^10
echo $SLURM_JOB_NODELIST
./task1 2^11
echo $SLURM_JOB_NODELIST
./task1 2^12
echo $SLURM_JOB_NODELIST
./task1 2^13
echo $SLURM_JOB_NODELIST
./task1 2^14

