void runjga(void)
{
}

void runjgajam(void)
{
  //printf("In runjgajam\n");
  //jam_syns();
  //srand(5);
  for (jata.r[0] = 0; jata.r[0] < cellnumb; jata.r[0]++){
    jata.taps[jata.r[0]] = 0;
    for (jata.r[1] = 0; jata.r[1] < ftorc; jata.r[1]++){
      for (jata.r[2] = 0; jata.r[2] < ttorc; jata.r[2]++){
	jata.avestrf[jata.r[0]][jata.r[1]][jata.r[2]] = 0;
	jata.tavestrf[jata.r[0]][jata.r[1]][jata.r[2]] = 0;
      }
    }
  }
  for (jata.strfrepss = 0; jata.strfrepss < 5; jata.strfrepss++){
    for (jata.strfrep = 1; jata.strfrep <= ntorc; jata.strfrep++){
      //printf("%d:::%d\n", jata.strfrep, jata.strfrepss);
      network_run();
      strf_rev_cor();
    }
    //strf_mean();
    //strf_normalise_maxabs();
  }
  strf_smooth();
  strf_zscore_smooth();
  //fftw_cleanup();
  //Normalise strfs
  //strf_normalise();
  //printf("Cost function\n");
  runjga_cost_smooth();
  /*jata.jga.res[0] = 0;
  for (jata.r[0] = 0; jata.r[0] < 225; jata.r[0]++){
    jata.jga.res[0] += jata.jga.cpop[0][jata.r[0]];
    }*/
}

void runjga_write_res(void)
{
  //printf("%d id in runjga_write_res for gen %d and id %d\n", jata.jmpi.id, jata.jga.gen, jata.jga.id);
  //sprintf(&jata.fname[0], "./results/wasabipas34.txt");
  //sprintf(&jata.fname[0], "./results/wasabiact37.txt");
  jata.f = fopen(&jata.jresname[0], "a");
  fprintf(jata.f, "%d %d %lf %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", jata.jga.gen, jata.jga.id, jata.jga.res[jata.jga.id], jata.jga.cpop[jata.jga.id][0], jata.jga.cpop[jata.jga.id][1], jata.jga.cpop[jata.jga.id][2], jata.jga.cpop[jata.jga.id][3], jata.jga.cpop[jata.jga.id][4], jata.jga.cpop[jata.jga.id][5], jata.jga.cpop[jata.jga.id][6], jata.jga.cpop[jata.jga.id][7], jata.jga.cpop[jata.jga.id][8], jata.jga.cpop[jata.jga.id][9], jata.jga.cpop[jata.jga.id][10], jata.jga.cpop[jata.jga.id][11], jata.jga.cpop[jata.jga.id][12], jata.jga.cpop[jata.jga.id][13], jata.jga.cpop[jata.jga.id][14], jata.jga.cpop[jata.jga.id][15], jata.jga.cpop[jata.jga.id][16], jata.jga.cpop[jata.jga.id][17], jata.jga.cpop[jata.jga.id][18], jata.jga.cpop[jata.jga.id][19], jata.jga.cpop[jata.jga.id][20], jata.jga.cpop[jata.jga.id][21], jata.jga.cpop[jata.jga.id][22], jata.jga.cpop[jata.jga.id][23], jata.jga.cpop[jata.jga.id][24], jata.jga.cpop[jata.jga.id][25], jata.jga.cpop[jata.jga.id][26], jata.jga.cpop[jata.jga.id][27], jata.jga.cpop[jata.jga.id][28], jata.jga.cpop[jata.jga.id][29], jata.jga.cpop[jata.jga.id][30], jata.jga.cpop[jata.jga.id][31], jata.jga.cpop[jata.jga.id][32], jata.jga.cpop[jata.jga.id][33], jata.jga.cpop[jata.jga.id][34], jata.jga.cpop[jata.jga.id][35], jata.jga.cpop[jata.jga.id][36], jata.jga.cpop[jata.jga.id][37], jata.jga.cpop[jata.jga.id][38], jata.jga.cpop[jata.jga.id][39], jata.jga.cpop[jata.jga.id][40], jata.jga.cpop[jata.jga.id][41], jata.jga.cpop[jata.jga.id][42], jata.jga.cpop[jata.jga.id][43], jata.jga.cpop[jata.jga.id][44], jata.jga.cpop[jata.jga.id][45], jata.jga.cpop[jata.jga.id][46], jata.jga.cpop[jata.jga.id][47], jata.jga.cpop[jata.jga.id][48], jata.jga.cpop[jata.jga.id][49], jata.jga.cpop[jata.jga.id][50], jata.jga.cpop[jata.jga.id][51], jata.jga.cpop[jata.jga.id][52], jata.jga.cpop[jata.jga.id][53], jata.jga.cpop[jata.jga.id][54], jata.jga.cpop[jata.jga.id][55], jata.jga.cpop[jata.jga.id][56], jata.jga.cpop[jata.jga.id][57], jata.jga.cpop[jata.jga.id][58], jata.jga.cpop[jata.jga.id][59], jata.jga.cpop[jata.jga.id][60], jata.jga.cpop[jata.jga.id][61], jata.jga.cpop[jata.jga.id][62], jata.jga.cpop[jata.jga.id][63], jata.jga.cpop[jata.jga.id][64], jata.jga.cpop[jata.jga.id][65], jata.jga.cpop[jata.jga.id][66], jata.jga.cpop[jata.jga.id][67], jata.jga.cpop[jata.jga.id][68], jata.jga.cpop[jata.jga.id][69], jata.jga.cpop[jata.jga.id][70], jata.jga.cpop[jata.jga.id][71], jata.jga.cpop[jata.jga.id][72], jata.jga.cpop[jata.jga.id][73], jata.jga.cpop[jata.jga.id][74], jata.jga.cpop[jata.jga.id][75], jata.jga.cpop[jata.jga.id][76], jata.jga.cpop[jata.jga.id][77], jata.jga.cpop[jata.jga.id][78], jata.jga.cpop[jata.jga.id][79], jata.jga.cpop[jata.jga.id][80], jata.jga.cpop[jata.jga.id][81], jata.jga.cpop[jata.jga.id][82], jata.jga.cpop[jata.jga.id][83], jata.jga.cpop[jata.jga.id][84], jata.jga.cpop[jata.jga.id][85], jata.jga.cpop[jata.jga.id][86], jata.jga.cpop[jata.jga.id][87], jata.jga.cpop[jata.jga.id][88], jata.jga.cpop[jata.jga.id][89], jata.jga.cpop[jata.jga.id][90], jata.jga.cpop[jata.jga.id][91], jata.jga.cpop[jata.jga.id][92], jata.jga.cpop[jata.jga.id][93], jata.jga.cpop[jata.jga.id][94], jata.jga.cpop[jata.jga.id][95], jata.jga.cpop[jata.jga.id][96], jata.jga.cpop[jata.jga.id][97], jata.jga.cpop[jata.jga.id][98], jata.jga.cpop[jata.jga.id][99], jata.jga.cpop[jata.jga.id][100], jata.jga.cpop[jata.jga.id][101], jata.jga.cpop[jata.jga.id][102], jata.jga.cpop[jata.jga.id][103], jata.jga.cpop[jata.jga.id][104], jata.jga.cpop[jata.jga.id][105], jata.jga.cpop[jata.jga.id][106], jata.jga.cpop[jata.jga.id][107], jata.jga.cpop[jata.jga.id][108], jata.jga.cpop[jata.jga.id][109], jata.jga.cpop[jata.jga.id][110], jata.jga.cpop[jata.jga.id][111], jata.jga.cpop[jata.jga.id][112], jata.jga.cpop[jata.jga.id][113], jata.jga.cpop[jata.jga.id][114], jata.jga.cpop[jata.jga.id][115], jata.jga.cpop[jata.jga.id][116], jata.jga.cpop[jata.jga.id][117], jata.jga.cpop[jata.jga.id][118], jata.jga.cpop[jata.jga.id][119], jata.jga.cpop[jata.jga.id][120], jata.jga.cpop[jata.jga.id][121], jata.jga.cpop[jata.jga.id][122], jata.jga.cpop[jata.jga.id][123], jata.jga.cpop[jata.jga.id][124], jata.jga.cpop[jata.jga.id][125], jata.jga.cpop[jata.jga.id][126], jata.jga.cpop[jata.jga.id][127], jata.jga.cpop[jata.jga.id][128], jata.jga.cpop[jata.jga.id][129], jata.jga.cpop[jata.jga.id][130], jata.jga.cpop[jata.jga.id][131], jata.jga.cpop[jata.jga.id][132], jata.jga.cpop[jata.jga.id][133], jata.jga.cpop[jata.jga.id][134], jata.jga.cpop[jata.jga.id][135], jata.jga.cpop[jata.jga.id][136], jata.jga.cpop[jata.jga.id][137], jata.jga.cpop[jata.jga.id][138], jata.jga.cpop[jata.jga.id][139], jata.jga.cpop[jata.jga.id][140], jata.jga.cpop[jata.jga.id][141], jata.jga.cpop[jata.jga.id][142], jata.jga.cpop[jata.jga.id][143], jata.jga.cpop[jata.jga.id][144], jata.jga.cpop[jata.jga.id][145], jata.jga.cpop[jata.jga.id][146], jata.jga.cpop[jata.jga.id][147], jata.jga.cpop[jata.jga.id][148], jata.jga.cpop[jata.jga.id][149], jata.jga.cpop[jata.jga.id][150], jata.jga.cpop[jata.jga.id][151], jata.jga.cpop[jata.jga.id][152], jata.jga.cpop[jata.jga.id][153], jata.jga.cpop[jata.jga.id][154], jata.jga.cpop[jata.jga.id][155], jata.jga.cpop[jata.jga.id][156], jata.jga.cpop[jata.jga.id][157], jata.jga.cpop[jata.jga.id][158], jata.jga.cpop[jata.jga.id][159], jata.jga.cpop[jata.jga.id][160], jata.jga.cpop[jata.jga.id][161], jata.jga.cpop[jata.jga.id][162], jata.jga.cpop[jata.jga.id][163], jata.jga.cpop[jata.jga.id][164], jata.jga.cpop[jata.jga.id][165], jata.jga.cpop[jata.jga.id][166], jata.jga.cpop[jata.jga.id][167], jata.jga.cpop[jata.jga.id][168], jata.jga.cpop[jata.jga.id][169], jata.jga.cpop[jata.jga.id][170], jata.jga.cpop[jata.jga.id][171], jata.jga.cpop[jata.jga.id][172], jata.jga.cpop[jata.jga.id][173], jata.jga.cpop[jata.jga.id][174], jata.jga.cpop[jata.jga.id][175], jata.jga.cpop[jata.jga.id][176], jata.jga.cpop[jata.jga.id][177], jata.jga.cpop[jata.jga.id][178], jata.jga.cpop[jata.jga.id][179], jata.jga.cpop[jata.jga.id][180], jata.jga.cpop[jata.jga.id][181], jata.jga.cpop[jata.jga.id][182], jata.jga.cpop[jata.jga.id][183], jata.jga.cpop[jata.jga.id][184], jata.jga.cpop[jata.jga.id][185], jata.jga.cpop[jata.jga.id][186], jata.jga.cpop[jata.jga.id][187], jata.jga.cpop[jata.jga.id][188], jata.jga.cpop[jata.jga.id][189], jata.jga.cpop[jata.jga.id][190], jata.jga.cpop[jata.jga.id][191], jata.jga.cpop[jata.jga.id][192], jata.jga.cpop[jata.jga.id][193], jata.jga.cpop[jata.jga.id][194], jata.jga.cpop[jata.jga.id][195], jata.jga.cpop[jata.jga.id][196], jata.jga.cpop[jata.jga.id][197], jata.jga.cpop[jata.jga.id][198], jata.jga.cpop[jata.jga.id][199], jata.jga.cpop[jata.jga.id][200], jata.jga.cpop[jata.jga.id][201], jata.jga.cpop[jata.jga.id][202], jata.jga.cpop[jata.jga.id][203], jata.jga.cpop[jata.jga.id][204], jata.jga.cpop[jata.jga.id][205], jata.jga.cpop[jata.jga.id][206], jata.jga.cpop[jata.jga.id][207], jata.jga.cpop[jata.jga.id][208], jata.jga.cpop[jata.jga.id][209], jata.jga.cpop[jata.jga.id][210], jata.jga.cpop[jata.jga.id][211], jata.jga.cpop[jata.jga.id][212], jata.jga.cpop[jata.jga.id][213], jata.jga.cpop[jata.jga.id][214], jata.jga.cpop[jata.jga.id][215], jata.jga.cpop[jata.jga.id][216], jata.jga.cpop[jata.jga.id][217], jata.jga.cpop[jata.jga.id][218], jata.jga.cpop[jata.jga.id][219], jata.jga.cpop[jata.jga.id][220], jata.jga.cpop[jata.jga.id][221], jata.jga.cpop[jata.jga.id][222], jata.jga.cpop[jata.jga.id][223], jata.jga.cpop[jata.jga.id][224], jata.jga.cpop[jata.jga.id][225], jata.jga.cpop[jata.jga.id][226], jata.jga.cpop[jata.jga.id][227], jata.jga.cpop[jata.jga.id][228], jata.jga.cpop[jata.jga.id][229], jata.jga.cpop[jata.jga.id][230], jata.jga.cpop[jata.jga.id][231], jata.jga.cpop[jata.jga.id][232], jata.jga.cpop[jata.jga.id][233], jata.jga.cpop[jata.jga.id][234], jata.jga.cpop[jata.jga.id][235], jata.jga.cpop[jata.jga.id][236], jata.jga.cpop[jata.jga.id][237], jata.jga.cpop[jata.jga.id][238], jata.jga.cpop[jata.jga.id][239], jata.jga.cpop[jata.jga.id][240], jata.jga.cpop[jata.jga.id][241], jata.jga.cpop[jata.jga.id][242], jata.jga.cpop[jata.jga.id][243], jata.jga.cpop[jata.jga.id][244], jata.jga.cpop[jata.jga.id][245], jata.jga.cpop[jata.jga.id][246], jata.jga.cpop[jata.jga.id][247], jata.jga.cpop[jata.jga.id][248], jata.jga.cpop[jata.jga.id][249], jata.jga.cpop[jata.jga.id][250], jata.jga.cpop[jata.jga.id][251], jata.jga.cpop[jata.jga.id][252], jata.jga.cpop[jata.jga.id][253], jata.jga.cpop[jata.jga.id][254]);
  fclose(jata.f);
  //printf("%d id leaving runjga_write_res for gen %d and id %d\n", jata.jmpi.id, jata.jga.gen, jata.jga.id);
}

