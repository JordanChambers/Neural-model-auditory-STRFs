#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include <fftw3.h>
#include <mpi.h>
#include <time.h>
#include "./jtel/jheaders.h"
#include "./jtel/jstructure.c"
#include "./jtel/jsoundsignal.c"
#include "./jtel/jwav2aud.c"
#include "./jtel/jnetwork.c"
#include "./jtel/jnetwork_is.c"
#include "./jtel/jstrf.c"
#include "./jtel/jga.c"

#define jjopt 50
#define jjoptr 2
#include "./jtel/jamsyn_dai003b-d2act02.c"
//#include "./jtel/jamsyn_dai003b-d2act03.c"
//#include "./jtel/jamsyn_dai003b-d2act04.c"
//#include "./jtel/jamsyn_dai003b-d2act05.c"
//#include "./jtel/jamsyn_dai003b-d2act06.c"

//#define jjopt 51
//#define jjoptr 6
//#include "./jtel/jamsyn_dai003b-d2pas02.c"
//#include "./jtel/jamsyn_dai003b-d2pas03.c"
//#include "./jtel/jamsyn_dai003b-d2pas04.c"
//#include "./jtel/jamsyn_dai003b-d2pas05.c"
//#include "./jtel/jamsyn_dai003b-d2pas06.c"

//#define jjopt 60
//#define jjoptr 6
//#include "./jtel/jamsyn_dai004c-a1act02.c"
//#include "./jtel/jamsyn_dai004c-a1act03.c"
//#include "./jtel/jamsyn_dai004c-a1act04.c"
//#include "./jtel/jamsyn_dai004c-a1act05.c"
//#include "./jtel/jamsyn_dai004c-a1act06.c"

//#define jjopt 61
//#define jjoptr 6
//#include "./jtel/jamsyn_dai004c-a1pas02.c"
//#include "./jtel/jamsyn_dai004c-a1pas03.c"
//#include "./jtel/jamsyn_dai004c-a1pas04.c"
//#include "./jtel/jamsyn_dai004c-a1pas05.c"
//#include "./jtel/jamsyn_dai004c-a1pas06.c"

//#define jjopt 80
//#define jjoptr 6
//#include "./jtel/jamsyn_dai006a-c1act02.c"
//#include "./jtel/jamsyn_dai006a-c1act03.c"
//#include "./jtel/jamsyn_dai006a-c1act04.c"
//#include "./jtel/jamsyn_dai006a-c1act05.c"
//#include "./jtel/jamsyn_dai006a-c1act06.c"

//#define jjopt 81
//#define jjoptr 6
//#include "./jtel/jamsyn_dai006a-c1pas02.c"
//#include "./jtel/jamsyn_dai006a-c1pas03.c"
//#include "./jtel/jamsyn_dai006a-c1pas04.c"
//#include "./jtel/jamsyn_dai006a-c1pas05.c"
//#include "./jtel/jamsyn_dai006a-c1pas06.c"

//#define jjopt 110
//#define jjoptr 2
//#include "./jtel/jamsyn_dai008b-c1act02.c"
//#include "./jtel/jamsyn_dai008b-c1act03.c"
//#include "./jtel/jamsyn_dai008b-c1act04.c"
//#include "./jtel/jamsyn_dai008b-c1act05.c"
//#include "./jtel/jamsyn_dai008b-c1act06.c"

//#define jjopt 111
//#define jjoptr 2
//#include "./jtel/jamsyn_dai008b-c1pas02.c"
//#include "./jtel/jamsyn_dai008b-c1pas03.c"
//#include "./jtel/jamsyn_dai008b-c1pas04.c"
//#include "./jtel/jamsyn_dai008b-c1pas05.c"
//#include "./jtel/jamsyn_dai008b-c1pas06.c"

//#define jjopt 130
//#define jjoptr 6
//#include "./jtel/jamsyn_dai009a-c2act02.c"
//#include "./jtel/jamsyn_dai009a-c2act03.c"
//#include "./jtel/jamsyn_dai009a-c2act04.c"
//#include "./jtel/jamsyn_dai009a-c2act05.c"
//#include "./jtel/jamsyn_dai009a-c2act06.c"

//#define jjopt 131
//#define jjoptr 6
//#include "./jtel/jamsyn_dai009a-c2pas02.c"
//#include "./jtel/jamsyn_dai009a-c2pas03.c"
//#include "./jtel/jamsyn_dai009a-c2pas04.c"
//#include "./jtel/jamsyn_dai009a-c2pas05.c"
//#include "./jtel/jamsyn_dai009a-c2pas06.c"

//#define jjopt 140
//#define jjoptr 6
//#include "./jtel/jamsyn_dai010a-d1act02.c"
//#include "./jtel/jamsyn_dai010a-d1act03.c"
//#include "./jtel/jamsyn_dai010a-d1act04.c"
//#include "./jtel/jamsyn_dai010a-d1act05.c"
//#include "./jtel/jamsyn_dai010a-d1act06.c"

//#define jjopt 141
//#define jjoptr 6
//#include "./jtel/jamsyn_dai010a-d1pas02.c"
//#include "./jtel/jamsyn_dai010a-d1pas03.c"
//#include "./jtel/jamsyn_dai010a-d1pas04.c"
//#include "./jtel/jamsyn_dai010a-d1pas05.c"
//#include "./jtel/jamsyn_dai010a-d1pas06.c"

//#define jjopt 230
//#define jjoptr 2
//#include "./jtel/jamsyn_tel007a-g1act02.c"
//#include "./jtel/jamsyn_tel007a-g1act03.c"
//#include "./jtel/jamsyn_tel007a-g1act04.c"
//#include "./jtel/jamsyn_tel007a-g1act05.c"
//#include "./jtel/jamsyn_tel007a-g1act06.c"

