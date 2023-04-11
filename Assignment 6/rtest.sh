#!/usr/bin/env zsh
#SBATCH --job-name=Rslurm
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="rtest.txt"

cd $SLURM_SUBMIT_DIR

module load mamba
bootstrap_conda
conda activate r459

Rscript task1.R /srv/home/jmfox8/test.csv
