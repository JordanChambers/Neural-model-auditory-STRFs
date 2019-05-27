void wave2aud_load_coch(void)
{
  //printf("w2a loadcoch1\n");
  wave2aud_load_cocha();
  //printf("w2a loadcoch2\n");
  wave2aud_load_cochb();
}

void wave2aud_load_cocha(void)
{
  sprintf(&jata.fname[0], "./gtfb/jgtfba.txt");
  jata.f = fopen(&jata.fname[0], "r");
  jata.r[0] = 1;
  jata.sscnt = 0;
  while (jata.r[0] == 1){
    jata.r[1] = fscanf(jata.f, "%lf %lf %lf %lf %lf %lf %lf", &jata.coch.a[jata.sscnt][0], &jata.coch.a[jata.sscnt][1], &jata.coch.a[jata.sscnt][2], &jata.coch.a[jata.sscnt][3], &jata.coch.a[jata.sscnt][4], &jata.coch.a[jata.sscnt][5], &jata.coch.a[jata.sscnt][6]);
    //printf("reads is %d\n", jata.r[1]);
    //printf("%g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g\n", jata.coch.a[jata.sscnt][0], jata.coch.a[jata.sscnt][1], jata.coch.a[jata.sscnt][2], jata.coch.a[jata.sscnt][3], jata.coch.a[jata.sscnt][4], jata.coch.a[jata.sscnt][5], jata.coch.a[jata.sscnt][6], jata.coch.a[jata.sscnt][7], jata.coch.a[jata.sscnt][8], jata.coch.a[jata.sscnt][9], jata.coch.a[jata.sscnt][10], jata.coch.a[jata.sscnt][11], jata.coch.a[jata.sscnt][12], jata.coch.a[jata.sscnt][13], jata.coch.a[jata.sscnt][14], jata.coch.a[jata.sscnt][15], jata.coch.a[jata.sscnt][16], jata.coch.a[jata.sscnt][17], jata.coch.a[jata.sscnt][18], jata.coch.a[jata.sscnt][19], jata.coch.a[jata.sscnt][20], jata.coch.a[jata.sscnt][21], jata.coch.a[jata.sscnt][22], jata.coch.a[jata.sscnt][23], jata.coch.a[jata.sscnt][24]);
    if (jata.r[1] != 7){
      jata.r[0] = 0;
      break;
    }
    jata.sscnt++;
  }
  //printf("a => %d\n", jata.sscnt);
  /*    printf("a50 => %g %g %g %g %g %g %g %g %g\n", jata.coch.a[50][0], jata.coch.a[50][1], jata.coch.a[50][2], jata.coch.a[50][3], jata.coch.a[50][4], jata.coch.a[50][5], jata.coch.a[50][6], jata.coch.a[50][7], jata.coch.a[50][8]);
  printf("a100 => %g %g %g %g %g %g %g %g %g\n", jata.coch.a[100][0], jata.coch.a[100][1], jata.coch.a[100][2], jata.coch.a[100][3], jata.coch.a[100][4], jata.coch.a[100][5], jata.coch.a[100][6], jata.coch.a[100][7], jata.coch.a[100][8]);
  printf("a170 => %g %g %g %g %g %g %g %g %g\n", jata.coch.a[170][0], jata.coch.a[170][1], jata.coch.a[170][2], jata.coch.a[170][3], jata.coch.a[170][4], jata.coch.a[170][5], jata.coch.a[170][6], jata.coch.a[170][7], jata.coch.a[170][8]);*/
  fclose(jata.f);
}