void runjga_check_res(void)
{
  //sprintf(&jata.fname[0], "./results/wasabipas34.txt");
  //sprintf(&jata.fname[0], "./results/wasabiact37.txt");
  //jata.f = fopen(&jata.fname[0], "r");
  jata.f = fopen(&jata.jresname[0], "a");
  if (jata.f == NULL){
    printf("Could not open results file\n");
    return;
  }
  //printf("Checking previous results\n");
  jata.r[0] = 1;
  while (jata.r[0] == 1){
    jata.r[1] = fscanf(jata.f, "%d %d %lf %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &jata.r[2], &jata.r[3], &jata.d[0], &jata.jga.pres[0], &jata.jga.pres[1], &jata.jga.pres[2], &jata.jga.pres[3], &jata.jga.pres[4], &jata.jga.pres[5], &jata.jga.pres[6], &jata.jga.pres[7], &jata.jga.pres[8], &jata.jga.pres[9], &jata.jga.pres[10], &jata.jga.pres[11], &jata.jga.pres[12], &jata.jga.pres[13], &jata.jga.pres[14], &jata.jga.pres[15], &jata.jga.pres[16], &jata.jga.pres[17], &jata.jga.pres[18], &jata.jga.pres[19], &jata.jga.pres[20], &jata.jga.pres[21], &jata.jga.pres[22], &jata.jga.pres[23], &jata.jga.pres[24], &jata.jga.pres[25], &jata.jga.pres[26], &jata.jga.pres[27], &jata.jga.pres[28], &jata.jga.pres[29], &jata.jga.pres[30], &jata.jga.pres[31], &jata.jga.pres[32], &jata.jga.pres[33], &jata.jga.pres[34], &jata.jga.pres[35], &jata.jga.pres[36], &jata.jga.pres[37], &jata.jga.pres[38], &jata.jga.pres[39], &jata.jga.pres[40], &jata.jga.pres[41], &jata.jga.pres[42], &jata.jga.pres[43], &jata.jga.pres[44], &jata.jga.pres[45], &jata.jga.pres[46], &jata.jga.pres[47], &jata.jga.pres[48], &jata.jga.pres[49], &jata.jga.pres[50], &jata.jga.pres[51], &jata.jga.pres[52], &jata.jga.pres[53], &jata.jga.pres[54], &jata.jga.pres[55], &jata.jga.pres[56], &jata.jga.pres[57], &jata.jga.pres[58], &jata.jga.pres[59], &jata.jga.pres[60], &jata.jga.pres[61], &jata.jga.pres[62], &jata.jga.pres[63], &jata.jga.pres[64], &jata.jga.pres[65], &jata.jga.pres[66], &jata.jga.pres[67], &jata.jga.pres[68], &jata.jga.pres[69], &jata.jga.pres[70], &jata.jga.pres[71], &jata.jga.pres[72], &jata.jga.pres[73], &jata.jga.pres[74], &jata.jga.pres[75], &jata.jga.pres[76], &jata.jga.pres[77], &jata.jga.pres[78], &jata.jga.pres[79], &jata.jga.pres[80], &jata.jga.pres[81], &jata.jga.pres[82], &jata.jga.pres[83], &jata.jga.pres[84], &jata.jga.pres[85], &jata.jga.pres[86], &jata.jga.pres[87], &jata.jga.pres[88], &jata.jga.pres[89], &jata.jga.pres[90], &jata.jga.pres[91], &jata.jga.pres[92], &jata.jga.pres[93], &jata.jga.pres[94], &jata.jga.pres[95], &jata.jga.pres[96], &jata.jga.pres[97], &jata.jga.pres[98], &jata.jga.pres[99], &jata.jga.pres[100], &jata.jga.pres[101], &jata.jga.pres[102], &jata.jga.pres[103], &jata.jga.pres[104], &jata.jga.pres[105], &jata.jga.pres[106], &jata.jga.pres[107], &jata.jga.pres[108], &jata.jga.pres[109], &jata.jga.pres[110], &jata.jga.pres[111], &jata.jga.pres[112], &jata.jga.pres[113], &jata.jga.pres[114], &jata.jga.pres[115], &jata.jga.pres[116], &jata.jga.pres[117], &jata.jga.pres[118], &jata.jga.pres[119], &jata.jga.pres[120], &jata.jga.pres[121], &jata.jga.pres[122], &jata.jga.pres[123], &jata.jga.pres[124], &jata.jga.pres[125], &jata.jga.pres[126], &jata.jga.pres[127], &jata.jga.pres[128], &jata.jga.pres[129], &jata.jga.pres[130], &jata.jga.pres[131], &jata.jga.pres[132], &jata.jga.pres[133], &jata.jga.pres[134], &jata.jga.pres[135], &jata.jga.pres[136], &jata.jga.pres[137], &jata.jga.pres[138], &jata.jga.pres[139], &jata.jga.pres[140], &jata.jga.pres[141], &jata.jga.pres[142], &jata.jga.pres[143], &jata.jga.pres[144], &jata.jga.pres[145], &jata.jga.pres[146], &jata.jga.pres[147], &jata.jga.pres[148], &jata.jga.pres[149], &jata.jga.pres[150], &jata.jga.pres[151], &jata.jga.pres[152], &jata.jga.pres[153], &jata.jga.pres[154], &jata.jga.pres[155], &jata.jga.pres[156], &jata.jga.pres[157], &jata.jga.pres[158], &jata.jga.pres[159], &jata.jga.pres[160], &jata.jga.pres[161], &jata.jga.pres[162], &jata.jga.pres[163], &jata.jga.pres[164], &jata.jga.pres[165], &jata.jga.pres[166], &jata.jga.pres[167], &jata.jga.pres[168], &jata.jga.pres[169], &jata.jga.pres[170], &jata.jga.pres[171], &jata.jga.pres[172], &jata.jga.pres[173], &jata.jga.pres[174], &jata.jga.pres[175], &jata.jga.pres[176], &jata.jga.pres[177], &jata.jga.pres[178], &jata.jga.pres[179], &jata.jga.pres[180], &jata.jga.pres[181], &jata.jga.pres[182], &jata.jga.pres[183], &jata.jga.pres[184], &jata.jga.pres[185], &jata.jga.pres[186], &jata.jga.pres[187], &jata.jga.pres[188], &jata.jga.pres[189], &jata.jga.pres[190], &jata.jga.pres[191], &jata.jga.pres[192], &jata.jga.pres[193], &jata.jga.pres[194], &jata.jga.pres[195], &jata.jga.pres[196], &jata.jga.pres[197], &jata.jga.pres[198], &jata.jga.pres[199], &jata.jga.pres[200], &jata.jga.pres[201], &jata.jga.pres[202], &jata.jga.pres[203], &jata.jga.pres[204], &jata.jga.pres[205], &jata.jga.pres[206], &jata.jga.pres[207], &jata.jga.pres[208], &jata.jga.pres[209], &jata.jga.pres[210], &jata.jga.pres[211], &jata.jga.pres[212], &jata.jga.pres[213], &jata.jga.pres[214], &jata.jga.pres[215], &jata.jga.pres[216], &jata.jga.pres[217], &jata.jga.pres[218], &jata.jga.pres[219], &jata.jga.pres[220], &jata.jga.pres[221], &jata.jga.pres[222], &jata.jga.pres[223], &jata.jga.pres[224], &jata.jga.pres[225], &jata.jga.pres[226], &jata.jga.pres[227], &jata.jga.pres[228], &jata.jga.pres[229], &jata.jga.pres[230], &jata.jga.pres[231], &jata.jga.pres[232], &jata.jga.pres[233], &jata.jga.pres[234], &jata.jga.pres[235], &jata.jga.pres[236], &jata.jga.pres[237], &jata.jga.pres[238], &jata.jga.pres[239], &jata.jga.pres[240], &jata.jga.pres[241], &jata.jga.pres[242], &jata.jga.pres[243], &jata.jga.pres[244], &jata.jga.pres[245], &jata.jga.pres[246], &jata.jga.pres[247], &jata.jga.pres[248], &jata.jga.pres[249], &jata.jga.pres[250], &jata.jga.pres[251], &jata.jga.pres[252], &jata.jga.pres[253], &jata.jga.pres[254]);
    if (jata.r[1] != 3 + gavar){
      jata.r[0] = 0;
      break;
    }
    jata.r[4] = 1;
    for (jata.r[5] = 0; jata.r[5] < gavar; jata.r[5]++){
      if (jata.jga.cpop[jata.jga.id][jata.r[5]] != jata.jga.pres[jata.r[5]]){
	//printf("%d has different values of %d and %d\n", jata.r[5], jata.jga.cpop[jata.jga.id][jata.r[5]], jata.jga.pres[jata.r[5]]);
	jata.r[4] = 0;
	break;
      }
    }
    //printf("comparing to %d, %d gives %d\n", jata.r[2], jata.r[3], jata.r[4]);
    if (jata.r[4] == 1){
      jata.jga.res[jata.jga.id] = jata.d[0];
      //printf("Previous result found from generation %d number %d, so loaded value %g\n", jata.r[2], jata.r[3], jata.jga.res[jata.jga.id]);
      jata.r[0] = 0;
      break;
    }
  }
  fclose(jata.f);
  //exit(1);
}

void runjga_check_res_npop(void)
{
  //sprintf(&jata.fname[0], "./results/wasabipas34.txt");
  //sprintf(&jata.fname[0], "./results/wasabiact37.txt");
  //jata.f = fopen(&jata.fname[0], "r");
  jata.f = fopen(&jata.jresname[0], "a");
  if (jata.f == NULL){
    printf("Could not open results file\n");
    return;
  }
  //printf("Checking previous results\n");
  jata.r[0] = 1;
  while (jata.r[0] == 1){
    jata.r[1] = fscanf(jata.f, "%d %d %lf %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &jata.r[2], &jata.r[3], &jata.d[0], &jata.jga.pres[0], &jata.jga.pres[1], &jata.jga.pres[2], &jata.jga.pres[3], &jata.jga.pres[4], &jata.jga.pres[5], &jata.jga.pres[6], &jata.jga.pres[7], &jata.jga.pres[8], &jata.jga.pres[9], &jata.jga.pres[10], &jata.jga.pres[11], &jata.jga.pres[12], &jata.jga.pres[13], &jata.jga.pres[14], &jata.jga.pres[15], &jata.jga.pres[16], &jata.jga.pres[17], &jata.jga.pres[18], &jata.jga.pres[19], &jata.jga.pres[20], &jata.jga.pres[21], &jata.jga.pres[22], &jata.jga.pres[23], &jata.jga.pres[24], &jata.jga.pres[25], &jata.jga.pres[26], &jata.jga.pres[27], &jata.jga.pres[28], &jata.jga.pres[29], &jata.jga.pres[30], &jata.jga.pres[31], &jata.jga.pres[32], &jata.jga.pres[33], &jata.jga.pres[34], &jata.jga.pres[35], &jata.jga.pres[36], &jata.jga.pres[37], &jata.jga.pres[38], &jata.jga.pres[39], &jata.jga.pres[40], &jata.jga.pres[41], &jata.jga.pres[42], &jata.jga.pres[43], &jata.jga.pres[44], &jata.jga.pres[45], &jata.jga.pres[46], &jata.jga.pres[47], &jata.jga.pres[48], &jata.jga.pres[49], &jata.jga.pres[50], &jata.jga.pres[51], &jata.jga.pres[52], &jata.jga.pres[53], &jata.jga.pres[54], &jata.jga.pres[55], &jata.jga.pres[56], &jata.jga.pres[57], &jata.jga.pres[58], &jata.jga.pres[59], &jata.jga.pres[60], &jata.jga.pres[61], &jata.jga.pres[62], &jata.jga.pres[63], &jata.jga.pres[64], &jata.jga.pres[65], &jata.jga.pres[66], &jata.jga.pres[67], &jata.jga.pres[68], &jata.jga.pres[69], &jata.jga.pres[70], &jata.jga.pres[71], &jata.jga.pres[72], &jata.jga.pres[73], &jata.jga.pres[74], &jata.jga.pres[75], &jata.jga.pres[76], &jata.jga.pres[77], &jata.jga.pres[78], &jata.jga.pres[79], &jata.jga.pres[80], &jata.jga.pres[81], &jata.jga.pres[82], &jata.jga.pres[83], &jata.jga.pres[84], &jata.jga.pres[85], &jata.jga.pres[86], &jata.jga.pres[87], &jata.jga.pres[88], &jata.jga.pres[89], &jata.jga.pres[90], &jata.jga.pres[91], &jata.jga.pres[92], &jata.jga.pres[93], &jata.jga.pres[94], &jata.jga.pres[95], &jata.jga.pres[96], &jata.jga.pres[97], &jata.jga.pres[98], &jata.jga.pres[99], &jata.jga.pres[100], &jata.jga.pres[101], &jata.jga.pres[102], &jata.jga.pres[103], &jata.jga.pres[104], &jata.jga.pres[105], &jata.jga.pres[106], &jata.jga.pres[107], &jata.jga.pres[108], &jata.jga.pres[109], &jata.jga.pres[110], &jata.jga.pres[111], &jata.jga.pres[112], &jata.jga.pres[113], &jata.jga.pres[114], &jata.jga.pres[115], &jata.jga.pres[116], &jata.jga.pres[117], &jata.jga.pres[118], &jata.jga.pres[119], &jata.jga.pres[120], &jata.jga.pres[121], &jata.jga.pres[122], &jata.jga.pres[123], &jata.jga.pres[124], &jata.jga.pres[125], &jata.jga.pres[126], &jata.jga.pres[127], &jata.jga.pres[128], &jata.jga.pres[129], &jata.jga.pres[130], &jata.jga.pres[131], &jata.jga.pres[132], &jata.jga.pres[133], &jata.jga.pres[134], &jata.jga.pres[135], &jata.jga.pres[136], &jata.jga.pres[137], &jata.jga.pres[138], &jata.jga.pres[139], &jata.jga.pres[140], &jata.jga.pres[141], &jata.jga.pres[142], &jata.jga.pres[143], &jata.jga.pres[144], &jata.jga.pres[145], &jata.jga.pres[146], &jata.jga.pres[147], &jata.jga.pres[148], &jata.jga.pres[149], &jata.jga.pres[150], &jata.jga.pres[151], &jata.jga.pres[152], &jata.jga.pres[153], &jata.jga.pres[154], &jata.jga.pres[155], &jata.jga.pres[156], &jata.jga.pres[157], &jata.jga.pres[158], &jata.jga.pres[159], &jata.jga.pres[160], &jata.jga.pres[161], &jata.jga.pres[162], &jata.jga.pres[163], &jata.jga.pres[164], &jata.jga.pres[165], &jata.jga.pres[166], &jata.jga.pres[167], &jata.jga.pres[168], &jata.jga.pres[169], &jata.jga.pres[170], &jata.jga.pres[171], &jata.jga.pres[172], &jata.jga.pres[173], &jata.jga.pres[174], &jata.jga.pres[175], &jata.jga.pres[176], &jata.jga.pres[177], &jata.jga.pres[178], &jata.jga.pres[179], &jata.jga.pres[180], &jata.jga.pres[181], &jata.jga.pres[182], &jata.jga.pres[183], &jata.jga.pres[184], &jata.jga.pres[185], &jata.jga.pres[186], &jata.jga.pres[187], &jata.jga.pres[188], &jata.jga.pres[189], &jata.jga.pres[190], &jata.jga.pres[191], &jata.jga.pres[192], &jata.jga.pres[193], &jata.jga.pres[194], &jata.jga.pres[195], &jata.jga.pres[196], &jata.jga.pres[197], &jata.jga.pres[198], &jata.jga.pres[199], &jata.jga.pres[200], &jata.jga.pres[201], &jata.jga.pres[202], &jata.jga.pres[203], &jata.jga.pres[204], &jata.jga.pres[205], &jata.jga.pres[206], &jata.jga.pres[207], &jata.jga.pres[208], &jata.jga.pres[209], &jata.jga.pres[210], &jata.jga.pres[211], &jata.jga.pres[212], &jata.jga.pres[213], &jata.jga.pres[214], &jata.jga.pres[215], &jata.jga.pres[216], &jata.jga.pres[217], &jata.jga.pres[218], &jata.jga.pres[219], &jata.jga.pres[220], &jata.jga.pres[221], &jata.jga.pres[222], &jata.jga.pres[223], &jata.jga.pres[224], &jata.jga.pres[225], &jata.jga.pres[226], &jata.jga.pres[227], &jata.jga.pres[228], &jata.jga.pres[229], &jata.jga.pres[230], &jata.jga.pres[231], &jata.jga.pres[232], &jata.jga.pres[233], &jata.jga.pres[234], &jata.jga.pres[235], &jata.jga.pres[236], &jata.jga.pres[237], &jata.jga.pres[238], &jata.jga.pres[239], &jata.jga.pres[240], &jata.jga.pres[241], &jata.jga.pres[242], &jata.jga.pres[243], &jata.jga.pres[244], &jata.jga.pres[245], &jata.jga.pres[246], &jata.jga.pres[247], &jata.jga.pres[248], &jata.jga.pres[249], &jata.jga.pres[250], &jata.jga.pres[251], &jata.jga.pres[252], &jata.jga.pres[253], &jata.jga.pres[254]);
    if (jata.r[1] != 3 + gavar){
      jata.r[0] = 0;
      break;
    }
    for (jata.r[6] = 0; jata.r[6] < gapop; jata.r[6]++){
      jata.r[4] = 1;
      for (jata.r[5] = 0; jata.r[5] < gavar; jata.r[5]++){
	if (jata.jga.cpop[jata.r[6]][jata.r[5]] != jata.jga.pres[jata.r[5]]){
	  //printf("%d has different values of %d and %d\n", jata.r[5], jata.jga.cpop[jata.jga.id][jata.r[5]], jata.jga.pres[jata.r[5]]);
	  jata.r[4] = 0;
	  break;
	}
      }
      //printf("comparing to %d, %d gives %d\n", jata.r[2], jata.r[3], jata.r[4]);
      if (jata.r[4] == 1){
	jata.jga.res[jata.r[6]] = jata.d[0];
	//printf("Previous result found from generation %d number %d, so loaded value %g\n", jata.r[2], jata.r[3], jata.jga.res[jata.jga.id]);
	//jata.r[0] = 0;
	//break;
      }
    }
  }
  fclose(jata.f);
  //exit(1);
}

void runjga_create_ipopulation(void)
{
  jata.r[2] = jata.jga.gaub - jata.jga.galb + 1;
  for (jata.r[0] = 0; jata.r[0] < gapop; jata.r[0]++){
    printf("%d ipop has: ", jata.r[0]);
    for (jata.r[1] = 0; jata.r[1] < gavar; jata.r[1]++){
      jata.d[0] = rand()/((double) RAND_MAX+1.0);
      jata.jga.cpop[jata.r[0]][jata.r[1]] = jata.jga.galb + jata.r[2]*jata.d[0];
      /*if (jata.r[1] == 14) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 29) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 44) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 59) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 74) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 89) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 104) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 119) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 134) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 149) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 164) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 179) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 209) jata.jga.cpop[jata.r[0]][jata.r[1]] = 0;
      if (jata.r[1] == 194) jata.jga.cpop[jata.r[0]][jata.r[1]] = -1;
      if (jata.r[1] == 237) jata.jga.cpop[jata.r[0]][jata.r[1]] = 1;
      if (jata.r[1] == 239) jata.jga.cpop[jata.r[0]][jata.r[1]] = 1;*/
      printf(" %d", jata.jga.cpop[jata.r[0]][jata.r[1]]);
    }
    printf("\n");
    jata.jga.res[jata.r[0]] = -101;
  }
}

void runjga_create_spopulation(void)
{
  for (jata.r[0] = 0; jata.r[0] < gapop; jata.r[0]++){
    jata.jga.id = jata.r[0];
    //jam_syns();
    jata.jga.cpop[jata.r[0]][jata.r[0]]++;
    //jata.jga.cpop[jata.r[0]][jata.r[0]]--;
    jata.jga.res[jata.r[0]] = -101;
  }
}

void runjga_create_npopulation(void)
{
  /*printf("\n\ncpop results:\n");
  for (jata.r[0] = 0; jata.r[0] < gapop; jata.r[0]++){
    printf("%d = %g\n", jata.r[0], jata.jga.res[jata.r[0]]);
    }*/
  //printf("In create npopulation\n");
  jata.jga.ncount = 0;
  //printf("rcn going to get elite\n");
  runjga_get_elite();
  //printf("rcn going to get parents\n");
  runjga_get_parents();
  //printf("rcn going to get crossover\n");
  runjga_crossover();
  //printf("rcn going to get mutate\n");
  runjga_mutate();
  //printf("rcn finished mutate\n");
  runjga_crossover();
  //printf("rcn going to get mutate\n");
  runjga_mutate();
  //printf("rcn finished mutate\n");
  for (jata.r[0] = 0; jata.r[0] < gapop; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < gavar; jata.r[1]++){
      jata.jga.cpop[jata.r[0]][jata.r[1]] = jata.jga.npop[jata.r[0]][jata.r[1]];
    }
    jata.jga.res[jata.r[0]] = -101;
  }
  runjga_check_res_npop();
}

void runjga_get_elite(void)
{
  //printf("Elite values are:\n");
  for (jata.r[0] = 0; jata.r[0] < gapop; jata.r[0]++){
    if (jata.jga.res[jata.r[0]] < -1) continue;
    jata.r[1] = 0;
    for (jata.r[2] = 0; jata.r[2] < gapop; jata.r[2]++){
      if (jata.jga.res[jata.r[2]] < -1) continue;
      if (jata.jga.res[jata.r[0]] > jata.jga.res[jata.r[2]]) jata.r[1]++;
    }
    if (jata.r[1] < jata.jga.gaec){
      //printf("%d (from %d)\n", jata.r[0], jata.r[1]);
      printf("%d; elite; %d (from %d);", jata.jga.gen, jata.r[1], jata.r[0]); 
      for (jata.r[2] = 0; jata.r[2] < gavar; jata.r[2]++){
	jata.jga.npop[jata.jga.ncount][jata.r[2]] = jata.jga.cpop[jata.r[0]][jata.r[2]];
	printf(" %d", jata.jga.cpop[jata.r[0]][jata.r[2]]);
      }
      printf("\n");
      jata.jga.ncount++;
    }
  }
}

void runjga_get_parents(void)
{
  for (jata.r[0] = 0; jata.r[0] < gapc; jata.r[0]++) jata.jga.parentv[jata.r[0]] = 1000000.0;
  for (jata.r[0] = 0; jata.r[0] < gapop; jata.r[0]++){
    if (jata.jga.res[jata.r[0]] < -1) continue;
    for (jata.r[1] = 0; jata.r[1] < gapc; jata.r[1]++){
      if (jata.jga.res[jata.r[0]] < jata.jga.parentv[jata.r[1]]){
	for (jata.r[2] = gapc - 1; jata.r[2] > jata.r[1]; jata.r[2]--){
	  jata.jga.parentv[jata.r[2]] = jata.jga.parentv[jata.r[2]-1];
	  jata.jga.parents[jata.r[2]] = jata.jga.parents[jata.r[2]-1];
	}
	jata.jga.parentv[jata.r[1]] = jata.jga.res[jata.r[0]];
	jata.jga.parents[jata.r[1]] = jata.r[0];
	break;
      }
    }
  }
  printf("%d; parents;", jata.jga.gen);
  for (jata.r[0] = 0; jata.r[0] < gapc; jata.r[0]++){
    printf(" %d %d %g;", jata.r[0], jata.jga.parents[jata.r[0]], jata.jga.parentv[jata.r[0]]);
  }
  printf("\n");
}

void runjga_crossover(void)
{
  jata.r[0] = 0;
  jata.r[4] = 1 + (jata.jga.gen % (gapc/2));
  for (jata.r[1] = 0; jata.r[1] < jata.jga.gacc; jata.r[1]++){
    if (jata.jga.ncount >= gapop) return;
    //printf("crossover: r[1] = %d, ncount = %d, r[0] is %d\n", jata.r[1], jata.jga.ncount, jata.r[0]);
    printf("%d; crossover; %d; %d; %d;", jata.jga.gen, jata.r[1], jata.r[0], jata.r[4]);
    for (jata.r[3] = 0; jata.r[3] < gavar; jata.r[3]++){
      if (rand() > RAND_MAX/2){
	jata.jga.npop[jata.jga.ncount][jata.r[3]] = jata.jga.cpop[jata.jga.parents[jata.r[0]]][jata.r[3]];
      }
      else{
	jata.jga.npop[jata.jga.ncount][jata.r[3]] = jata.jga.cpop[jata.jga.parents[jata.r[0]+jata.r[4]]][jata.r[3]];
      }
      //printf(" %d", jata.jga.npop[jata.jga.ncount][jata.r[3]]);
    }
    printf("\n");
    jata.jga.ncount++;
    //jata.r[0] = jata.r[0] + 2;
    //if (jata.r[0] > gapc - 2) jata.r[0] = 1;
    jata.r[0]++;
    if (jata.r[0] % jata.r[4] == 0) jata.r[0] += jata.r[4];
    if (jata.r[0] >= gapc - jata.r[4]){
      jata.r[0] = 0;
      //jata.r[4] = 1 + jata.r[4]/3;
      jata.r[4]++;
    }
  }
  /*jata.r[0] = 0;
  jata.r[4] = 1 + (jata.jga.gen % (gapc/2));
  for (jata.r[1] = 0; jata.r[1] < jata.jga.gacc; jata.r[1]++){
    if (jata.jga.ncount >= gapop) return;
    //printf("crossover: r[1] = %d, ncount = %d, r[0] is %d\n", jata.r[1], jata.jga.ncount, jata.r[0]);
    printf("%d; crossover; %d; %d;", jata.jga.gen, jata.r[1], jata.r[0]);
    for (jata.r[3] = 0; jata.r[3] < gavar; jata.r[3]++){
      if (rand() > RAND_MAX/2){
	jata.jga.npop[jata.jga.ncount][jata.r[3]] = jata.jga.cpop[jata.jga.parents[jata.r[0]]][jata.r[3]];
      }
      else{
	jata.jga.npop[jata.jga.ncount][jata.r[3]] = jata.jga.cpop[jata.jga.parents[jata.r[0]+1]][jata.r[3]];
      }
      printf(" %d", jata.jga.npop[jata.jga.ncount][jata.r[3]]);
    }
    printf("\n");
    jata.jga.ncount++;
    //jata.r[0] = jata.r[0] + 2;
    //if (jata.r[0] > gapc - 2) jata.r[0] = 1;
    jata.r[0]++;
    if (jata.r[0] % jata.r[4] == 0) jata.r[0] += jata.r[4];
    if (jata.r[0] > gapc - jata.r[4]){
      jata.r[0] = 0;
      jata.r[4] = 1 + jata.r[4]/3;
    }
    }*/
}

void runjga_mutate(void)
{
  jata.d[0] = 3 + (jata.jga.gen*2.0/jata.jga.genmax);//(1 - jata.jga.shrink*(jata.jga.gen/jata.jga.genmax))*jata.jga.scale*(jata.jga.gaub - jata.jga.galb);
  jata.r[2] = 0;
  for (jata.r[0] = 0; jata.r[0] < jata.jga.gamc; jata.r[0]++){
    if (jata.jga.ncount >= gapop) return;
    printf("%d; mutate; %d; %d;", jata.jga.gen, jata.r[0], jata.r[2]);
    for (jata.r[1] = 0; jata.r[1] < gavar; jata.r[1]++){
      jata.jga.npop[jata.jga.ncount][jata.r[1]] = jata.jga.cpop[jata.jga.parents[jata.r[2]]][jata.r[1]] + (rand() - 0.5*RAND_MAX)*jata.d[0]/RAND_MAX;
      if (jata.jga.npop[jata.jga.ncount][jata.r[1]] > jata.jga.gaub){
	jata.jga.npop[jata.jga.ncount][jata.r[1]] += jata.jga.galb - jata.jga.gaub;
      }
      else if (jata.jga.npop[jata.jga.ncount][jata.r[1]] < jata.jga.galb){
	jata.jga.npop[jata.jga.ncount][jata.r[1]] += jata.jga.gaub - jata.jga.galb;
      }
      printf(" %d", jata.jga.npop[jata.jga.ncount][jata.r[1]]);
    }
    printf("\n");
    jata.jga.ncount++;
    jata.r[2]++;
    if (jata.r[2] >= gapc) jata.r[2] = 0;
  }
}

void runjga_cost(void)
{
  //printf("In runjga cost\n");
  if (jata.jga.loadtarget == 0) runjga_loadtarget();
  if (jata.jga.loadtargetvar == 0) runjga_loadtargetvar();
  //printf("still going in cost\n");
  jata.d[0] = 0;
  /*for (jata.r[0] = 0; jata.r[0] < ftorc; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < ttorc; jata.r[1]++){
      printf("%g ", jata.avestrf[jata.jga.cindex][jata.r[0]][jata.r[1]]);
    }
    printf("\n");
    }*/
  for (jata.r[0] = 0; jata.r[0] < ttorc; jata.r[0]++){
    jata.d[1] = 1 - (0.005*pow(jata.r[0], 2));
    for (jata.r[1] = 0; jata.r[1] < ftorc; jata.r[1]++){
      jata.d[2] = jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]]/(1+exp(-(fabs(jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]])-0.8)/0.05));
      jata.d[3] = jata.jga.target[jata.r[1]][jata.r[0]]/(1+exp(-(fabs(jata.jga.target[jata.r[1]][jata.r[0]])-0.8)/0.05));
      if (jata.d[2] > jata.d[3]) jata.d[4] = jata.d[2];
      else jata.d[4] = jata.d[3];
      if (jata.d[4] < 0.001) jata.d[4] = 0.001;
      //if (jata.r[1] == 13) printf("%d %d => %g conv %g\n", jata.r[1], jata.r[0], jata.jga.target[jata.r[1]][jata.r[0]], jata.d[3]);
      //jata.d[0] += jata.d[1]*pow(pow((jata.d[2] - jata.d[3]), 2), 0.5);
      //jata.d[0] += 0.02*jata.d[1]*pow(pow((jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5);
      if (fabs(jata.jga.target[jata.r[1]][jata.r[0]]) > 3) jata.d[2] = 1;
      //else if (fabs(jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]]) > 3) jata.d[2] = 1;
      //else if (fabs(jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]]) > 2) jata.d[2] = 0.1;
      //else if (fabs(jata.jga.target[jata.r[1]][jata.r[0]]) > 2) jata.d[2] = 0.1;
      else jata.d[2] = 0.1;
      //jata.d[0] += jata.d[2]*jata.d[1]*pow(pow((jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5);
      //jata.d[0] += jata.d[4]*jata.d[1]*pow(pow((jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5);
      //printf("%g; %g; %g; %g\n", jata.jga.targetvar[jata.r[1]][jata.r[0]], pow(pow((jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5), jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]], jata.jga.target[jata.r[1]][jata.r[0]]);
      //jata.d[0] += jata.jga.targetvar[jata.r[1]][jata.r[0]]*pow(pow((jata.avestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5);
      //printf("%d; %d => %g (from %g; %g; %g)\n", jata.r[0], jata.r[1], (fabs(jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]])/jata.jga.targetvar[jata.r[1]][jata.r[0]]), jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]], jata.jga.target[jata.r[1]][jata.r[0]], jata.jga.targetvar[jata.r[1]][jata.r[0]]);
      //jata.d[0] += (fabs(jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]])/jata.jga.targetvar[jata.r[1]][jata.r[0]]);
      //jata.d[0] += fabs(jata.jga.target[jata.r[1]][jata.r[0]])*(fabs(jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]])/jata.jga.targetvar[jata.r[1]][jata.r[0]]);
      printf("%d; %d => %g (from %g; %g)\n", jata.r[0], jata.r[1], pow(pow((jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5), jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]], jata.jga.target[jata.r[1]][jata.r[0]]);
      jata.d[0] += jata.d[2]*pow(pow((jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5);
      //jata.d[0] += jata.jga.targetvar[jata.r[1]][jata.r[0]]*pow(pow((jata.tavestrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5);
      /*if (fabs(jata.d[3]) > 0.5){
        printf("cost target from %d, %d is %g (taken from %g and %g)\n", jata.r[1], jata.r[0], jata.d[1]*pow(pow((jata.d[2] - jata.d[3]), 2), 0.5), jata.d[3], jata.d[2]);
        //printf("%g vs %g\n", jata.d[2], fabs(jata.d[2]));
      }
      else if (fabs(jata.d[2]) > 0.5){
        printf("cost result from %d, %d is %g (taken from t=%g and r=%g)\n", jata.r[1], jata.r[0], jata.d[1]*pow(pow((jata.d[2] - jata.d[3]), 2), 0.5), jata.d[3], jata.d[2]);
        }*/
    }
    //printf("\n");
  }
  if (jata.taps[jata.jga.cindex] < 50) jata.d[0] += 1000;
  else if (jata.taps[jata.jga.cindex] < 100) jata.d[0] += 500;
  else if (jata.taps[jata.jga.cindex] < 250) jata.d[0] += 100;
  else if (jata.taps[jata.jga.cindex] > 100000) jata.d[0] += 1000;
  else if (jata.taps[jata.jga.cindex] > 70000) jata.d[0] += 500;
  else if (jata.taps[jata.jga.cindex] > 50000) jata.d[0] += 100;
  /*jata.d[0] += 10 - 10*exp(-pow((jata.taps[jata.jga.cindex]-166),2)/pow(500, 2));
  if (jata.taps[jata.jga.cindex] == 0) jata.d[0] += 100;
  jata.r[2] = -1;
  jata.r[3] = -1;
  jata.r[4] = -1;
  jata.r[5] = -1;
  for (jata.r[0] = 0; jata.r[0] < ftorc; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < ttorc; jata.r[1]++){
      if (jata.jga.target[jata.r[0]][jata.r[1]] > 0.99){
	jata.r[2] = jata.r[0];
	jata.r[3] = jata.r[1];
      }
      if (jata.jga.target[jata.r[0]][jata.r[1]] < -0.99){
	jata.r[4] = jata.r[0];
	jata.r[5] = jata.r[1];
      }
    }
  }
  jata.d[1] = ftorc + ttorc;
  jata.d[2] = ftorc + ttorc;
  for (jata.r[0] = 0; jata.r[0] < ftorc; jata.r[0]++){
    for (jata.r[1] = 0; jata.r[1] < ttorc; jata.r[1]++){
      if (jata.avestrf[jata.jga.cindex][jata.r[0]][jata.r[1]] > 0.99){
	jata.d[3] = 5*(abs(jata.r[2] - jata.r[0]) + abs(jata.r[3] - jata.r[1]));
	if (jata.d[3] < jata.d[1]) jata.d[1] = jata.d[3];
      }
      if (jata.avestrf[jata.jga.cindex][jata.r[0]][jata.r[1]] < -0.99){
	jata.d[3] = 5*(abs(jata.r[4] - jata.r[0]) + abs(jata.r[5] - jata.r[1]));
	if (jata.d[3] < jata.d[2]) jata.d[2] = jata.d[3];
      }
    }
  }
  jata.d[0] += jata.d[1] + jata.d[2];*/
  jata.jga.res[jata.jga.id] = jata.d[0];
  //printf("%d: cost is %g (calculated from %d aps)\n", jata.jmpi.id, jata.jga.res[jata.jga.id], jata.taps[jata.jga.cindex]);
}

