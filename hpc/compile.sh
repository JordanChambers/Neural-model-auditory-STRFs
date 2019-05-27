## Compile on VLSCI/Melbourne Bioinformatics
#module avail
module load gcc
module load openmpi-gcc
mpicc mpijam.c $CPPFLAGS $LDFLAGS -o mjwasabi003act39
