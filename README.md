# Neural-model-auditory-STRFs
Computational neural modelling of auditory cortical receptive fields



Computational Neural Modelling of Auditory Cortical Receptive Fields
--------------------------------------------------------------------
Written by Jordan Chambers (jordandchambers@gmail.com)

This repository contains all the source code, data files and simulation results from:

Chambers, JD, et. al., "Computational neural modelling of auditory cortical receptive fields", Front. Comput. Neurosci., doi: 10.3389/fncom.2019.00028
https://www.frontiersin.org/articles/10.3389/fncom.2019.00028/abstract

This computational model uses a neural network model to investigate mechanisms by which cortical neurons can change their receptive fields. A sound signal was used as input to a model of the cochlea and auditory periphery, which activated or inhibited integrate-and-fire neuron models to represent networks in the primary auditory cortex. Each neuron in the network was tuned to a different frequency. All neurons were interconnected with excitatory or inhibitory synapses of varying strengths. Action potentials in one of the model neurons were used to calculate the receptive field using reverse correlation, which were directly compared to previously recorded electrophysiological data from ferrets performing behavioral tasks that require discrimination of particular sounds. This neural network model could reproduce complex STRFs observed experimentally through optimizing the synaptic drives in the model. 

User guide
----------

It should be noted that since all data files and results have been uploaded, it should be possible to just run one component of the model. However, a description of all steps in sequential order is provided here. It is assumed the user has an understanding of C, mpi, python and MATLAB. While the code will run in its current state, it does require the user to manually change parameters, filenames, etc to repeat multiple results/figures presented in the paper.

1. Converting sound signals to action potentials.

All the sound signals, or TORCs, can be found in the folder ./torcs/ and are in the .wav format.
The Carney and colleagues model of the cochlear is used to convert the wav files to action potential. The Carney model can be found in the folder ./carney and requires MATLAB. Run mexANmodel.m to compile the Carney model. Then running dumpjANstmstorcs.m will convert one set of TORCs to action potential data. The action potential data will be placed in a folder, ./cotorcH for the example provided here. To convert all sets of TORCs used in this paper requires the user to manually change the TORC file names and output files names found in dumpjANstmstorcs.m

2. Create stimulus profiles

Changing to a directory with a set of action potential data from the TORCs (e.g. ./cotorcH, ./cotorcV or ./cotorcL) will show a python file jcreate_mfile_for_stimprofiles01.py. Using python to run this file, it will generate a MATLAB script such as htorc.m. Using MATLAB to run the htorc.m file will generate text files containing the stimulus profile information (e.g. c1torc424h5011_stimprof.txt) in the current directory. Please note this process needs to be repeated for each set of TORCs and the filename and directories need to be manually set in the jcreate_mfile_for_stimprofiles01.py or htorc.m files.

3. Using a genetic algorithm to optimise synaptic strengths in the neural network

With the action potential data and stimulus profiles created above, the model of auditory cortex can be run. Action potentials in one of the integrate-and-fire neuron models is used to calculate the spatiotemporal receptive field (STRF) using reverse correlation. A genetic algorithm is used to optimise the synaptic strengths in the cortical neuron network to produce an STRF that matches a physiologically recorded STRF. The physiologically recorded STRFs are located in the ./targets folder.

To run the genetic algorithm, one of the mpi files in the main directory needs to be compiled (for example, mpitel.c or mpijwasabipas.c) linked to the mpi library. The complete list of .c files can be found the corresponding directory (for example, ./jtel or ./jwasabipas). Examples of how to compile these files and submit jobs on high performace computing facilities such as VLSCI/Melbourne bioinformatics can be found in the folder ./hpc. The different sets of c code (for example, mpitel.c or mpijwasabipas.c) correspond to different sets of TORCs. Furthermore, to change options such as the random seed, the cell used to calculate the STRF or the physiological target used for the optimisation, see the first few lines of the main function at the start of the file (for example, mpitel.c or mpijwasabipas.c).