void runjga_cost_smooth(void)
{
  if (jata.jga.loadtarget == 0) runjga_loadtarget_smooth();
  jata.d[0] = 0;
  for (jata.r[0] = 0; jata.r[0] < sttorc; jata.r[0]++){
    jata.d[1] = 1 - (0.000014*pow(jata.r[0], 2));
    for (jata.r[1] = 0; jata.r[1] < sftorc; jata.r[1]++){
      if (fabs(jata.jga.target[jata.r[1]][jata.r[0]]) >= 3) jata.d[2] = 1;
      else jata.d[2] = 0.1;
      jata.d[0] += jata.d[2]*pow(pow((jata.tsmoothstrf[jata.jga.cindex][jata.r[1]][jata.r[0]] - jata.jga.target[jata.r[1]][jata.r[0]]), 2), 0.5);
      //if (fabs(jata.tsmoothstrf[jata.jga.cindex][jata.r[1]][jata.r[0]]) + fabs(jata.jga.target[jata.r[1]][jata.r[0]]) > 0){
      //if (fabs(jata.jga.target[jata.r[1]][jata.r[0]]) > 0){
      //printf("%d %d %g %g\n", jata.r[0], jata.r[1], jata.tsmoothstrf[jata.jga.cindex][jata.r[1]][jata.r[0]], jata.jga.target[jata.r[1]][jata.r[0]]);
      //}
    }
  }
  if (jata.taps[jata.jga.cindex] < 50) jata.d[0] += 1000;
  else if (jata.taps[jata.jga.cindex] < 100) jata.d[0] += 500;
  else if (jata.taps[jata.jga.cindex] < 250) jata.d[0] += 100;
  else if (jata.taps[jata.jga.cindex] > 100000) jata.d[0] += 1000;
  else if (jata.taps[jata.jga.cindex] > 70000) jata.d[0] += 500;
  else if (jata.taps[jata.jga.cindex] > 50000) jata.d[0] += 100;
  jata.jga.res[jata.jga.id] = jata.d[0];
  printf("%d: cost is %g (calculated from %d aps)\n", jata.jmpi.id, jata.jga.res[jata.jga.id], jata.taps[jata.jga.cindex]);
}

