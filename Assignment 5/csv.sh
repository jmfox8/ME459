#!/usr/bin/env zsh
#SBATCH --job-name=prob3test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="sample.csv"
cd $SLURM_SUBMIT_DIR

module load mamba
bootstrap_conda
conda activate py459

## Put the commands to launch your python script below ##
python matrixgen.py 2 2