void wave2aud_load_cochb(void)
{
  sprintf(&jata.fname[0], "./gtfb/jgtfbb.txt");
  jata.f = fopen(&jata.fname[0], "r");
  jata.r[0] = 1;
  jata.sscnt = 0;
  while (jata.r[0] == 1){
    jata.r[1] = fscanf(jata.f, "%lf %lf %lf %lf", &jata.coch.b[jata.sscnt][0], &jata.coch.b[jata.sscnt][1], &jata.coch.b[jata.sscnt][2], &jata.coch.b[jata.sscnt][3]);
    //printf("reads is %d\n", jata.r[1]);
    //printf("%g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g\n", jata.coch.b[jata.sscnt][0], jata.coch.b[jata.sscnt][1], jata.coch.b[jata.sscnt][2], jata.coch.b[jata.sscnt][3], jata.coch.b[jata.sscnt][4], jata.coch.b[jata.sscnt][5], jata.coch.b[jata.sscnt][6], jata.coch.b[jata.sscnt][7], jata.coch.b[jata.sscnt][8], jata.coch.b[jata.sscnt][9], jata.coch.b[jata.sscnt][10], jata.coch.b[jata.sscnt][11], jata.coch.b[jata.sscnt][12], jata.coch.b[jata.sscnt][13], jata.coch.b[jata.sscnt][14], jata.coch.b[jata.sscnt][15], jata.coch.b[jata.sscnt][16], jata.coch.b[jata.sscnt][17], jata.coch.b[jata.sscnt][18], jata.coch.b[jata.sscnt][19], jata.coch.b[jata.sscnt][20], jata.coch.b[jata.sscnt][21], jata.coch.b[jata.sscnt][22], jata.coch.b[jata.sscnt][23], jata.coch.b[jata.sscnt][24]);
    if (jata.r[1] != 4){
      jata.r[0] = 0;
      break;
    }
    jata.sscnt++;
  }
  //printf("b => %d\n", jata.sscnt);
  /*printf("b50 => %g %g %g %g %g %g %g %g %g\n", jata.coch.b[50][0], jata.coch.b[50][1], jata.coch.b[50][2], jata.coch.b[50][3], jata.coch.b[50][4], jata.coch.b[50][5], jata.coch.b[50][6], jata.coch.b[50][7], jata.coch.b[50][8]);
  printf("b100 => %g %g %g %g %g %g %g %g %g\n", jata.coch.b[100][0], jata.coch.b[100][1], jata.coch.b[100][2], jata.coch.b[100][3], jata.coch.b[100][4], jata.coch.b[100][5], jata.coch.b[100][6], jata.coch.b[100][7], jata.coch.b[100][8]);
  printf("b170 => %g %g %g %g %g %g %g %g %g\n", jata.coch.b[170][0], jata.coch.b[170][1], jata.coch.b[170][2], jata.coch.b[170][3], jata.coch.b[170][4], jata.coch.b[170][5], jata.coch.b[170][6], jata.coch.b[170][7], jata.coch.b[170][8]);*/
  fclose(jata.f);
}

void wave2aud_process(void)
{
  //printf("w2a process1\n");
  wave2aud_filter();
  //printf("w2a process2\n");
  wave2aud_sigmoid();
  //printf("w2a process3\n");
  wave2aud_lateral_inhibition();
  //printf("w2a process4\n");
  wave2aud_half_wave_rectifier();
  //printf("w2a process5\n");
  wave2aud_leaky_integration();
  //wave2aud_dump_fas();
}

void wave2aud_filter(void)
{
  for (jata.r[0] = 0; jata.r[0] < fnumb; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < flen; jata.r[1]++) jata.coch.si[jata.r[1]] = 0;
    for (jata.r[1] = 0; jata.r[1] < jT*jFs; jata.r[1]++){
      jata.as[jata.r[0]][jata.r[1]] = jata.coch.si[0] + (jata.coch.b[jata.r[0]][0]*jata.ss[jata.r[1]]);
      //printf("filter %d %d %g from %g %g %g\n", jata.r[0], jata.r[1], jata.as[jata.r[0]][jata.r[1]], jata.coch.si[0], jata.coch.b[jata.r[0]][0], jata.ss[jata.r[1]]);
      for (jata.r[2] = 0; jata.r[2] < 6; jata.r[2]++){
	jata.coch.si[jata.r[2]] = jata.coch.si[jata.r[2]+1] - (jata.coch.a[jata.r[0]][jata.r[2]+1]*jata.as[jata.r[0]][jata.r[1]]) + (jata.coch.b[jata.r[0]][jata.r[2]+1]*jata.ss[jata.r[1]]);
      }
      jata.coch.si[6] = (jata.coch.b[jata.r[0]][7]*jata.ss[jata.r[1]]) - (jata.coch.a[jata.r[0]][7]*jata.as[jata.r[0]][jata.r[1]]);
    }
  }
}

void wave2aud_sigmoid(void)
{
  for (jata.r[0] = 0; jata.r[0] < fnumb; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < jT*jFs; jata.r[1]++){
      //printf("as sig1 %d %d %g\n", jata.r[0], jata.r[1], jata.as[jata.r[0]][jata.r[1]]);      
      jata.as[jata.r[0]][jata.r[1]] = 1/(1+exp(-jata.as[jata.r[0]][jata.r[1]]/0.1));
      //printf("as sig2 %d %d %g\n", jata.r[0], jata.r[1], jata.as[jata.r[0]][jata.r[1]]);
    }
  }
}

