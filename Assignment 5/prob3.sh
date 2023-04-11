#!/usr/bin/env zsh
#SBATCH --job-name=prob3test
#SBATCH --partition=wacc
#SBATCH --ntasks=1  --cpus-per-task=2
#SBATCH --time=0-00:10:00
#SBATCH --output="prob3.txt"

cd $SLURM_SUBMIT_DIR

gcc task3.c fnorm.c -Wall -O3 -lm -o task3

./task3 /srv/home/jmfox8/test.csv