void runjga_loadtarget(void)
{
  //printf("loading target\n");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05_raw.txt");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05_1norm.txt");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05g5raw.txt");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05g5norm.txt");
  sprintf(&jata.fname[0], "./targets/twasabi003a06rawsdg3.txt");
  jata.f = fopen(&jata.fname[0], "r");
  jata.r[0] = 1;
  jata.r[1] = 0;
  while (jata.r[0] == 1){
    jata.r[2] = fscanf(jata.f, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &jata.jga.target[jata.r[1]][0], &jata.jga.target[jata.r[1]][1], &jata.jga.target[jata.r[1]][2], &jata.jga.target[jata.r[1]][3], &jata.jga.target[jata.r[1]][4], &jata.jga.target[jata.r[1]][5], &jata.jga.target[jata.r[1]][6], &jata.jga.target[jata.r[1]][7], &jata.jga.target[jata.r[1]][8], &jata.jga.target[jata.r[1]][9], &jata.jga.target[jata.r[1]][10], &jata.jga.target[jata.r[1]][11], &jata.jga.target[jata.r[1]][12]);
    if (jata.r[2] != ttorc){
      jata.r[0] = 0;
      break;
    }
    jata.r[1]++;
    if (jata.r[1] == ftorc){
      jata.r[0] = 0;
      break;
    }
  }
  if (jata.r[1] != ftorc){
    printf("Potential error loading target strf: %d frequencies loaded\n", jata.r[1]);
  }
  fclose(jata.f);
  jata.jga.loadtarget = 1;
  //printf("target loaded\n");
}