void wave2aud_lateral_inhibition(void)
{
  for (jata.r[0] = 0; jata.r[0] < fnumb-1; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < jT*jFs; jata.r[1]++){
      jata.as[jata.r[0]][jata.r[1]] = jata.as[jata.r[0]][jata.r[1]] - jata.as[jata.r[0]+1][jata.r[1]];
      //printf("as lat %d %d %g\n", jata.r[0], jata.r[1], jata.as[jata.r[0]][jata.r[1]]);
    }
  }
}

void wave2aud_half_wave_rectifier(void)
{
  for (jata.r[0] = 0; jata.r[0] < fnumb; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < jT*jFs; jata.r[1]++){
      if (jata.as[jata.r[0]][jata.r[1]] < 0) jata.as[jata.r[0]][jata.r[1]] = 0;
      //printf("as ret %d %d %g\n", jata.r[0], jata.r[1], jata.as[jata.r[0]][jata.r[1]]);
    }
  }
}

void wave2aud_leaky_integration(void)
{
  jata.d[0] = 0;
  for (jata.r[0] = 0; jata.r[0] < fnumb; jata.r[0]++){
    jata.d[1] = 0;
    for (jata.r[1] = 0; jata.r[1] < flen; jata.r[1]++) jata.coch.si[jata.r[1]] = 0;
    for (jata.r[1] = 0; jata.r[1] < jT*jFs; jata.r[1]++){
      jata.fas[jata.r[0]][jata.r[1]] = jata.coch.si[0] + (jata.as[jata.r[0]][jata.r[1]]);
      jata.d[1] += jata.fas[jata.r[0]][jata.r[1]];
      jata.d[0] += jata.fas[jata.r[0]][jata.r[1]];
      jata.coch.si[0] = jata.coch.si[1] - (-0.9845*jata.as[jata.r[0]][jata.r[1]]) + (1*jata.as[jata.r[0]][jata.r[1]]);
      jata.coch.si[1] = (1*jata.as[jata.r[0]][jata.r[1]]) - (-0.9845*jata.fas[jata.r[0]][jata.r[1]]);
    }
    jata.d[1] /= jT*jFs;
    //printf("fas %d has a mean of %g\n", jata.r[0], jata.d[1]);
  }
  jata.d[1] = jata.d[0]/(fnumb*jT*jFs);
  //printf("total fas mean is %g\n", jata.d[1]);
  //srand(0);
  /*for (jata.r[0] = 0; jata.r[0] < fnumb; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < jT*jFs; jata.r[1]++){
      jata.d[0] = 0;
      for (jata.r[2] = 0; jata.r[2] < 25; jata.r[2]++){
	jata.d[0] += (double)rand()/RAND_MAX;
      }
      jata.d[0] -= 12.5;
      jata.d[0] /= sqrt(25.0/12.0);
      //jata.fas[jata.r[0]][jata.r[1]] = ((0.75+jata.d[0])*jata.fas[jata.r[0]][jata.r[1]]);
      //if (jata.fas[jata.r[0]][jata.r[1]] < 0) jata.fas[jata.r[0]][jata.r[1]] = 0;
      /*if (jata.phase == 0){
	jata.U = (rand() + 1.) / (RAND_MAX + 2.);
	jata.V = rand() / (RAND_MAX + 1.);
	jata.d[0] = sqrt(-2*log(jata.U))*sin(2*M_PI*jata.V);
      }
      else{
	jata.d[0] = sqrt(-2*log(jata.U))*cos(2*M_PI*jata.V);
      }
      jata.phase = 1 - jata.phase;
      //jata.fas[jata.r[0]][jata.r[1]] += (jata.d[0]*jata.d[1]);
      if (jata.fas[jata.r[0]][jata.r[1]] < 0) jata.fas[jata.r[0]][jata.r[1]] = 0;*/
  //}
//}
  /*for (jata.r[0] = 0; jata.r[0] < fnumb; jata.r[0]++){
    for (jata.r[1] = jT*jFs+apdelay-1; jata.r[1] >= apdelay; jata.r[1]--){
      jata.fas[jata.r[0]][jata.r[1]] = jata.fas[jata.r[0]][jata.r[1]-apdelay];
      //if (jata.r[0] >= 115){
	//if (jata.r[0] <= 122){
	  //jata.fas[jata.r[0]][jata.r[1]] = -jata.fas[jata.r[0]][jata.r[1]];
	//}
	//}
      //printf("fas li %d %d %g\n", jata.r[0], jata.r[1], jata.fas[jata.r[0]][jata.r[1]]);
    }
    for (jata.r[1] = 0; jata.r[1] < apdelay; jata.r[1]++){
      jata.fas[jata.r[0]][jata.r[1]] = 0;
    }
    }*/
}