//#define jjopt 231
//#define jjoptr 2
//#include "./jtel/jamsyn_tel007a-g1pas02.c"
//#include "./jtel/jamsyn_tel007a-g1pas03.c"
//#include "./jtel/jamsyn_tel007a-g1pas04.c"
//#include "./jtel/jamsyn_tel007a-g1pas05.c"
//#include "./jtel/jamsyn_tel007a-g1pas06.c"

//#define jjopt 240
//#define jjoptr 2
//#include "./jtel/jamsyn_tel007a-h1act02.c"
//#include "./jtel/jamsyn_tel007a-h1act03.c"
//#include "./jtel/jamsyn_tel007a-h1act04.c"
//#include "./jtel/jamsyn_tel007a-h1act05.c"
//#include "./jtel/jamsyn_tel007a-h1act06.c"

//#define jjopt 241
//#define jjoptr 2
//#include "./jtel/jamsyn_tel007a-h1pas02.c"
//#include "./jtel/jamsyn_tel007a-h1pas03.c"
//#include "./jtel/jamsyn_tel007a-h1pas04.c"
//#include "./jtel/jamsyn_tel007a-h1pas05.c"
//#include "./jtel/jamsyn_tel007a-h1pas06.c"

int main(void)
{
  //printf("In mpi main\n");
  srand(3);
  jata.jga.cindex = 13;
  jata.jopt = jjopt;
  if (jata.jopt == 50){
    jata.jga.cindex = 12;
    sprintf(&jata.jresname[0], "./results/sendai003b-d2act0%d.txt", jjoptr); //12
  }
  else if (jata.jopt == 51){
    jata.jga.cindex = 12;
    sprintf(&jata.jresname[0], "./results/sendai003b-d2pas0%d.txt", jjoptr); //12
  }
  else if (jata.jopt == 60){
    jata.jga.cindex = 13;
    sprintf(&jata.jresname[0], "./results/sendai004c-a1act0%d.txt", jjoptr); //13
  }
  else if (jata.jopt == 61){
    jata.jga.cindex = 13;
    sprintf(&jata.jresname[0], "./results/sendai004c-a1pas0%d.txt", jjoptr); //13
  }
  else if (jata.jopt == 80){
    jata.jga.cindex = 12;
    sprintf(&jata.jresname[0], "./results/sendai006a-c1act0%d.txt", jjoptr); //12
  }
  else if (jata.jopt == 81){
    jata.jga.cindex = 12;
    sprintf(&jata.jresname[0], "./results/sendai006a-c1pas0%d.txt", jjoptr); //12
  }
  else if (jata.jopt == 110){
    jata.jga.cindex = 14;
    sprintf(&jata.jresname[0], "./results/sendai008b-c1act0%d.txt", jjoptr); //14
  }
  else if (jata.jopt == 111){
    jata.jga.cindex = 14;
    sprintf(&jata.jresname[0], "./results/sendai008b-c1pas0%d.txt", jjoptr); //14
  }
  else if (jata.jopt == 130){
    jata.jga.cindex = 11;
    sprintf(&jata.jresname[0], "./results/sendai009a-c2act0%d.txt", jjoptr); //11
  }
  else if (jata.jopt == 131){
    jata.jga.cindex = 11;
    sprintf(&jata.jresname[0], "./results/sendai009a-c2pas0%d.txt", jjoptr); //11
  }
  else if (jata.jopt == 140){
    jata.jga.cindex = 10;
    sprintf(&jata.jresname[0], "./results/sendai010a-d1act0%d.txt", jjoptr); //10
  }
  else if (jata.jopt == 141){
    jata.jga.cindex = 10;
    sprintf(&jata.jresname[0], "./results/sendai010a-d1pas0%d.txt", jjoptr); //10
  }
  else if (jata.jopt == 230){
    jata.jga.cindex = 4;
    sprintf(&jata.jresname[0], "./results/sentel007a-g1act0%d.txt", jjoptr); //4
  }
  else if (jata.jopt == 231){
    jata.jga.cindex = 4;
    sprintf(&jata.jresname[0], "./results/sentel007a-g1pas0%d.txt", jjoptr); //4
  }
  else if (jata.jopt == 240){
    jata.jga.cindex = 7;
    sprintf(&jata.jresname[0], "./results/sentel007a-h1act0%d.txt", jjoptr); //7
  }
  else if (jata.jopt == 241){
    jata.jga.cindex = 7;
    sprintf(&jata.jresname[0], "./results/sentel007a-h1pas0%d.txt", jjoptr); //7
  }
  jata.jmpi.ierr = MPI_Init(&jata.jmpi.argc, jata.jmpi.argv);
  
  jata.jmpi.ierr = MPI_Comm_rank(MPI_COMM_WORLD, &jata.jmpi.id);
  jata.jmpi.ierr = MPI_Comm_size(MPI_COMM_WORLD, &jata.jmpi.procs);

  jata.jga.gen = 0;
  jata.jga.genmax = 1000;
  jata.jga.gaec = 10;
  jata.jga.gacc = 60;
  jata.jga.gamc = 30;
  jata.jga.galb = -5;
  jata.jga.gaub = 5;
  jata.jga.scale = 100;
  jata.jga.shrink = 1;

  if(jata.jmpi.id == 0 ){
    printf("My id is %d out of %d procs\n", jata.jmpi.id, jata.jmpi.procs);
    printf("Creating ipopulation\n");
    runjga_create_spopulation();
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
