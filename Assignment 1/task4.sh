#!/usr/bin/env zsh
#SBATCH --job-name=WhereAmI
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-0:25:0
#SBATCH --output="WhereAmI-%j.txt"

cd $SLURM_SUBMIT_DIR

name=$(hostname)

echo "The name of the machine on which this is running is $name"

