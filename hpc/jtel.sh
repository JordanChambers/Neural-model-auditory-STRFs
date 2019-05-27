#!/bin/bash
#SBATCH --ntasks=48
#SBATCH --time=5-12
#SBATCH --job-name=siract68
#SBATCH --mail-type=FAIL
#SBATCH --mail-type=BEGIN
cd 
srun c68csiract