void runjga_loadtarget_smooth(void)
{
  sprintf(&jata.fname[0], "./targets/wasabi003passivesmoothsdg3.txt");
  //sprintf(&jata.fname[0], "./targets/wasabi003activesmoothsdg3.txt");
  //sprintf(&jata.fname[0], "./targets/jt4asdg3smooth.txt");
  //sprintf(&jata.fname[0], "./targets/sirpassivesmoothsdg3.txt");
  //sprintf(&jata.fname[0], "./targets/sirbehavioursmoothsdg3.txt");
  jata.f = fopen(&jata.fname[0], "r");
  jata.r[0] = 1;
  jata.r[1] = 0;
  while (jata.r[0] == 1){
    jata.r[2] = fscanf(jata.f, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &jata.jga.target[jata.r[1]][0], &jata.jga.target[jata.r[1]][1], &jata.jga.target[jata.r[1]][2], &jata.jga.target[jata.r[1]][3], &jata.jga.target[jata.r[1]][4], &jata.jga.target[jata.r[1]][5], &jata.jga.target[jata.r[1]][6], &jata.jga.target[jata.r[1]][7], &jata.jga.target[jata.r[1]][8], &jata.jga.target[jata.r[1]][9], &jata.jga.target[jata.r[1]][10], &jata.jga.target[jata.r[1]][11], &jata.jga.target[jata.r[1]][12], &jata.jga.target[jata.r[1]][13], &jata.jga.target[jata.r[1]][14], &jata.jga.target[jata.r[1]][15], &jata.jga.target[jata.r[1]][16], &jata.jga.target[jata.r[1]][17], &jata.jga.target[jata.r[1]][18], &jata.jga.target[jata.r[1]][19], &jata.jga.target[jata.r[1]][20], &jata.jga.target[jata.r[1]][21], &jata.jga.target[jata.r[1]][22], &jata.jga.target[jata.r[1]][23], &jata.jga.target[jata.r[1]][24], &jata.jga.target[jata.r[1]][25], &jata.jga.target[jata.r[1]][26], &jata.jga.target[jata.r[1]][27], &jata.jga.target[jata.r[1]][28], &jata.jga.target[jata.r[1]][29], &jata.jga.target[jata.r[1]][30], &jata.jga.target[jata.r[1]][31], &jata.jga.target[jata.r[1]][32], &jata.jga.target[jata.r[1]][33], &jata.jga.target[jata.r[1]][34], &jata.jga.target[jata.r[1]][35], &jata.jga.target[jata.r[1]][36], &jata.jga.target[jata.r[1]][37], &jata.jga.target[jata.r[1]][38], &jata.jga.target[jata.r[1]][39], &jata.jga.target[jata.r[1]][40], &jata.jga.target[jata.r[1]][41], &jata.jga.target[jata.r[1]][42], &jata.jga.target[jata.r[1]][43], &jata.jga.target[jata.r[1]][44], &jata.jga.target[jata.r[1]][45], &jata.jga.target[jata.r[1]][46], &jata.jga.target[jata.r[1]][47], &jata.jga.target[jata.r[1]][48], &jata.jga.target[jata.r[1]][49], &jata.jga.target[jata.r[1]][50], &jata.jga.target[jata.r[1]][51], &jata.jga.target[jata.r[1]][52], &jata.jga.target[jata.r[1]][53], &jata.jga.target[jata.r[1]][54], &jata.jga.target[jata.r[1]][55], &jata.jga.target[jata.r[1]][56], &jata.jga.target[jata.r[1]][57], &jata.jga.target[jata.r[1]][58], &jata.jga.target[jata.r[1]][59], &jata.jga.target[jata.r[1]][60], &jata.jga.target[jata.r[1]][61], &jata.jga.target[jata.r[1]][62], &jata.jga.target[jata.r[1]][63], &jata.jga.target[jata.r[1]][64], &jata.jga.target[jata.r[1]][65], &jata.jga.target[jata.r[1]][66], &jata.jga.target[jata.r[1]][67], &jata.jga.target[jata.r[1]][68], &jata.jga.target[jata.r[1]][69], &jata.jga.target[jata.r[1]][70], &jata.jga.target[jata.r[1]][71], &jata.jga.target[jata.r[1]][72], &jata.jga.target[jata.r[1]][73], &jata.jga.target[jata.r[1]][74], &jata.jga.target[jata.r[1]][75], &jata.jga.target[jata.r[1]][76], &jata.jga.target[jata.r[1]][77], &jata.jga.target[jata.r[1]][78], &jata.jga.target[jata.r[1]][79], &jata.jga.target[jata.r[1]][80], &jata.jga.target[jata.r[1]][81], &jata.jga.target[jata.r[1]][82], &jata.jga.target[jata.r[1]][83], &jata.jga.target[jata.r[1]][84], &jata.jga.target[jata.r[1]][85], &jata.jga.target[jata.r[1]][86], &jata.jga.target[jata.r[1]][87], &jata.jga.target[jata.r[1]][88], &jata.jga.target[jata.r[1]][89], &jata.jga.target[jata.r[1]][90], &jata.jga.target[jata.r[1]][91], &jata.jga.target[jata.r[1]][92], &jata.jga.target[jata.r[1]][93], &jata.jga.target[jata.r[1]][94], &jata.jga.target[jata.r[1]][95], &jata.jga.target[jata.r[1]][96], &jata.jga.target[jata.r[1]][97], &jata.jga.target[jata.r[1]][98], &jata.jga.target[jata.r[1]][99], &jata.jga.target[jata.r[1]][100], &jata.jga.target[jata.r[1]][101], &jata.jga.target[jata.r[1]][102], &jata.jga.target[jata.r[1]][103], &jata.jga.target[jata.r[1]][104], &jata.jga.target[jata.r[1]][105], &jata.jga.target[jata.r[1]][106], &jata.jga.target[jata.r[1]][107], &jata.jga.target[jata.r[1]][108], &jata.jga.target[jata.r[1]][109], &jata.jga.target[jata.r[1]][110], &jata.jga.target[jata.r[1]][111], &jata.jga.target[jata.r[1]][112], &jata.jga.target[jata.r[1]][113], &jata.jga.target[jata.r[1]][114], &jata.jga.target[jata.r[1]][115], &jata.jga.target[jata.r[1]][116], &jata.jga.target[jata.r[1]][117], &jata.jga.target[jata.r[1]][118], &jata.jga.target[jata.r[1]][119], &jata.jga.target[jata.r[1]][120], &jata.jga.target[jata.r[1]][121], &jata.jga.target[jata.r[1]][122], &jata.jga.target[jata.r[1]][123], &jata.jga.target[jata.r[1]][124], &jata.jga.target[jata.r[1]][125], &jata.jga.target[jata.r[1]][126], &jata.jga.target[jata.r[1]][127], &jata.jga.target[jata.r[1]][128], &jata.jga.target[jata.r[1]][129], &jata.jga.target[jata.r[1]][130], &jata.jga.target[jata.r[1]][131], &jata.jga.target[jata.r[1]][132], &jata.jga.target[jata.r[1]][133], &jata.jga.target[jata.r[1]][134], &jata.jga.target[jata.r[1]][135], &jata.jga.target[jata.r[1]][136], &jata.jga.target[jata.r[1]][137], &jata.jga.target[jata.r[1]][138], &jata.jga.target[jata.r[1]][139], &jata.jga.target[jata.r[1]][140], &jata.jga.target[jata.r[1]][141], &jata.jga.target[jata.r[1]][142], &jata.jga.target[jata.r[1]][143], &jata.jga.target[jata.r[1]][144], &jata.jga.target[jata.r[1]][145], &jata.jga.target[jata.r[1]][146], &jata.jga.target[jata.r[1]][147], &jata.jga.target[jata.r[1]][148], &jata.jga.target[jata.r[1]][149], &jata.jga.target[jata.r[1]][150], &jata.jga.target[jata.r[1]][151], &jata.jga.target[jata.r[1]][152], &jata.jga.target[jata.r[1]][153], &jata.jga.target[jata.r[1]][154], &jata.jga.target[jata.r[1]][155], &jata.jga.target[jata.r[1]][156], &jata.jga.target[jata.r[1]][157], &jata.jga.target[jata.r[1]][158], &jata.jga.target[jata.r[1]][159], &jata.jga.target[jata.r[1]][160], &jata.jga.target[jata.r[1]][161], &jata.jga.target[jata.r[1]][162], &jata.jga.target[jata.r[1]][163], &jata.jga.target[jata.r[1]][164], &jata.jga.target[jata.r[1]][165], &jata.jga.target[jata.r[1]][166], &jata.jga.target[jata.r[1]][167], &jata.jga.target[jata.r[1]][168], &jata.jga.target[jata.r[1]][169], &jata.jga.target[jata.r[1]][170], &jata.jga.target[jata.r[1]][171], &jata.jga.target[jata.r[1]][172], &jata.jga.target[jata.r[1]][173], &jata.jga.target[jata.r[1]][174], &jata.jga.target[jata.r[1]][175], &jata.jga.target[jata.r[1]][176], &jata.jga.target[jata.r[1]][177], &jata.jga.target[jata.r[1]][178], &jata.jga.target[jata.r[1]][179], &jata.jga.target[jata.r[1]][180], &jata.jga.target[jata.r[1]][181], &jata.jga.target[jata.r[1]][182], &jata.jga.target[jata.r[1]][183], &jata.jga.target[jata.r[1]][184], &jata.jga.target[jata.r[1]][185], &jata.jga.target[jata.r[1]][186], &jata.jga.target[jata.r[1]][187], &jata.jga.target[jata.r[1]][188], &jata.jga.target[jata.r[1]][189], &jata.jga.target[jata.r[1]][190], &jata.jga.target[jata.r[1]][191], &jata.jga.target[jata.r[1]][192], &jata.jga.target[jata.r[1]][193], &jata.jga.target[jata.r[1]][194], &jata.jga.target[jata.r[1]][195], &jata.jga.target[jata.r[1]][196], &jata.jga.target[jata.r[1]][197], &jata.jga.target[jata.r[1]][198], &jata.jga.target[jata.r[1]][199], &jata.jga.target[jata.r[1]][200], &jata.jga.target[jata.r[1]][201], &jata.jga.target[jata.r[1]][202], &jata.jga.target[jata.r[1]][203], &jata.jga.target[jata.r[1]][204], &jata.jga.target[jata.r[1]][205], &jata.jga.target[jata.r[1]][206], &jata.jga.target[jata.r[1]][207], &jata.jga.target[jata.r[1]][208], &jata.jga.target[jata.r[1]][209], &jata.jga.target[jata.r[1]][210], &jata.jga.target[jata.r[1]][211], &jata.jga.target[jata.r[1]][212], &jata.jga.target[jata.r[1]][213], &jata.jga.target[jata.r[1]][214], &jata.jga.target[jata.r[1]][215], &jata.jga.target[jata.r[1]][216], &jata.jga.target[jata.r[1]][217], &jata.jga.target[jata.r[1]][218], &jata.jga.target[jata.r[1]][219], &jata.jga.target[jata.r[1]][220], &jata.jga.target[jata.r[1]][221], &jata.jga.target[jata.r[1]][222], &jata.jga.target[jata.r[1]][223], &jata.jga.target[jata.r[1]][224], &jata.jga.target[jata.r[1]][225], &jata.jga.target[jata.r[1]][226], &jata.jga.target[jata.r[1]][227], &jata.jga.target[jata.r[1]][228], &jata.jga.target[jata.r[1]][229], &jata.jga.target[jata.r[1]][230], &jata.jga.target[jata.r[1]][231], &jata.jga.target[jata.r[1]][232], &jata.jga.target[jata.r[1]][233], &jata.jga.target[jata.r[1]][234], &jata.jga.target[jata.r[1]][235], &jata.jga.target[jata.r[1]][236], &jata.jga.target[jata.r[1]][237], &jata.jga.target[jata.r[1]][238], &jata.jga.target[jata.r[1]][239], &jata.jga.target[jata.r[1]][240], &jata.jga.target[jata.r[1]][241], &jata.jga.target[jata.r[1]][242], &jata.jga.target[jata.r[1]][243], &jata.jga.target[jata.r[1]][244], &jata.jga.target[jata.r[1]][245], &jata.jga.target[jata.r[1]][246], &jata.jga.target[jata.r[1]][247], &jata.jga.target[jata.r[1]][248], &jata.jga.target[jata.r[1]][249]);
    if (jata.r[2] != sttorc){
      jata.r[0] = 0;
      break;
    }
    jata.r[1]++;
    if (jata.r[1] == sftorc){
      jata.r[0] = 0;
      break;
    }
  }
  if (jata.r[1] != sftorc){
    printf("Potential error loading target strf: %d frequencies loaded\n", jata.r[1]);
  }
  fclose(jata.f);
  jata.jga.loadtarget = 1;
  //printf("target loaded\n");
}

