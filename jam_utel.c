#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include <fftw3.h>
#include <mpi.h>
#include "./jtel/jheaders.h"
#include "./jtel/jstructure.c"
#include "./jtel/jsoundsignal.c"
#include "./jtel/jwav2aud.c"
#include "./jtel/jnetwork.c"
#include "./jtel/jnetwork_is.c"
#include "./jtel/jstrf.c"
#include "./jtel/jga.c"

#define jjopt 0
#define jjoptr 6
#include "./jtel/jamsyn_dai003b-d2act02.c"

int main(void)
{
  //printf("In main\n");
  srand(3);
  jata.jga.id = 0;
  jata.jga.gen = 0;
  jata.jga.genmax = 1000;
  jata.jga.gaec = 10;
  jata.jga.gacc = gapop - jata.jga.gaec;
  jata.jga.gamc = 30;
  jata.jga.galb = -5;
  jata.jga.gaub = 5;
  jata.jga.scale = 1;
  jata.jga.shrink = 1;
  jata.jga.cindex = 11;
  jata.jopt = jjopt;
  if (jata.jopt == 50){
    jata.jga.cindex = 12;
  }
  else if (jata.jopt == 51){
    jata.jga.cindex = 12;
  }
  else if (jata.jopt == 60){
    jata.jga.cindex = 13;
  }
  else if (jata.jopt == 61){
    jata.jga.cindex = 13;
  }
  else if (jata.jopt == 80){
    jata.jga.cindex = 12;
  }
  else if (jata.jopt == 81){
    jata.jga.cindex = 12;
  }
  else if (jata.jopt == 110){
    jata.jga.cindex = 14;
  }
  else if (jata.jopt == 111){
    jata.jga.cindex = 14;
  }
  else if (jata.jopt == 130){
    jata.jga.cindex = 11;
  }
  else if (jata.jopt == 131){
    jata.jga.cindex = 11;
  }
  else if (jata.jopt == 140){
    jata.jga.cindex = 10;
  }
  else if (jata.jopt == 141){
    jata.jga.cindex = 10;
  }
  else if (jata.jopt == 230){
    jata.jga.cindex = 4;
  }
  else if (jata.jopt == 231){
    jata.jga.cindex = 4;
  }
  else if (jata.jopt == 240){
    jata.jga.cindex = 7;
  }
  else if (jata.jopt == 241){
    jata.jga.cindex = 7;
  }
  else{
    printf("missed jopt %d\n", jata.jopt);
  }
  //jam_syns();
  jata.jga.cpop[jata.jga.id][225] = 2; // i0
  jata.jga.cpop[jata.jga.id][226] = 2; // i1
  jata.jga.cpop[jata.jga.id][227] = 2; // i2
  jata.jga.cpop[jata.jga.id][228] = 2; // i3
  jata.jga.cpop[jata.jga.id][229] = 2; // i4
  jata.jga.cpop[jata.jga.id][230] = 2; // i5
  jata.jga.cpop[jata.jga.id][231] = 2; // i6
  jata.jga.cpop[jata.jga.id][232] = 2; // i7
  jata.jga.cpop[jata.jga.id][233] = 2; // i8
  jata.jga.cpop[jata.jga.id][234] = 2; // i9
  jata.jga.cpop[jata.jga.id][235] = 2; // i10
  jata.jga.cpop[jata.jga.id][236] = 2; // i11
  jata.jga.cpop[jata.jga.id][237] = 2; // i12
  jata.jga.cpop[jata.jga.id][238] = 2; // i13
  jata.jga.cpop[jata.jga.id][239] = 2; // i14
  jata.jga.cpop[jata.jga.id][240] = 0; // i0
  jata.jga.cpop[jata.jga.id][241] = 0; // i1
  jata.jga.cpop[jata.jga.id][242] = 0; // i2
  jata.jga.cpop[jata.jga.id][243] = 0; // i3
  jata.jga.cpop[jata.jga.id][244] = 0; // i4
  jata.jga.cpop[jata.jga.id][245] = 0; // i5
  jata.jga.cpop[jata.jga.id][246] = 0; // i6
  jata.jga.cpop[jata.jga.id][247] = 0; // i7
  jata.jga.cpop[jata.jga.id][248] = 0; // i8
  jata.jga.cpop[jata.jga.id][249] = 0; // i9
  jata.jga.cpop[jata.jga.id][250] = 0; // i10
  jata.jga.cpop[jata.jga.id][251] = 0; // i11
  jata.jga.cpop[jata.jga.id][252] = 0; // i12
  jata.jga.cpop[jata.jga.id][253] = 0; // i13
  jata.jga.cpop[jata.jga.id][254] = 0; // i14
  runjgajam();
  jata.r[4] = jjoptr;
  for (jata.r[0] = 0; jata.r[0] < cellnumb+topdc; jata.r[0]++){
    printf("The total action potential count for cell %d was %d\n", jata.r[0], jata.taps[jata.r[0]]);
  }
  for (jata.r[0] = 0; jata.r[0] < cellnumb; jata.r[0]++){
    printf("The total action potential count for cell %d was %d\n", jata.r[0], jata.taps[jata.r[0]]);
    if (jata.jopt == 50){
      jata.jga.cindex = 12;
      sprintf(&jata.fname[0], "./output/jamsyn_dai003b-d2act0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 51){
      jata.jga.cindex = 12;
      sprintf(&jata.fname[0], "./output/jamsyn_dai003b-d2pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 60){
      jata.jga.cindex = 13;
      sprintf(&jata.fname[0], "./output/jamsyn_dai004c-a1act0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 61){
      jata.jga.cindex = 13;
      sprintf(&jata.fname[0], "./output/jamsyn_dai004c-a1pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 80){
      jata.jga.cindex = 12;
      sprintf(&jata.fname[0], "./output/jamsyn_dai006a-c1act0%d%dns.txt", jata.r[4], jata.r[0]);  
    }
    else if (jata.jopt == 81){
      jata.jga.cindex = 12;
      sprintf(&jata.fname[0], "./output/jamsyn_dai006a-c1pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 110){
      jata.jga.cindex = 14;
      sprintf(&jata.fname[0], "./output/jamsyn_dai008b-c1act0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 111){
      jata.jga.cindex = 14;
      sprintf(&jata.fname[0], "./output/jamsyn_dai008b-c1pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 130){
      jata.jga.cindex = 11;
      sprintf(&jata.fname[0], "./output/jamsyn_dai009a-c2act0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 131){
      jata.jga.cindex = 11;
      sprintf(&jata.fname[0], "./output/jamsyn_dai009a-c2pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 140){
      jata.jga.cindex = 10;
      sprintf(&jata.fname[0], "./output/jamsyn_dai010a-d1act0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 141){
      jata.jga.cindex = 10;
      sprintf(&jata.fname[0], "./output/jamsyn_dai010a-d1pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 230){
      jata.jga.cindex = 4;
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-g1act0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 231){
      jata.jga.cindex = 4;
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-g1pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 240){
      jata.jga.cindex = 7;
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-h1act0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 241){
      jata.jga.cindex = 7;
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-h1pas0%d%dns.txt", jata.r[4], jata.r[0]);
    }
    else{
      printf("missed jopt %d\n", jata.jopt);
      sprintf(&jata.fname[0], "./output/fig3a%dns.txt", jata.r[4], jata.r[0]);
    }

    jata.f = fopen(&jata.fname[0], "w");
    for (jata.r[1] = 0; jata.r[1] < ftorc; jata.r[1]++){
      for (jata.r[2] = 0; jata.r[2] < ttorc; jata.r[2]++){
	fprintf(jata.f, "%g ", jata.tavestrf[jata.r[0]][jata.r[1]][jata.r[2]]);
      }
      fprintf(jata.f, "\n");
    }
    fclose(jata.f);
    if (jata.jopt == 50){
      sprintf(&jata.fname[0], "./output/jamsyn_dai003b-d2act0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 51){
      sprintf(&jata.fname[0], "./output/jamsyn_dai003b-d2pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 60){
      sprintf(&jata.fname[0], "./output/jamsyn_dai004c-a1act0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 61){
      sprintf(&jata.fname[0], "./output/jamsyn_dai004c-a1pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 80){
      sprintf(&jata.fname[0], "./output/jamsyn_dai006a-c1act0%d%dsm.txt", jata.r[4], jata.r[0]);  
    }
    else if (jata.jopt == 81){
      sprintf(&jata.fname[0], "./output/jamsyn_dai006a-c1pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 110){
      sprintf(&jata.fname[0], "./output/jamsyn_dai008b-c1act0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 111){
      sprintf(&jata.fname[0], "./output/jamsyn_dai008b-c1pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 130){
      sprintf(&jata.fname[0], "./output/jamsyn_dai009a-c2act0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 131){
      sprintf(&jata.fname[0], "./output/jamsyn_dai009a-c2pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 140){
      sprintf(&jata.fname[0], "./output/jamsyn_dai010a-d1act0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 141){
      sprintf(&jata.fname[0], "./output/jamsyn_dai010a-d1pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 230){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-g1act0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 231){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-g1pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 240){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-h1act0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 241){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-h1pas0%d%dsm.txt", jata.r[4], jata.r[0]);
    }
    else{
      printf("missed jopt %d\n", jata.jopt);
      sprintf(&jata.fname[0], "./output/fig3a%dsm.txt", jata.r[4], jata.r[0]);
    }
    jata.f = fopen(&jata.fname[0], "w");
    for (jata.r[1] = 0; jata.r[1] < sftorc; jata.r[1]++){
      for (jata.r[2] = 0; jata.r[2] < sttorc; jata.r[2]++){
	fprintf(jata.f, "%g ", jata.smoothstrf[jata.r[0]][jata.r[1]][jata.r[2]]);
      }
      fprintf(jata.f, "\n");
    }
    fclose(jata.f);
    if (jata.jopt == 50){
      sprintf(&jata.fname[0], "./output/jamsyn_dai003b-d2act0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 51){
      sprintf(&jata.fname[0], "./output/jamsyn_dai003b-d2pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 60){
      sprintf(&jata.fname[0], "./output/jamsyn_dai004c-a1act0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 61){
      sprintf(&jata.fname[0], "./output/jamsyn_dai004c-a1pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 80){
      sprintf(&jata.fname[0], "./output/jamsyn_dai006a-c1act0%d%dsmg3.txt", jata.r[4], jata.r[0]);  
    }
    else if (jata.jopt == 81){
      sprintf(&jata.fname[0], "./output/jamsyn_dai006a-c1pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 110){
      sprintf(&jata.fname[0], "./output/jamsyn_dai008b-c1act0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 111){
      sprintf(&jata.fname[0], "./output/jamsyn_dai008b-c1pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 130){
      sprintf(&jata.fname[0], "./output/jamsyn_dai009a-c2act0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 131){
      sprintf(&jata.fname[0], "./output/jamsyn_dai009a-c2pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 140){
      sprintf(&jata.fname[0], "./output/jamsyn_dai010a-d1act0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 141){
      sprintf(&jata.fname[0], "./output/jamsyn_dai010a-d1pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 230){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-g1act0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 231){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-g1pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 240){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-h1act0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else if (jata.jopt == 241){
      sprintf(&jata.fname[0], "./output/jamsyn_tel007a-h1pas0%d%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    else{
      printf("missed jopt %d\n", jata.jopt);
      sprintf(&jata.fname[0], "./output/fig3a%dsmg3.txt", jata.r[4], jata.r[0]);
    }
    jata.f = fopen(&jata.fname[0], "w");
    for (jata.r[1] = 0; jata.r[1] < sftorc; jata.r[1]++){
      for (jata.r[2] = 0; jata.r[2] < sttorc; jata.r[2]++){
	if (fabs(jata.tsmoothstrf[jata.r[0]][jata.r[1]][jata.r[2]]) > 3){
	  fprintf(jata.f, "%g ", jata.tsmoothstrf[jata.r[0]][jata.r[1]][jata.r[2]]);
	}
	else fprintf(jata.f, "0 ");
      }
      fprintf(jata.f, "\n");
    }
    fclose(jata.f);
  }
  for (jata.r[0] = 0; jata.r[0] < cellnumb; jata.r[0]++){
    printf("%d ", jata.taps[jata.r[0]]);
  }
  printf("\n");
  printf("Cost is %g\n", jata.jga.res[jata.jga.id]);
  printf("Total action potential count was %d\n", jata.taps[jata.jga.cindex]);
  return 0;
}
/*
void jam_syns(void)
{

jata.jga.cpop[jata.jga.id][0] = -3;
jata.jga.cpop[jata.jga.id][1] = 2;
jata.jga.cpop[jata.jga.id][2] = 5;
jata.jga.cpop[jata.jga.id][3] = 2;
jata.jga.cpop[jata.jga.id][4] = 4;
jata.jga.cpop[jata.jga.id][5] = 2;
jata.jga.cpop[jata.jga.id][6] = 3;
jata.jga.cpop[jata.jga.id][7] = -4;
jata.jga.cpop[jata.jga.id][8] = -4;
jata.jga.cpop[jata.jga.id][9] = 4;
jata.jga.cpop[jata.jga.id][10] = 0;
jata.jga.cpop[jata.jga.id][11] = -3;
jata.jga.cpop[jata.jga.id][12] = 0;
jata.jga.cpop[jata.jga.id][13] = 5;
jata.jga.cpop[jata.jga.id][14] = 2;
jata.jga.cpop[jata.jga.id][15] = 4;
jata.jga.cpop[jata.jga.id][16] = 5;
jata.jga.cpop[jata.jga.id][17] = -2;
jata.jga.cpop[jata.jga.id][18] = -3;
jata.jga.cpop[jata.jga.id][19] = -2;
jata.jga.cpop[jata.jga.id][20] = -2;
jata.jga.cpop[jata.jga.id][21] = -1;
jata.jga.cpop[jata.jga.id][22] = 5;
jata.jga.cpop[jata.jga.id][23] = 0;
jata.jga.cpop[jata.jga.id][24] = 1;
jata.jga.cpop[jata.jga.id][25] = 0;
jata.jga.cpop[jata.jga.id][26] = 3;
jata.jga.cpop[jata.jga.id][27] = 4;
jata.jga.cpop[jata.jga.id][28] = -2;
jata.jga.cpop[jata.jga.id][29] = 3;
jata.jga.cpop[jata.jga.id][30] = 5;
jata.jga.cpop[jata.jga.id][31] = -2;
jata.jga.cpop[jata.jga.id][32] = -4;
jata.jga.cpop[jata.jga.id][33] = -3;
jata.jga.cpop[jata.jga.id][34] = -3;
jata.jga.cpop[jata.jga.id][35] = 2;
jata.jga.cpop[jata.jga.id][36] = -1;
jata.jga.cpop[jata.jga.id][37] = -4;
jata.jga.cpop[jata.jga.id][38] = -1;
jata.jga.cpop[jata.jga.id][39] = 4;
jata.jga.cpop[jata.jga.id][40] = 2;
jata.jga.cpop[jata.jga.id][41] = 1;
jata.jga.cpop[jata.jga.id][42] = -4;
jata.jga.cpop[jata.jga.id][43] = -2;
jata.jga.cpop[jata.jga.id][44] = 2;
jata.jga.cpop[jata.jga.id][45] = -1;
jata.jga.cpop[jata.jga.id][46] = 0;
jata.jga.cpop[jata.jga.id][47] = -1;
jata.jga.cpop[jata.jga.id][48] = -1;
jata.jga.cpop[jata.jga.id][49] = 2;
jata.jga.cpop[jata.jga.id][50] = 0;
jata.jga.cpop[jata.jga.id][51] = -3;
jata.jga.cpop[jata.jga.id][52] = 2;
jata.jga.cpop[jata.jga.id][53] = 0;
jata.jga.cpop[jata.jga.id][54] = -2;
jata.jga.cpop[jata.jga.id][55] = 0;
jata.jga.cpop[jata.jga.id][56] = 1;
jata.jga.cpop[jata.jga.id][57] = 1;
jata.jga.cpop[jata.jga.id][58] = 5;
jata.jga.cpop[jata.jga.id][59] = -3;
jata.jga.cpop[jata.jga.id][60] = -1;
jata.jga.cpop[jata.jga.id][61] = 4;
jata.jga.cpop[jata.jga.id][62] = 1;
jata.jga.cpop[jata.jga.id][63] = 3;
jata.jga.cpop[jata.jga.id][64] = 4;
jata.jga.cpop[jata.jga.id][65] = 2;
jata.jga.cpop[jata.jga.id][66] = 0;
jata.jga.cpop[jata.jga.id][67] = 1;
jata.jga.cpop[jata.jga.id][68] = 2;
jata.jga.cpop[jata.jga.id][69] = -4;
jata.jga.cpop[jata.jga.id][70] = 2;
jata.jga.cpop[jata.jga.id][71] = 0;
jata.jga.cpop[jata.jga.id][72] = 4;
jata.jga.cpop[jata.jga.id][73] = 0;
jata.jga.cpop[jata.jga.id][74] = 1;
jata.jga.cpop[jata.jga.id][75] = 0;
jata.jga.cpop[jata.jga.id][76] = 3;
jata.jga.cpop[jata.jga.id][77] = 0;
jata.jga.cpop[jata.jga.id][78] = 1;
jata.jga.cpop[jata.jga.id][79] = 3;
jata.jga.cpop[jata.jga.id][80] = 0;
jata.jga.cpop[jata.jga.id][81] = 4;
jata.jga.cpop[jata.jga.id][82] = -4;
jata.jga.cpop[jata.jga.id][83] = -3;
jata.jga.cpop[jata.jga.id][84] = 4;
jata.jga.cpop[jata.jga.id][85] = -2;
jata.jga.cpop[jata.jga.id][86] = -3;
jata.jga.cpop[jata.jga.id][87] = 1;
jata.jga.cpop[jata.jga.id][88] = 4;
jata.jga.cpop[jata.jga.id][89] = 3;
jata.jga.cpop[jata.jga.id][90] = -4;
jata.jga.cpop[jata.jga.id][91] = 4;
jata.jga.cpop[jata.jga.id][92] = 2;
jata.jga.cpop[jata.jga.id][93] = -3;
jata.jga.cpop[jata.jga.id][94] = 2;
jata.jga.cpop[jata.jga.id][95] = -4;
jata.jga.cpop[jata.jga.id][96] = -1;
jata.jga.cpop[jata.jga.id][97] = 2;
jata.jga.cpop[jata.jga.id][98] = -1;
jata.jga.cpop[jata.jga.id][99] = 0;
jata.jga.cpop[jata.jga.id][100] = 3;
jata.jga.cpop[jata.jga.id][101] = 0;
jata.jga.cpop[jata.jga.id][102] = -3;
jata.jga.cpop[jata.jga.id][103] = 0;
jata.jga.cpop[jata.jga.id][104] = 0;
jata.jga.cpop[jata.jga.id][105] = 5;
jata.jga.cpop[jata.jga.id][106] = 0;
jata.jga.cpop[jata.jga.id][107] = 4;
jata.jga.cpop[jata.jga.id][108] = 0;
jata.jga.cpop[jata.jga.id][109] = 4;
jata.jga.cpop[jata.jga.id][110] = 3;
jata.jga.cpop[jata.jga.id][111] = 3;
jata.jga.cpop[jata.jga.id][112] = 1;
jata.jga.cpop[jata.jga.id][113] = 4;
jata.jga.cpop[jata.jga.id][114] = 4;
jata.jga.cpop[jata.jga.id][115] = 0;
jata.jga.cpop[jata.jga.id][116] = -3;
jata.jga.cpop[jata.jga.id][117] = -3;
jata.jga.cpop[jata.jga.id][118] = 4;
jata.jga.cpop[jata.jga.id][119] = -2;
jata.jga.cpop[jata.jga.id][120] = 0;
jata.jga.cpop[jata.jga.id][121] = 3;
jata.jga.cpop[jata.jga.id][122] = 0;
jata.jga.cpop[jata.jga.id][123] = -4;
jata.jga.cpop[jata.jga.id][124] = 5;
jata.jga.cpop[jata.jga.id][125] = 2;
jata.jga.cpop[jata.jga.id][126] = -4;
jata.jga.cpop[jata.jga.id][127] = 2;
jata.jga.cpop[jata.jga.id][128] = 3;
jata.jga.cpop[jata.jga.id][129] = 4;
jata.jga.cpop[jata.jga.id][130] = -2;
jata.jga.cpop[jata.jga.id][131] = 1;
jata.jga.cpop[jata.jga.id][132] = 5;
jata.jga.cpop[jata.jga.id][133] = 3;
jata.jga.cpop[jata.jga.id][134] = 3;
jata.jga.cpop[jata.jga.id][135] = 0;
jata.jga.cpop[jata.jga.id][136] = -3;
jata.jga.cpop[jata.jga.id][137] = -3;
jata.jga.cpop[jata.jga.id][138] = 2;
jata.jga.cpop[jata.jga.id][139] = 1;
jata.jga.cpop[jata.jga.id][140] = -4;
jata.jga.cpop[jata.jga.id][141] = 3;
jata.jga.cpop[jata.jga.id][142] = -2;
jata.jga.cpop[jata.jga.id][143] = -2;
jata.jga.cpop[jata.jga.id][144] = 2;
jata.jga.cpop[jata.jga.id][145] = -1;
jata.jga.cpop[jata.jga.id][146] = 5;
jata.jga.cpop[jata.jga.id][147] = 5;
jata.jga.cpop[jata.jga.id][148] = 4;
jata.jga.cpop[jata.jga.id][149] = 4;
jata.jga.cpop[jata.jga.id][150] = 2;
jata.jga.cpop[jata.jga.id][151] = -2;
jata.jga.cpop[jata.jga.id][152] = -3;
jata.jga.cpop[jata.jga.id][153] = 3;
jata.jga.cpop[jata.jga.id][154] = 1;
jata.jga.cpop[jata.jga.id][155] = 0;
jata.jga.cpop[jata.jga.id][156] = 3;
jata.jga.cpop[jata.jga.id][157] = 2;
jata.jga.cpop[jata.jga.id][158] = -2;
jata.jga.cpop[jata.jga.id][159] = -4;
jata.jga.cpop[jata.jga.id][160] = 0;
jata.jga.cpop[jata.jga.id][161] = 3;
jata.jga.cpop[jata.jga.id][162] = -4;
jata.jga.cpop[jata.jga.id][163] = -4;
jata.jga.cpop[jata.jga.id][164] = 1;
jata.jga.cpop[jata.jga.id][165] = -1;
jata.jga.cpop[jata.jga.id][166] = -4;
jata.jga.cpop[jata.jga.id][167] = 4;
jata.jga.cpop[jata.jga.id][168] = 1;
jata.jga.cpop[jata.jga.id][169] = 0;
jata.jga.cpop[jata.jga.id][170] = 2;
jata.jga.cpop[jata.jga.id][171] = 4;
jata.jga.cpop[jata.jga.id][172] = -1;
jata.jga.cpop[jata.jga.id][173] = -2;
jata.jga.cpop[jata.jga.id][174] = -4;
jata.jga.cpop[jata.jga.id][175] = 0;
jata.jga.cpop[jata.jga.id][176] = 5;
jata.jga.cpop[jata.jga.id][177] = 5;
jata.jga.cpop[jata.jga.id][178] = 4;
jata.jga.cpop[jata.jga.id][179] = 3;
jata.jga.cpop[jata.jga.id][180] = -1;
jata.jga.cpop[jata.jga.id][181] = -2;
jata.jga.cpop[jata.jga.id][182] = -4;
jata.jga.cpop[jata.jga.id][183] = -3;
jata.jga.cpop[jata.jga.id][184] = 4;
jata.jga.cpop[jata.jga.id][185] = 2;
jata.jga.cpop[jata.jga.id][186] = 0;
jata.jga.cpop[jata.jga.id][187] = 5;
jata.jga.cpop[jata.jga.id][188] = 5;
jata.jga.cpop[jata.jga.id][189] = -4;
jata.jga.cpop[jata.jga.id][190] = -3;
jata.jga.cpop[jata.jga.id][191] = 1;
jata.jga.cpop[jata.jga.id][192] = 0;
jata.jga.cpop[jata.jga.id][193] = 0;
jata.jga.cpop[jata.jga.id][194] = 0;
jata.jga.cpop[jata.jga.id][195] = -4;
jata.jga.cpop[jata.jga.id][196] = -4;
jata.jga.cpop[jata.jga.id][197] = 3;
jata.jga.cpop[jata.jga.id][198] = 3;
jata.jga.cpop[jata.jga.id][199] = 0;
jata.jga.cpop[jata.jga.id][200] = -1;
jata.jga.cpop[jata.jga.id][201] = 0;
jata.jga.cpop[jata.jga.id][202] = -3;
jata.jga.cpop[jata.jga.id][203] = 4;
jata.jga.cpop[jata.jga.id][204] = -1;
jata.jga.cpop[jata.jga.id][205] = 0;
jata.jga.cpop[jata.jga.id][206] = 5;
jata.jga.cpop[jata.jga.id][207] = 3;
jata.jga.cpop[jata.jga.id][208] = 4;
jata.jga.cpop[jata.jga.id][209] = 0;
jata.jga.cpop[jata.jga.id][210] = 4;
jata.jga.cpop[jata.jga.id][211] = -1;
jata.jga.cpop[jata.jga.id][212] = 3;
jata.jga.cpop[jata.jga.id][213] = 3;
jata.jga.cpop[jata.jga.id][214] = 0;
jata.jga.cpop[jata.jga.id][215] = 2;
jata.jga.cpop[jata.jga.id][216] = -1;
jata.jga.cpop[jata.jga.id][217] = -1;
jata.jga.cpop[jata.jga.id][218] = -4;
jata.jga.cpop[jata.jga.id][219] = -2;
jata.jga.cpop[jata.jga.id][220] = -4;
jata.jga.cpop[jata.jga.id][221] = -2;
jata.jga.cpop[jata.jga.id][222] = 0;
jata.jga.cpop[jata.jga.id][223] = -4;
jata.jga.cpop[jata.jga.id][224] = 3;
jata.jga.cpop[jata.jga.id][225] = -4;
jata.jga.cpop[jata.jga.id][226] = 0;
jata.jga.cpop[jata.jga.id][227] = -3;
jata.jga.cpop[jata.jga.id][228] = 3;
jata.jga.cpop[jata.jga.id][229] = 1;
jata.jga.cpop[jata.jga.id][230] = 2;
jata.jga.cpop[jata.jga.id][231] = -2;
jata.jga.cpop[jata.jga.id][232] = 4;
jata.jga.cpop[jata.jga.id][233] = -1;
jata.jga.cpop[jata.jga.id][234] = 0;
jata.jga.cpop[jata.jga.id][235] = 5;
jata.jga.cpop[jata.jga.id][236] = -1;
jata.jga.cpop[jata.jga.id][237] = -3;
jata.jga.cpop[jata.jga.id][238] = -1;
jata.jga.cpop[jata.jga.id][239] = -3;

}

void jam_syns_man(void)
{
  jata.jga.cpop[jata.jga.id][0] = 0; // 0 -> 0
  jata.jga.cpop[jata.jga.id][1] = 0; // 0 -> 1
  jata.jga.cpop[jata.jga.id][2] = 0; // 0 -> 2
  jata.jga.cpop[jata.jga.id][3] = 0; // 0 -> 3
  jata.jga.cpop[jata.jga.id][4] = 0; // 0 -> 4
  jata.jga.cpop[jata.jga.id][5] = 0; // 0 -> 5
  jata.jga.cpop[jata.jga.id][6] = 0; // 0 -> 6
  jata.jga.cpop[jata.jga.id][7] = 0; // 0 -> 7
  jata.jga.cpop[jata.jga.id][8] = 0; // 0 -> 8
  jata.jga.cpop[jata.jga.id][9] = 0; // 0 -> 9
  jata.jga.cpop[jata.jga.id][10] = 0; // 0 -> 10
  jata.jga.cpop[jata.jga.id][11] = 0; // 0 -> 11
  jata.jga.cpop[jata.jga.id][12] = 0; // 0 -> 12
  jata.jga.cpop[jata.jga.id][13] = 0; // 0 -> 13
  jata.jga.cpop[jata.jga.id][14] = 0; // 0 -> 14
  jata.jga.cpop[jata.jga.id][15] = 0; // 1 -> 0
  jata.jga.cpop[jata.jga.id][16] = 0; // 1 -> 1
  jata.jga.cpop[jata.jga.id][17] = 0; // 1 -> 2
  jata.jga.cpop[jata.jga.id][18] = 0; // 1 -> 3
  jata.jga.cpop[jata.jga.id][19] = 0; // 1 -> 4
  jata.jga.cpop[jata.jga.id][20] = 0; // 1 -> 5
  jata.jga.cpop[jata.jga.id][21] = 0; // 1 -> 6
  jata.jga.cpop[jata.jga.id][22] = 0; // 1 -> 7
  jata.jga.cpop[jata.jga.id][23] = 0; // 1 -> 8
  jata.jga.cpop[jata.jga.id][24] = 0; // 1 -> 9
  jata.jga.cpop[jata.jga.id][25] = 0; // 1 -> 10
  jata.jga.cpop[jata.jga.id][26] = 0; // 1 -> 11
  jata.jga.cpop[jata.jga.id][27] = 0; // 1 -> 12
  jata.jga.cpop[jata.jga.id][28] = 0; // 1 -> 13
  jata.jga.cpop[jata.jga.id][29] = 0; // 1 -> 14
  jata.jga.cpop[jata.jga.id][30] = 0; // 2 -> 0
  jata.jga.cpop[jata.jga.id][31] = 0; // 2 -> 1
  jata.jga.cpop[jata.jga.id][32] = 0; // 2 -> 2
  jata.jga.cpop[jata.jga.id][33] = 0; // 2 -> 3
  jata.jga.cpop[jata.jga.id][34] = 0; // 2 -> 4
  jata.jga.cpop[jata.jga.id][35] = 0; // 2 -> 5
  jata.jga.cpop[jata.jga.id][36] = 0; // 2 -> 6
  jata.jga.cpop[jata.jga.id][37] = 0; // 2 -> 7
  jata.jga.cpop[jata.jga.id][38] = 0; // 2 -> 8
  jata.jga.cpop[jata.jga.id][39] = 0; // 2 -> 9
  jata.jga.cpop[jata.jga.id][40] = 0; // 2 -> 10
  jata.jga.cpop[jata.jga.id][41] = 0; // 2 -> 11
  jata.jga.cpop[jata.jga.id][42] = 0; // 2 -> 12
  jata.jga.cpop[jata.jga.id][43] = 0; // 2 -> 13
  jata.jga.cpop[jata.jga.id][44] = 0; // 2 -> 14
  jata.jga.cpop[jata.jga.id][45] = 0; // 3 -> 0
  jata.jga.cpop[jata.jga.id][46] = 0; // 3 -> 1
  jata.jga.cpop[jata.jga.id][47] = 0; // 3 -> 2
  jata.jga.cpop[jata.jga.id][48] = 0; // 3 -> 3
  jata.jga.cpop[jata.jga.id][49] = 0; // 3 -> 4
  jata.jga.cpop[jata.jga.id][50] = 0; // 3 -> 5
  jata.jga.cpop[jata.jga.id][51] = 0; // 3 -> 6
  jata.jga.cpop[jata.jga.id][52] = 0; // 3 -> 7
  jata.jga.cpop[jata.jga.id][53] = 0; // 3 -> 8
  jata.jga.cpop[jata.jga.id][54] = 0; // 3 -> 9
  jata.jga.cpop[jata.jga.id][55] = 0; // 3 -> 10
  jata.jga.cpop[jata.jga.id][56] = 0; // 3 -> 11
  jata.jga.cpop[jata.jga.id][57] = 0; // 3 -> 12
  jata.jga.cpop[jata.jga.id][58] = 0; // 3 -> 13
  jata.jga.cpop[jata.jga.id][59] = 0; // 3 -> 14
  jata.jga.cpop[jata.jga.id][60] = 0; // 4 -> 0
  jata.jga.cpop[jata.jga.id][61] = 0; // 4 -> 1
  jata.jga.cpop[jata.jga.id][62] = 0; // 4 -> 2
  jata.jga.cpop[jata.jga.id][63] = 0; // 4 -> 3
  jata.jga.cpop[jata.jga.id][64] = 0; // 4 -> 4
  jata.jga.cpop[jata.jga.id][65] = 0; // 4 -> 5
  jata.jga.cpop[jata.jga.id][66] = 0; // 4 -> 6
  jata.jga.cpop[jata.jga.id][67] = 0; // 4 -> 7
  jata.jga.cpop[jata.jga.id][68] = 0; // 4 -> 8
  jata.jga.cpop[jata.jga.id][69] = 0; // 4 -> 9
  jata.jga.cpop[jata.jga.id][70] = 0; // 4 -> 10
  jata.jga.cpop[jata.jga.id][71] = 0; // 4 -> 11
  jata.jga.cpop[jata.jga.id][72] = 0; // 4 -> 12
  jata.jga.cpop[jata.jga.id][73] = 0; // 4 -> 13
  jata.jga.cpop[jata.jga.id][74] = 0; // 4 -> 14
  jata.jga.cpop[jata.jga.id][75] = 0; // 5 -> 0
  jata.jga.cpop[jata.jga.id][76] = 0; // 5 -> 1
  jata.jga.cpop[jata.jga.id][77] = 0; // 5 -> 2
  jata.jga.cpop[jata.jga.id][78] = 0; // 5 -> 3
  jata.jga.cpop[jata.jga.id][79] = 0; // 5 -> 4
  jata.jga.cpop[jata.jga.id][80] = 0; // 5 -> 5
  jata.jga.cpop[jata.jga.id][81] = 0; // 5 -> 6
  jata.jga.cpop[jata.jga.id][82] = 0; // 5 -> 7
  jata.jga.cpop[jata.jga.id][83] = 0; // 5 -> 8
  jata.jga.cpop[jata.jga.id][84] = 0; // 5 -> 9
  jata.jga.cpop[jata.jga.id][85] = 0; // 5 -> 10
  jata.jga.cpop[jata.jga.id][86] = 0; // 5 -> 11
  jata.jga.cpop[jata.jga.id][87] = 0; // 5 -> 12
  jata.jga.cpop[jata.jga.id][88] = 0; // 5 -> 13
  jata.jga.cpop[jata.jga.id][89] = 0; // 5 -> 14
  jata.jga.cpop[jata.jga.id][90] = 0; // 6 -> 0
  jata.jga.cpop[jata.jga.id][91] = 0; // 6 -> 1
  jata.jga.cpop[jata.jga.id][92] = 0; // 6 -> 2
  jata.jga.cpop[jata.jga.id][93] = 0; // 6 -> 3
  jata.jga.cpop[jata.jga.id][94] = 0; // 6 -> 4
  jata.jga.cpop[jata.jga.id][95] = 0; // 6 -> 5
  jata.jga.cpop[jata.jga.id][96] = 0; // 6 -> 6
  jata.jga.cpop[jata.jga.id][97] = 0; // 6 -> 7
  jata.jga.cpop[jata.jga.id][98] = 0; // 6 -> 8
  jata.jga.cpop[jata.jga.id][99] = 0; // 6 -> 9
  jata.jga.cpop[jata.jga.id][100] = 0; // 6 -> 10
  jata.jga.cpop[jata.jga.id][101] = 0; // 6 -> 11
  jata.jga.cpop[jata.jga.id][102] = 0; // 6 -> 12
  jata.jga.cpop[jata.jga.id][103] = 0; // 6 -> 13
  jata.jga.cpop[jata.jga.id][104] = 0; // 6 -> 14
  jata.jga.cpop[jata.jga.id][105] = 0; // 7 -> 0
  jata.jga.cpop[jata.jga.id][106] = 0; // 7 -> 1
  jata.jga.cpop[jata.jga.id][107] = 0; // 7 -> 2
  jata.jga.cpop[jata.jga.id][108] = 0; // 7 -> 3
  jata.jga.cpop[jata.jga.id][109] = 0; // 7 -> 4
  jata.jga.cpop[jata.jga.id][110] = 0; // 7 -> 5
  jata.jga.cpop[jata.jga.id][111] = 0; // 7 -> 6
  jata.jga.cpop[jata.jga.id][112] = 0; // 7 -> 7
  jata.jga.cpop[jata.jga.id][113] = 0; // 7 -> 8
  jata.jga.cpop[jata.jga.id][114] = 0; // 7 -> 9
  jata.jga.cpop[jata.jga.id][115] = 0; // 7 -> 10
  jata.jga.cpop[jata.jga.id][116] = 0; // 7 -> 11
  jata.jga.cpop[jata.jga.id][117] = 0; // 7 -> 12
  jata.jga.cpop[jata.jga.id][118] = 0; // 7 -> 13
  jata.jga.cpop[jata.jga.id][119] = 0; // 7 -> 14
  jata.jga.cpop[jata.jga.id][120] = 0; // 8 -> 0
  jata.jga.cpop[jata.jga.id][121] = 0; // 8 -> 1
  jata.jga.cpop[jata.jga.id][122] = 0; // 8 -> 2
  jata.jga.cpop[jata.jga.id][123] = 0; // 8 -> 3
  jata.jga.cpop[jata.jga.id][124] = 0; // 8 -> 4
  jata.jga.cpop[jata.jga.id][125] = 0; // 8 -> 5
  jata.jga.cpop[jata.jga.id][126] = 0; // 8 -> 6
  jata.jga.cpop[jata.jga.id][127] = 0; // 8 -> 7
  jata.jga.cpop[jata.jga.id][128] = 0; // 8 -> 8
  jata.jga.cpop[jata.jga.id][129] = 0; // 8 -> 9
  jata.jga.cpop[jata.jga.id][130] = 0; // 8 -> 10
  jata.jga.cpop[jata.jga.id][131] = 0; // 8 -> 11
  jata.jga.cpop[jata.jga.id][132] = 0; // 8 -> 12
  jata.jga.cpop[jata.jga.id][133] = 0; // 8 -> 13
  jata.jga.cpop[jata.jga.id][134] = 0; // 8 -> 14
  jata.jga.cpop[jata.jga.id][135] = 0; // 9 -> 0
  jata.jga.cpop[jata.jga.id][136] = 0; // 9 -> 1
  jata.jga.cpop[jata.jga.id][137] = 0; // 9 -> 2
  jata.jga.cpop[jata.jga.id][138] = 0; // 9 -> 3
  jata.jga.cpop[jata.jga.id][139] = 0; // 9 -> 4
  jata.jga.cpop[jata.jga.id][140] = 0; // 9 -> 5
  jata.jga.cpop[jata.jga.id][141] = 0; // 9 -> 6
  jata.jga.cpop[jata.jga.id][142] = 0; // 9 -> 7
  jata.jga.cpop[jata.jga.id][143] = 0; // 9 -> 8
  jata.jga.cpop[jata.jga.id][144] = 0; // 9 -> 9
  jata.jga.cpop[jata.jga.id][145] = 0; // 9 -> 10
  jata.jga.cpop[jata.jga.id][146] = 0; // 9 -> 11
  jata.jga.cpop[jata.jga.id][147] = 0; // 9 -> 12
  jata.jga.cpop[jata.jga.id][148] = 0; // 9 -> 13
  jata.jga.cpop[jata.jga.id][149] = 0; // 9 -> 14
  jata.jga.cpop[jata.jga.id][150] = 0; // 10 -> 0
  jata.jga.cpop[jata.jga.id][151] = 0; // 10 -> 1
  jata.jga.cpop[jata.jga.id][152] = 0; // 10 -> 2
  jata.jga.cpop[jata.jga.id][153] = 0; // 10 -> 3
  jata.jga.cpop[jata.jga.id][154] = 0; // 10 -> 4
  jata.jga.cpop[jata.jga.id][155] = 0; // 10 -> 5
  jata.jga.cpop[jata.jga.id][156] = 0; // 10 -> 6
  jata.jga.cpop[jata.jga.id][157] = 0; // 10 -> 7
  jata.jga.cpop[jata.jga.id][158] = 0; // 10 -> 8
  jata.jga.cpop[jata.jga.id][159] = 0; // 10 -> 9
  jata.jga.cpop[jata.jga.id][160] = 0; // 10 -> 10
  jata.jga.cpop[jata.jga.id][161] = 0; // 10 -> 11
  jata.jga.cpop[jata.jga.id][162] = 0; // 10 -> 12
  jata.jga.cpop[jata.jga.id][163] = 0; // 10 -> 13
  jata.jga.cpop[jata.jga.id][164] = 0; // 10 -> 14
  jata.jga.cpop[jata.jga.id][165] = 0; // 11 -> 0
  jata.jga.cpop[jata.jga.id][166] = 0; // 11 -> 1
  jata.jga.cpop[jata.jga.id][167] = 0; // 11 -> 2
  jata.jga.cpop[jata.jga.id][168] = 0; // 11 -> 3
  jata.jga.cpop[jata.jga.id][169] = 0; // 11 -> 4
  jata.jga.cpop[jata.jga.id][170] = 0; // 11 -> 5
  jata.jga.cpop[jata.jga.id][171] = 0; // 11 -> 6
  jata.jga.cpop[jata.jga.id][172] = 0; // 11 -> 7
  jata.jga.cpop[jata.jga.id][173] = 0; // 11 -> 8
  jata.jga.cpop[jata.jga.id][174] = 0; // 11 -> 9
  jata.jga.cpop[jata.jga.id][175] = 0; // 11 -> 10
  jata.jga.cpop[jata.jga.id][176] = 0; // 11 -> 11
  jata.jga.cpop[jata.jga.id][177] = 0; // 11 -> 12
  jata.jga.cpop[jata.jga.id][178] = 0; // 11 -> 13
  jata.jga.cpop[jata.jga.id][179] = 0; // 11 -> 14
  jata.jga.cpop[jata.jga.id][180] = 0; // 12 -> 0
  jata.jga.cpop[jata.jga.id][181] = 0; // 12 -> 1
  jata.jga.cpop[jata.jga.id][182] = 0; // 12 -> 2
  jata.jga.cpop[jata.jga.id][183] = 0; // 12 -> 3
  jata.jga.cpop[jata.jga.id][184] = 0; // 12 -> 4
  jata.jga.cpop[jata.jga.id][185] = 0; // 12 -> 5
  jata.jga.cpop[jata.jga.id][186] = 0; // 12 -> 6
  jata.jga.cpop[jata.jga.id][187] = 0; // 12 -> 7
  jata.jga.cpop[jata.jga.id][188] = 0; // 12 -> 8
  jata.jga.cpop[jata.jga.id][189] = 0; // 12 -> 9
  jata.jga.cpop[jata.jga.id][190] = 0; // 12 -> 10
  jata.jga.cpop[jata.jga.id][191] = 0; // 12 -> 11
  jata.jga.cpop[jata.jga.id][192] = 0; // 12 -> 12
  jata.jga.cpop[jata.jga.id][193] = -5; // 12 -> 13
  jata.jga.cpop[jata.jga.id][194] = 0; // 12 -> 14
  jata.jga.cpop[jata.jga.id][195] = 0; // 13 -> 0
  jata.jga.cpop[jata.jga.id][196] = 0; // 13 -> 1
  jata.jga.cpop[jata.jga.id][197] = 0; // 13 -> 2
  jata.jga.cpop[jata.jga.id][198] = 0; // 13 -> 3
  jata.jga.cpop[jata.jga.id][199] = 0; // 13 -> 4
  jata.jga.cpop[jata.jga.id][200] = 0; // 13 -> 5
  jata.jga.cpop[jata.jga.id][201] = 0; // 13 -> 6
  jata.jga.cpop[jata.jga.id][202] = 0; // 13 -> 7
  jata.jga.cpop[jata.jga.id][203] = 0; // 13 -> 8
  jata.jga.cpop[jata.jga.id][204] = 0; // 13 -> 9
  jata.jga.cpop[jata.jga.id][205] = 0; // 13 -> 10
  jata.jga.cpop[jata.jga.id][206] = 0; // 13 -> 11
  jata.jga.cpop[jata.jga.id][207] = 5; // 13 -> 12
  jata.jga.cpop[jata.jga.id][208] = 0; // 13 -> 13
  jata.jga.cpop[jata.jga.id][209] = 0; // 13 -> 14
  jata.jga.cpop[jata.jga.id][210] = 0; // 14 -> 0
  jata.jga.cpop[jata.jga.id][211] = 0; // 14 -> 1
  jata.jga.cpop[jata.jga.id][212] = 0; // 14 -> 2
  jata.jga.cpop[jata.jga.id][213] = 0; // 14 -> 3
  jata.jga.cpop[jata.jga.id][214] = 0; // 14 -> 4
  jata.jga.cpop[jata.jga.id][215] = 0; // 14 -> 5
  jata.jga.cpop[jata.jga.id][216] = 0; // 14 -> 6
  jata.jga.cpop[jata.jga.id][217] = 0; // 14 -> 7
  jata.jga.cpop[jata.jga.id][218] = 0; // 14 -> 8
  jata.jga.cpop[jata.jga.id][219] = 0; // 14 -> 9
  jata.jga.cpop[jata.jga.id][220] = 0; // 14 -> 10
  jata.jga.cpop[jata.jga.id][221] = 0; // 14 -> 11
  jata.jga.cpop[jata.jga.id][222] = 0; // 14 -> 12
  jata.jga.cpop[jata.jga.id][223] = 3; // 14 -> 13
  jata.jga.cpop[jata.jga.id][224] = 0; // 14 -> 14
  jata.jga.cpop[jata.jga.id][225] = 0; // i0
  jata.jga.cpop[jata.jga.id][226] = 0; // i1
  jata.jga.cpop[jata.jga.id][227] = 0; // i2
  jata.jga.cpop[jata.jga.id][228] = 0; // i3
  jata.jga.cpop[jata.jga.id][229] = 0; // i4
  jata.jga.cpop[jata.jga.id][230] = 0; // i5
  jata.jga.cpop[jata.jga.id][231] = 0; // i6
  jata.jga.cpop[jata.jga.id][232] = 0; // i7
  jata.jga.cpop[jata.jga.id][233] = 0; // i8
  jata.jga.cpop[jata.jga.id][234] = 0; // i9
  jata.jga.cpop[jata.jga.id][235] = 0; // i10
  jata.jga.cpop[jata.jga.id][236] = 0; // i11
  jata.jga.cpop[jata.jga.id][237] = 1; // i12
  jata.jga.cpop[jata.jga.id][238] = 5; // i13
  jata.jga.cpop[jata.jga.id][239] = 1; // i14
}
*/
