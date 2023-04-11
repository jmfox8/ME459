#!/usr/bin/env zsh
#SBATCH --job-name=FoxProject
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:30:00
#SBATCH --output="results.txt"
#SBATCH --mem=8G

cd $SLURM_SUBMIT_DIR

module load matlab

matlab -batch "dynamics_engine_func '3' '3' '75'"