void runjga_loadtargetvar(void)
{
  //printf("loading targetvar\n");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05_raw.txt");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05sd1norm005sig.txt");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05g5rawsd.txt");
  //sprintf(&jata.fname[0], "./targets/targetwasabi003a05g5normsd.txt");
  sprintf(&jata.fname[0], "./targets/twasabi003a05rawsdabsexp.txt");
  jata.f = fopen(&jata.fname[0], "r");
  //printf("jata.f %d\n", jata.f);
  jata.r[0] = 1;
  jata.r[1] = 0;
  while (jata.r[0] == 1){
    jata.r[2] = fscanf(jata.f, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &jata.jga.targetvar[jata.r[1]][0], &jata.jga.targetvar[jata.r[1]][1], &jata.jga.targetvar[jata.r[1]][2], &jata.jga.targetvar[jata.r[1]][3], &jata.jga.targetvar[jata.r[1]][4], &jata.jga.targetvar[jata.r[1]][5], &jata.jga.targetvar[jata.r[1]][6], &jata.jga.targetvar[jata.r[1]][7], &jata.jga.targetvar[jata.r[1]][8], &jata.jga.targetvar[jata.r[1]][9], &jata.jga.targetvar[jata.r[1]][10], &jata.jga.targetvar[jata.r[1]][11], &jata.jga.targetvar[jata.r[1]][12]);
    //printf("targetvar %g %g %g %g %g %g %g %g %g %g %g %g %g\n", jata.jga.targetvar[jata.r[1]][0], jata.jga.targetvar[jata.r[1]][1], jata.jga.targetvar[jata.r[1]][2], jata.jga.targetvar[jata.r[1]][3], jata.jga.targetvar[jata.r[1]][4], jata.jga.targetvar[jata.r[1]][5], jata.jga.targetvar[jata.r[1]][6], jata.jga.targetvar[jata.r[1]][7], jata.jga.targetvar[jata.r[1]][8], jata.jga.targetvar[jata.r[1]][9], jata.jga.targetvar[jata.r[1]][10], jata.jga.targetvar[jata.r[1]][11], jata.jga.targetvar[jata.r[1]][12]);
    if (jata.r[2] != ttorc){
      jata.r[0] = 0;
      break;
    }
    jata.r[1]++;
    if (jata.r[1] == ftorc){
      jata.r[0] = 0;
      break;
    }
  }
  if (jata.r[1] != ftorc){
    printf("Potential error loading targetvar strf: %d frequencies loaded\n", jata.r[1]);
  }
  fclose(jata.f);
  jata.jga.loadtargetvar = 1;
  //printf("targetvar loaded\n");
}