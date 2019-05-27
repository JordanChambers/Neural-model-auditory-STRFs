struct Cells{
  double esyn[msyn];
  double isyn[msyn];
  double ewt[msyn];
  double iwt[msyn];
  double nstms[mapf*jT];
  int nstmspos;
  double v;
  double rmp;
  double vrs;
  double Rm;
  double tau;
  double thres;
  double grp;
  double rptau;
  double grpm;
  double kdr;
  double ea_gmax;
  double ea_tau;
  double ea_e;
  double ia_gmax;
  double ia_tau;
  double ia_e;
  int capdelay;
  int dfas;
  int eout[cellnumb];
  int edlay[cellnumb];
  double estn[cellnumb];
  int iout[cellnumb];
  int idlay[cellnumb];
  double istn[cellnumb];
};

struct Jnet{
  struct Cells cells[cellnumb+topdc];
  int cellinputs[cellnumb][17];
  double inscale[fnumb];
  double tau;
  double jconv;
  double instr;
  double tm;
  double g[4];
  int count;
};

struct Coch{
  int l[fnumb];
  double a[fnumb][flen];
  double b[fnumb][flen];
  double si[flen];
  int xstep;
};

struct Jfftw{
  //double in[250];
  //fftw_complex out[125];
  //fftw_complex cout[13];
  //fftw_plan jplan;
  int r[2];
  double s[250];
  double a[125];
  double b[125];
  int n;
};

struct Jga{
  int gen;
  int genmax;
  int id;
  int ss;
  int cpop[gapop][gavar];
  int tpop[gapop][cellnumb][2];
  int npop[gapop][gavar];
  double res[gapop];
  int pres[gavar];
  int ncount;
  double nres[gapop];
  int parents[gapc];
  double parentv[gapc];
  int gaec;
  //int gapc;
  int gacc;
  int gamc;
  int galb;
  int gaub;
  double scale;
  double shrink;
  int loadtarget;
  double target[sftorc][sttorc];
  int loadtargetvar;
  double targetvar[ftorc][ttorc];
  int cindex;
};

struct Torc{
  double stimprofile[ntorc][ftorc][ttorc];
  int raster[250];
  double aps[ttorc];
  int getsimdata;
  int ramp[ntorc][torcvar];
  double rfreq[ntorc][torcvar];
  int phase[ntorc][torcvar];
  int afreq[ntorc][torcvar];
  double W[torcvar];
  double Omega[torcvar+2][2];
  int ripple_count;
  int basep;
  int reps;
  int noct;
  int leng;
  int numcomp;
  int k[torcvar];
  int l[torcvar+2][2];
  double waveparams[2][torcvar][torcvar+2][2];
  double stimholder[ftorc][ttorc][2];
  double stimhl[ftorc][ttorc][2];
};

struct Jmpi{
  MPI_Status status;
  MPI_Request request;
  int ierr;
  int id;
  int procs;
  int argc;
  char argva[1];
  char ***argv;
  int r[3];
  double tres;
  int nproc[gapop];
};

struct Jata{
  int r[7];
  double d[5];
  double ss[jT*jFs];
  double sst[jT*jFs];
  int sscnt;
  double as[fnumb][jT*jFs];
  double fas[fnumb][jT*jFs+apdelay];
  double arcstrf[ftorc][ttorc];
  double avestrf[cellnumb][ftorc][ttorc];
  double tavestrf[cellnumb][ftorc][ttorc];
  double smoothstrf[cellnumb][sftorc][sttorc];
  double tsmoothstrf[cellnumb][sftorc][sttorc];
  double fstrf[ftorc][ttorc];
  int taps[cellnumb+topdc];
  int strfrep;
  int strfrepss;
  FILE *f;
  char jresname[50];
  char fname[50];
  char *cp;
  char strj[50];
  time_t tm;
  //double U;
  //double V;
  //int phase;
  struct Torc torc;
  struct Jnet jnet;
  struct Coch coch;
  struct Jfftw jfftw;
  struct Jga jga;
  struct Jmpi jmpi;
} jata = {};


