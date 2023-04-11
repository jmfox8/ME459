#!/usr/bin/env zsh
#SBATCH --job-name=Rslurm
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="rslurm.txt"

cd $SLURM_SUBMIT_DIR

echo $SLURM_JOB_NODELIST

module load mamba
bootstrap_conda
conda activate r459

Rscript task3.R 1024

Rscript task3.R 2048

Rscript task3.R 4096

Rscript task3.R 8192

Rscript task3.R 16384
