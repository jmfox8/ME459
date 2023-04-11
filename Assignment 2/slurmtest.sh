#!/usr/bin/env zsh
#SBATCH --job-name=assignment2test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="slurmtest-%j.txt"

pwd

cd $SLURM_SUBMIT_DIR

pwd