void wave2aud_dump_fas(void)
{
  for (jata.r[0] = 0; jata.r[0] < fnumb; jata.r[0]++){
    sprintf(&jata.fname[0], "jfas%d.txt", jata.r[0]);
    jata.f = fopen(&jata.fname[0], "w");
    for (jata.r[1] = 0; jata.r[1] < jT*jFs; jata.r[1]++){
      fprintf(jata.f, "%g\n", jata.as[jata.r[0]][jata.r[1]]);
    }
    fclose(jata.f);
  }
}

/*
//==================================================== file = genpois.c =====
//=  Program to generate Poisson distributed random variables               =
//===========================================================================
//=  Notes: 1) Writes to a user specified output file                       =
//=         2) Generates user specified number of values                    =
//=-------------------------------------------------------------------------=
//= Example user input:                                                     =
//=                                                                         =
//=   ---------------------------------------- genpois.c -----              =
//=   -  Program to generate Poisson random variables        -              =
//=   --------------------------------------------------------              =
//=   Output file name ===================================> output.dat      =
//=   Random number seed =================================> 1               =
//=   Rate in customers per second =======================> 10.0            =
//=   Number of values to generate =======================> 5               =
//=   --------------------------------------------------------              =
//=   -  Generating samples to file                          -              =
//=   --------------------------------------------------------              =
//=   --------------------------------------------------------              =
//=   -  Done!                                                              =
//=   --------------------------------------------------------              =
//=-------------------------------------------------------------------------=
//= Example output file ("output.dat" for above):                           =
//=                                                                         =
//=   0                                                                     =
//=   9                                                                     =
//=   6                                                                     =
//=   10                                                                    =
//=   13                                                                    =
//=-------------------------------------------------------------------------=
//=  Build: bcc32 genpois.c                                                 =
//=-------------------------------------------------------------------------=
//=  Execute: genpois                                                       =
//=-------------------------------------------------------------------------=
//=  Author: Ken Christensen                                                =
//=          University of South Florida                                    =
//=          WWW: http://www.csee.usf.edu/~christen                         =
//=          Email: christen@csee.usf.edu                                   =
//=-------------------------------------------------------------------------=
//=  History: KJC (05/25/06) - Genesis (from genexp.c)                      =
//===========================================================================

//----- Include files -------------------------------------------------------
#include <stdio.h>              // Needed for printf()
#include <stdlib.h>             // Needed for exit() and ato*()
#include <math.h>               // Needed for log()

//----- Function prototypes -------------------------------------------------
int    poisson(double x);       // Returns a Poisson random variable
double expon(double x);         // Returns an exponential random variable
double rand_val(int seed);      // Jain's RNG

//===== Main program ========================================================
void main(void)
{
  FILE     *fp;                 // File pointer to output file
  char     file_name[256];      // Output file name string
  char     temp_string[256];    // Temporary string variable
  double   lambda;              // Mean rate
  int      pois_rv;             // Poisson random variable
  int      num_values;          // Number of values
  int      i;                   // Loop counter

  // Output banner
  printf("---------------------------------------- genpois.c ----- \n");
  printf("-  Program to generate Poisson random variables        - \n");
  printf("-------------------------------------------------------- \n");

  // Prompt for output filename and then create/open the file
  printf("Output file name ===================================> ");
  scanf("%s", file_name);
  fp = fopen(file_name, "w");
  if (fp == NULL)
  {
    printf("ERROR in creating output file (%s) \n", file_name);
    exit(1);
  }

  // Prompt for random number seed and then use it
  printf("Random number seed (greater than 0) ================> ");
  scanf("%s", temp_string);
  rand_val((int) atoi(temp_string));

  // Prompt for rate (lambda)
  printf("Rate in customers per second =======================> ");
  scanf("%s", temp_string);
  lambda = atof(temp_string);

  // Prompt for number of values to generate
  printf("Number of values to generate =======================> ");
  scanf("%s", temp_string);
  num_values = atoi(temp_string);

  //Output message and generate interarrival times
  printf("-------------------------------------------------------- \n");
  printf("-  Generating samples to file                          - \n");
  printf("-------------------------------------------------------- \n");

  // Generate and output exponential random variables
  for (i=0; i<num_values; i++)
  {
    pois_rv = poisson(1.0 / lambda);
    fprintf(fp, "%d \n", pois_rv);
  }

  //Output message and close the output file
  printf("-------------------------------------------------------- \n");
  printf("-  Done! \n");
  printf("-------------------------------------------------------- \n");
  fclose(fp);
}

//===========================================================================
//=  Function to generate Poisson distributed random variables              =
//=    - Input:  Mean value of distribution                                 =
//=    - Output: Returns with Poisson distributed random variable           =
//===========================================================================
int poisson(double x)
{
  int    poi_value;             // Computed Poisson value to be returned
  double t_sum;                 // Time sum value

  // Loop to generate Poisson values using exponential distribution
  poi_value = 0;
  t_sum = 0.0;
  while(1)
  {
    t_sum = t_sum + expon(x);
    if (t_sum >= 1.0) break;
    poi_value++;
  }

  return(poi_value);
}

//===========================================================================
//=  Function to generate exponentially distributed random variables        =
//=    - Input:  Mean value of distribution                                 =
//=    - Output: Returns with exponentially distributed random variable     =
//===========================================================================
double expon(double x)
{
  double z;                     // Uniform random number (0 < z < 1)
  double exp_value;             // Computed exponential value to be returned

  // Pull a uniform random number (0 < z < 1)
  do
  {
    z = rand_val(0);
  }
  while ((z == 0) || (z == 1));

  // Compute exponential random variable using inversion method
  exp_value = -x * log(z);

  return(exp_value);
}

//=========================================================================
//= Multiplicative LCG for generating uniform(0.0, 1.0) random numbers    =
//=   - x_n = 7^5*x_(n-1)mod(2^31 - 1)                                    =
//=   - With x seeded to 1 the 10000th x value should be 1043618065       =
//=   - From R. Jain, "The Art of Computer Systems Performance Analysis," =
//=     John Wiley & Sons, 1991. (Page 443, Figure 26.2)                  =
//=========================================================================
double rand_val(int seed)
{
  const long  a =      16807;  // Multiplier
  const long  m = 2147483647;  // Modulus
  const long  q =     127773;  // m div a
  const long  r =       2836;  // m mod a
  static long x;               // Random int value
  long        x_div_q;         // x divided by q
  long        x_mod_q;         // x modulo q
  long        x_new;           // New x value

  // Set the seed if argument is non-zero and then return zero
  if (seed > 0)
  {
    x = seed;
    return(0.0);
  }

  // RNG using integer arithmetic
  x_div_q = x / q;
  x_mod_q = x % q;
  x_new = (a * x_mod_q) - (r * x_div_q);
  if (x_new > 0)
    x = x_new;
  else
    x = x_new + m;

  // Return a random value between 0.0 and 1.0
  return((double) x / m);
}
*/