While the genetic algorithm is running and once it has finished, results from the optimisation are placed in the ./results folder. Note that some of the result files in this folder from the paper have been reduced to contain only the best 20 results to compile with github's file size requirements. In this folder there is a python script, jstats.py, that will show the progress of the optimisation. Running "python jstats.py result_filename.txt" (where result_filename.txt is replaced with the appropriate results file generated from the genetic algorithm, for example dai003b-d2act01.txt) will print three main outputs. The first output shows the generation number and average value of top 20 solutions for that generation. The second gives the value of the optimal solutions and a list of synaptic strengths required to generate the solution. The third output gives a list of the optimal solution at the end of each generation.

4. Calculating the STRF of the optimal solution

To reduce the use of space on the hard drive, the genetic algorithm (see part 3) does not save the values of the STRF. To view the STRF, the model needs to be run again with the synaptic strengths from the optimal solution (or, if so desired, any combination of synaptic strengths). The second output from the jstats.py file (see part 3) is a list of the optimal synaptic strengths. Copying this list of parameters and passing it as an argument to csyns.py (that is, run "python csyns.py [list of optimal solutions]) will generate a file called jamsyn.c. The file csyns.py is in the main directory and the generated file jamsyn.c will be in the same directory.

Compiling and running file jamtel.c (or jamwasabipas.c) will run the cortical neuron network once and produce the STRF data in the directory ./output for call cells in the network. To run this code to produce an optimal solution found by the genetic algorithm, the jamtel.c file needs to be altered to include the jamsyn.c generated in the paragraph above (for example, #include "./jtel/jamsyn_dai003b-d2act02.c") and the function jam_syns() needs to be called prior to running the network simulation. To view the STRF, there is the matlab file ./matlabanalysis/jgraphstrf.m which can be called and have the filename passed to it (for example, jgraphstrf('../output/jamsyn_dai003b-d2pas0512sm.txt'), where the last number in the filename corresponds to the cell number in the network (this cell number needs to correspond to same cell number for which the genetic algorithm optimised the STRF).

5. Sensitivity analysis

To perform the sensitivity analysis, the synaptic strength needs to be set to the optimal solution (see part 4) and the cell from which the STRF is calculated and the target STRF need to be the same as those chosen for the optimisation (see examples in mpisentel.c lines 17-23). The code mpisentel.c requires mpi libraries and will run the sensitivity analysis, but it needs to be run twice. Once to increase the value of the synaptic strength by one step and once to decrease the value of the synaptic strength. To change the direction of the step, see file ./jtel/jga.c, function runjga_create_spopulation(), line 166/167. The will produce results in the ./results directory.

In the ./results directory, there is a python script jsenanal.py that will determine how sensitivity of each parameter. This script takes the arguments optimum value, positive step results, negative step results (see ./results/jrunsenanal.sh for all examples in the paper). It prints an output of a list that contains the values representing the sensitivity of each parameter. This list then needs to be copied and pasted into the file ./matlabanlysis/jgraphsynstrmat9.m.

Once all the data from the sensitivity analysis for each repetition, active and passive state, and, each cell has being placed in ./matlabanaylsis/jgraphsynstrmat9.m running this file will perform the final stages of the sensitivity analysis and graph the results.

COMMAND SUMMARY
---------------

cd ./carney

matlab mexANmodel.m

matlab dumpjANstmstorcs.m ## repeat for each set of TORCs

cd ../cotorcH ## directory name dependent on set of TORCs

python jcreate_mfile_for_stimprofiles01.py ## repeat for each set of TORCs

matlab htorc.m ## file name dependent on set of TORCs

cd ..

mpicc mpitel.c ## file name dependent on set of TORCs. Needs to be repeated five times for each cell and each state (passive/active)

cd ./results

python jstats.py results_file.txt ## repeat for each results from repetitions above

cd ..

python csyns.py input ## input is the output from last command, repeat for each result

cp jamsyn.c ./jtel/jamsyn_result_name.c ## repeat for each result

cc jamtel.c ## change linked files according to last two commands, repeat for each result

cd ./matlabanalysis

matlab jgraphstrf('../output/jamsyn_dai003b-d2pas0512sm.txt') ## repeat for each result, providing the appropriate filename each time 

cd ..

mpicc mpisentel.c ## file name dependent on set of TORCs. Needs to be repeated five times for each cell and each state (passive/active)

cd ./results

python jsenanal.py best_value pos_file neg_file ## repeat for each result, copy and paste output to ./matlabanalysis/jgraphsynstrmat9.m

cd ../matlabanalysis

matlab jgraphsynstrmat9.m
