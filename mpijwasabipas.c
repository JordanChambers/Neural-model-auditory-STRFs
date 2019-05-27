#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include <fftw3.h>
#include <mpi.h>
#include <time.h>
#include "./jwasabipas/jheaders.h"
#include "./jwasabipas/jstructure.c"
#include "./jwasabipas/jsoundsignal.c"
#include "./jwasabipas/jwav2aud.c"
#include "./jwasabipas/jnetwork.c"
#include "./jwasabipas/jnetwork_is.c"
#include "./jwasabipas/jstrf.c"
#include "./jwasabipas/jga.c"

int main(void)
{
  //printf("In mpi main\n");
  srand(42);
  jata.jga.cindex = 8;
  sprintf(&jata.jresname[0], "./results/sirpas42.txt");
  jata.jmpi.ierr = MPI_Init(&jata.jmpi.argc, jata.jmpi.argv);
  
  jata.jmpi.ierr = MPI_Comm_rank(MPI_COMM_WORLD, &jata.jmpi.id);
  jata.jmpi.ierr = MPI_Comm_size(MPI_COMM_WORLD, &jata.jmpi.procs);

  jata.jga.gen = 0;
  jata.jga.genmax = 1000;
  jata.jga.gaec = 40;//20;
  jata.jga.gacc = 480;//240;
  jata.jga.gamc = 480;//240;
  jata.jga.galb = -5;
  jata.jga.gaub = 5;
  jata.jga.scale = 100;
  jata.jga.shrink = 1;

  if(jata.jmpi.id == 0 ){
    printf("My id is %d out of %d procs\n", jata.jmpi.id, jata.jmpi.procs);
    printf("Creating ipopulation\n");
    runjga_create_ipopulation();
    for (jata.jga.gen = 0; jata.jga.gen < jata.jga.genmax; jata.jga.gen++){
      jata.jmpi.r[2] = 0;
      while (jata.jmpi.r[2] < gapop){
	jata.jmpi.r[0] = 1;
	while (jata.jmpi.r[0] < jata.jmpi.procs){
	  //printf("Checking past results for %d and %d\n", jata.jga.genmax, jata.jmpi.r[2]);
	  jata.jga.id = jata.jmpi.r[2];
	  //runjga_check_res();
	  if (jata.jga.res[jata.jmpi.r[2]] < -100){
	    //time(&jata.tm);
	    //printf("%s: Sending %d to pid %d\n", ctime(&jata.tm), jata.jmpi.r[2], jata.jmpi.r[0]);
	    //fflush(stdout);
	    jata.jmpi.ierr = MPI_Isend(&jata.jga.cpop[jata.jmpi.r[2]][0], gavar, MPI_INT, jata.jmpi.r[0], 101, MPI_COMM_WORLD, &jata.jmpi.request);
	    MPI_Wait(&jata.jmpi.request,&jata.jmpi.status);
	    //printf("ierr is %d\n", jata.jmpi.ierr);
	    jata.jmpi.nproc[jata.jmpi.r[0]] = jata.jmpi.r[2];
	    //printf("nproc %d -> %d\n", jata.jmpi.r[0], jata.jmpi.r[2]);
	    jata.jmpi.r[0]++;
	  }
	  else{
	    runjga_write_res();
	  }
	  jata.jmpi.r[2]++;
	  if (jata.jmpi.r[2] >= gapop) break;
	}
	if (jata.jmpi.r[2] < gapop){
	  jata.jga.id = jata.jmpi.r[2];
	  runjgajam();
	  //printf("Now writing master calculated\n");
	  runjga_write_res();
	  jata.jmpi.r[2]++;
	}
	for (jata.jmpi.r[1] = 1; jata.jmpi.r[1] < jata.jmpi.r[0]; jata.jmpi.r[1]++){
	  //printf("Master to start recieving\n");
	  jata.jmpi.ierr = MPI_Irecv(&jata.jmpi.tres, 1, MPI_LONG, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &jata.jmpi.request);
	  MPI_Wait(&jata.jmpi.request,&jata.jmpi.status);
	  jata.jga.res[jata.jmpi.nproc[jata.jmpi.status.MPI_SOURCE]] = jata.jmpi.tres;
	  //time(&jata.tm);
	  //printf("%s: Master received %g from %d for gid %d\n", ctime(&jata.tm), jata.jmpi.tres, jata.jmpi.status.MPI_SOURCE, jata.jmpi.nproc[jata.jmpi.status.MPI_SOURCE]);
	  //fflush(stdout);
	  //printf("Now writing recieved\n");
	  jata.jga.id = jata.jmpi.nproc[jata.jmpi.status.MPI_SOURCE];
	  runjga_write_res();
	}
	if (jata.jmpi.r[2] >= gaspop){
	  break;
	}
      }
      printf("Creating npopulation for %d generation\n", jata.jga.gen);
      runjga_create_npopulation();
    }
    jata.jga.cpop[0][0] = -101;
    jata.jga.cpop[0][1] = -101;
    for (jata.jmpi.r[0] = 1; jata.jmpi.r[0] < jata.jmpi.procs; jata.jmpi.r[0]++){
      time(&jata.tm);
      printf("%s: Sending -101 to pid %d\n", ctime(&jata.tm), jata.jmpi.r[0]);
      fflush(stdout);
      jata.jmpi.ierr = MPI_Isend(&jata.jga.cpop[0][0], gavar, MPI_INT, jata.jmpi.r[0], 101, MPI_COMM_WORLD, &jata.jmpi.request);
    }
  }
  else{
    printf("I am a slave with an id of %d\n", jata.jmpi.id);
    jata.jmpi.r[0] = 0;
    while (jata.jmpi.r[0] == 0){
      jata.jmpi.ierr = MPI_Irecv(&jata.jga.cpop[0][0], gavar, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &jata.jmpi.request);
      MPI_Wait(&jata.jmpi.request,&jata.jmpi.status);
      //time(&jata.tm);
      //printf("%s: %d id recieved %d and %d from master\n", ctime(&jata.tm), jata.jmpi.id, jata.jga.cpop[0][0], jata.jga.cpop[0][1]);
      //fflush(stdout);
      if (jata.jga.cpop[0][0] == -101){
	jata.jmpi.r[0] = 1;
	time(&jata.tm);
	printf("%s: %d id recieved -101\n", ctime(&jata.tm), jata.jmpi.id);
	fflush(stdout);
	break;
      }
      //printf("%d will execute runjgajam\n", jata.jmpi.id);
      runjgajam();
      //time(&jata.tm);
      //printf("%s: %d id will send %g to master\n", ctime(&jata.tm), jata.jmpi.id, jata.jmpi.tres);
      //fflush(stdout);
      jata.jmpi.ierr = MPI_Isend(&jata.jga.res[0], 1, MPI_LONG, 0, 101, MPI_COMM_WORLD, &jata.jmpi.request);
      MPI_Wait(&jata.jmpi.request,&jata.jmpi.status);
      //printf("%d id sent %g to master\n", jata.jmpi.id, jata.jmpi.tres);
    }
  }
  jata.jmpi.ierr = MPI_Finalize();
  return 0;
}