/*#include <stdlib.h>
#include <math.h>

#define NSUM 25

double gaussrand()
{
	double x = 0;
	int i;
	for(i = 0; i < NSUM; i++)
		x += (double)rand() / RAND_MAX;

	x -= NSUM / 2.0;
	x /= sqrt(NSUM / 12.0);

	return x;
}
(Don't overlook the sqrt(NSUM / 12.) correction, though it's easy to do so accidentally, especially when NSUM is 12.)
Use a method described by Abramowitz and Stegun:
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

double gaussrand()
{
	static double U, V;
	static int phase = 0;
	double Z;

	if(phase == 0) {
		U = (rand() + 1.) / (RAND_MAX + 2.);
		V = rand() / (RAND_MAX + 1.);
		Z = sqrt(-2 * log(U)) * sin(2 * PI * V);
	} else
		Z = sqrt(-2 * log(U)) * cos(2 * PI * V);

	phase = 1 - phase;

	return Z;
}
Use a method discussed in Knuth and due originally to Marsaglia:
#include <stdlib.h>
#include <math.h>

double gaussrand()
{
	static double V1, V2, S;
	static int phase = 0;
	double X;

	if(phase == 0) {
		do {
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
			} while(S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	} else
		X = V2 * sqrt(-2 * log(S) / S);

	phase = 1 - phase;

	return X;
}
These methods all generate numbers with mean 0 and standard deviation 1. (To adjust to some other distribution, multiply by the standard deviation and add the mean.) Method 1 is poor ``in the tails'' (especially if NSUM is small), but methods 2 and 3 perform quite well. See the references for more information.
*/
