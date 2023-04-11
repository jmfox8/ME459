#!/usr/bin/env zsh
#SBATCH --job-name=task2test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="task2.txt"
#SBATCH --mem=4G

cd $SLURM_SUBMIT_DIR

gcc task2.c matmul.c -Wall -O3 -o task2

echo $SLURM_JOB_NODELIST
./task2 32
echo $SLURM_JOB_NODELIST
./task2 64
echo $SLURM_JOB_NODELIST
./task2 128
echo $SLURM_JOB_NODELIST
./task2 256
echo $SLURM_JOB_NODELIST
./task2 512
echo $SLURM_JOB_NODELIST
./task2 1024
echo $SLURM_JOB_NODELIST
./task2 2048
echo $SLURM_JOB_NODELIST
./task2 4096


