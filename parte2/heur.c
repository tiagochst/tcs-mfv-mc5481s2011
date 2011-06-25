#include"heur.h"

/* Program 
   Authors:
   - Murilo Fossa Vicentini
   - Tiago Chedraoui Silva
*/

/*
 * Global variables,   used beacause of alarm signal
 * Other gv are only for debug purpose see heur.h 
 */
Solution zf;
char OUTPUT [100];

Solution oldzf;
Satelite oldsat[301];
Shard oldshard [50914];
int gain;
/*****     FUNCTIONS     *****/

void Local_search(Shard s[],Satelite sat[], int k,int nsat)
{
  Solution zrand;
  int LRC[11];/*At least 100 options*/
  int rm_shard,nlrc;
  int i,it=0;

  /* We choose a shard from solution to take off 
     And make a list (lrc) of 11 new possibilities
     to be chosen (the last one is the removed one) 
     we try to put every one of lrc taht fits in
     (memory limits our choice)
     if better result, save 
     if not a better result try other random shard
  */
  copy_sol(&zrand);

  while(1){
    /*get the best solution, this will be our start point*/
   
    /*
      For every shard of solution we take it out
      And try to put other shards
    */
    for(rm_shard=zrand.nshards-1; rm_shard>=0; rm_shard--){

      save_state(sat,k,s,nsat);
      
      /*Clear possible candidates to be in place in solution*/    
      for(i=0;i<11;i++){
	LRC[i]=0;
      }
    
      nlrc=find_lrc(LRC,k,s,rm_shard);
 
      /*insert removed node at end of lrc*/
      /*     LRC[nlrc]=zrand.chosen[rm_shard].idx;
      nlrc++;
      */
      /*removing node from solution*/
      rm(rm_shard,&zrand,sat,s);

      choose_lrc(&zrand,LRC,nlrc,s,sat);
    
      if(zrand.value>zf.value){
	printf("\n%d %d",zrand.value,it);
	save_sol(&zrand);
      }
      else{
	recover_state(sat,k,s,nsat);
	copy_sol(&zrand);
      }
      it++;
    }
  }
}

int choose_lrc(Solution* zrand,int LRC[],int nshard,Shard s[],
	       Satelite sat[])
{
  int save=0,i;

  /*Every shard of lrc is tried*/
  for(i=0;i<nshard;i++){

    /*If it fits in solution, put it in*/
    if(sat[s[LRC[i]].x].hmemory>= s[LRC[i]].hcost && s[LRC[i]].active==1 ){
      save=1;
      (*zrand).chosen[(*zrand).nshards].dir='h';
      sat[s[LRC[i]].x].hmemory-=s[LRC[i]].hcost;
    }
    else if(sat[s[LRC[i]].y].vmemory>= s[LRC[i]].vcost && s[LRC[i]].active==1){
      save=1;
      (*zrand).chosen[(*zrand).nshards].dir='v';
      sat[s[LRC[i]].y].vmemory-=s[LRC[i]].vcost;
    }
    if(save==1){
      s[LRC[i]].active=0;
      (*zrand).value=(*zrand).value+s[LRC[i]].gain;
      (*zrand).chosen[(*zrand).nshards].idx=LRC[i];
      (*zrand).chosen[(*zrand).nshards].x=s[LRC[i]].x;
      (*zrand).chosen[(*zrand).nshards].y=s[LRC[i]].y;
      (*zrand).nshards++;
      save=0;
    }
  }
  return i;
}

void rm(int rm_shard,Solution* zrand,Satelite sat[],Shard s[])
{
  int i;

  /*Remove shard and restore memory, shards avaiability,
    and  decrease value of best solution
  */
  if((*zrand).chosen[rm_shard].dir=='h'){
    sat[(*zrand).chosen[rm_shard].x].hmemory+=s[(*zrand).chosen[rm_shard].idx].hcost;
    s[(*zrand).chosen[rm_shard].idx].active=1;
  }
  else{
    sat[(*zrand).chosen[rm_shard].y].vmemory+=s[(*zrand).chosen[rm_shard].idx].vcost;
    s[(*zrand).chosen[rm_shard].idx].active=1;
  }
  
  (*zrand).value-=s[(*zrand).chosen[rm_shard].idx].gain;
  
  /* Remove shard from solution */
  for(i=rm_shard;i<(*zrand).nshards;i++){
    (*zrand).chosen[i]=(*zrand).chosen[i+1];
  }
  (*zrand).chosen[i].idx=-1;
  (*zrand).chosen[i].x=-1;
  (*zrand).chosen[i].y=-1;
  (*zrand).nshards--;
}

int find_lrc(int LRC[],int nshards,Shard s[],int rm_shard)
{
  int aux,i=0,find;
  if(zf.chosen[rm_shard].dir=='h'){
    find=zf.chosen[rm_shard].x;
    for(aux=1;aux<=nshards;aux++){
      if(i==10)
	break;
      if(s[aux].x==find && s[aux].active==1){
	LRC[i]=aux;
	i++;
      }
    }
  }
  else{
    find=zf.chosen[rm_shard].y;
    for(aux=1;aux<=nshards;aux++){
      if(i==10)
	break;
      if(s[aux].y==find && s[aux].active==1){
	LRC[i]=aux;
	i++;
      }
    }
  }
  return i;
}

void Greedy_solver(Shard s[],Satelite sat[],int k)
{
  int i,vmin,vmax,save;
  for(i=1;i<=k;i++){
    vmin=min(s[i].vcost,s[i].hcost);
    vmax=max(s[i].vcost,s[i].hcost);
    save=0;
    if(vmin==s[i].hcost){
      if(sat[s[i].x].hmemory>= vmin){
	save=1;
	zf.chosen[zf.nshards].dir='h';
	sat[s[i].x].hmemory-=s[i].hcost;
      }
      else if(sat[s[i].y].vmemory>= vmax){
	save=1;
	zf.chosen[zf.nshards].dir='v';
	sat[s[i].y].vmemory-=s[i].vcost;
      }
    }
    else if(vmin==s[i].vcost){
      if(sat[s[i].y].vmemory>= vmin){
	save=1;
	zf.chosen[zf.nshards].dir='v';
	sat[s[i].y].vmemory-=s[i].vcost;
      }
      else if(sat[s[i].x].hmemory>= vmax){
	save=1;
	zf.chosen[zf.nshards].dir='h';
	sat[s[i].x].hmemory-=s[i].hcost;
      }
    }
    if(save==1){
      s[i].active=0;
      zf.value=zf.value+s[i].gain;
      zf.chosen[zf.nshards].idx=i;
      zf.chosen[zf.nshards].x=s[i].x;
      zf.chosen[zf.nshards].y=s[i].y;
      zf.nshards++;
    }
  }
}


/* Sort functions */
void change(Shard s[],int i,int j ){
  Shard aux=s[i];
  s[i]=s[j];
  s[j]=aux;
}

int partition(Shard s[],int p,int r){
  Shard aux=s[r];
  int i,j;

  i=p-1;
  for(j=p;j<r;j++){
    if((float)s[j].gain/min(s[j].hcost,s[j].vcost)>=(float)aux.gain/min(aux.hcost,aux.vcost)){
      i++;
      change(s,i,j);
    }
  }
  change(s,i+1,r);
  return i+1;
}

void quicksort(Shard s[],int begin,int end){
  int q;
  if (begin<end){
    q=partition(s,begin,end);
    quicksort(s,begin,q-1);
    quicksort(s,q+1,end);
  }
}


/* Input/output functions */
void write_solution()
{
  int i;
  FILE * pFile;

  pFile = fopen(OUTPUT, "w"); 
  if (pFile == NULL) {
    printf("INPUT file is invalid\n");
    exit(0);
  }

  fprintf(pFile, "%d\n",zf.value);
  fprintf(pFile, "%d\n",zf.nshards);

  for(i=0;i<zf.nshards;i++){
    fprintf(pFile, "%d ",zf.chosen[i].x);
    fprintf(pFile, "%d ",zf.chosen[i].y);
    fprintf(pFile, "%c\n",zf.chosen[i].dir);
  }
  fclose(pFile);

}

void read_instances(char INPUT[], int* nsat,int* k,
		    Shard shard [],Satelite sat[])
{
  int i=0,j=0,aux=0;
  FILE * pFile;

  /* Leitura de arquivo de entrada  */
  pFile = fopen(INPUT, "r"); 
  if (pFile == NULL) {
    printf("INPUT file is invalid\n");
    exit(0);
  }

  /* Leitura do numero de satelites */
  fscanf (pFile,"%d",&aux);
  *nsat=aux;

  /* Leitura dos satelites */
  for(j=1;j<=*nsat;j++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&sat[i].hmemory);
  }
  for(j=1;j<=*nsat;j++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&sat[i].vmemory);
  }

  /* Leitura do numero de shards */
  fscanf (pFile,"%d",&aux);
  *k=aux;
  /* Leitura dos shards */
  for(j=1;j<=*k;j++){
    fscanf (pFile,"%d",&shard[j].x);
    fscanf (pFile,"%d",&shard[j].y);
    fscanf (pFile,"%d",&shard[j].gain);
    fscanf (pFile,"%d",&shard[j].hcost);
    fscanf (pFile,"%d",&shard[j].vcost);
  }
  
  fclose(pFile);
}

/* Command line error message */
void error_args()
{
  printf("\n****************************************************\n");
  printf(" Program should receive the following parameters :\n");
  printf(" -t Time -o SAIDA ENTRADA\n");
  printf("****************************************************\n");

  return;
}

/*
  Reading all arguments
  Its is expected:
  -- A time limit:: flag [-t][integer]
  -- Output's path:: flag [-o][path]
  -- Input's path:: flag [path]
*/

void get_args(int argc, char** argv,int* TIME,char IN [],char OUT[])
{
  int i;

  if (argc < 6){
    error_args();
    exit(0);
  }  	    
  else{
    for(i=1;i<6;i++){ 
      if(strcmp(argv[i],"-t")==0){
	printf("Time limit read ...\n");
	*TIME=atoi(argv[i+1]);
	i++;
      }
      else if(strcmp(argv[i],"-o")==0){
	printf("Path output file read ...\n");
	strcpy(OUT,argv[i+1]);
	i++;
      }
      else {
	printf("Path input file read ...\n");
	strcpy(IN,argv[i]);
      }
    }
  }
}


/* Time limit's signal handler
   We should print our best solution 
   reached within time limit
*/
void end_heur() 
{
  printf("\nTIME LIMIT EXCEDED");
  write_solution();
  verify_solution();

  exit(0);
}

/* Main program
   - Read input
   - Find a solution
*/
int main( int argc, char** argv)
{
  /*Program parameters*/
  int TIME;
  char INPUT[100];

  /*Intances*/
  Shard shard [50914];
  Satelite sat[301];
  int nsat=0,k=0,i;

  /* Defining my signal alarm*/
  signal(SIGALRM, end_heur);

  printf("Iniciando leitura de parametros...\n");
  get_args(argc,argv,&TIME,INPUT,OUTPUT);

  alarm(TIME); /*Alarme para tempo limite iniciado*/

  printf("Iniciando leitura de dados...\n");
  read_instances(INPUT,&nsat,&k,shard,sat);

  /* all shards should be avaiables*/
  for(i=1;i<=k;i++){
    shard[i].active=1;
  }

  printf("Iniciando processamento dos dados...\n");
  quicksort(shard,1,k);
  printf("sort realizado");

  /*
    Greedy solution
  */
  zf.value=0;
  zf.nshards=0;

  Greedy_solver(shard,sat,k);
 
  /* does not get out of local search this except for a given time*/
  Local_search(shard,sat,k,nsat);

  return 0;	
}

/*recover Satelite and shards info*/
void save_state(Satelite sat[], int nsat,Shard shard[],int k){
  int j;
  /* Leitura dos satelites */
  for(j=1;j<=nsat;j++){
    oldsat[j].hmemory=sat[j].hmemory;
    oldsat[j].vmemory=sat[j].vmemory;
  }
  
  /* Leitura dos shards */
  for(j=1;j<=k;j++){
    oldshard[j].x=shard[j].x;
    oldshard[j].active=shard[j].active;
    oldshard[j].y=shard[j].y;
    oldshard[j].hcost=shard[j].hcost;
    oldshard[j].gain=shard[j].gain;
    oldshard[j].vcost=shard[j].vcost;
  }
}

void recover_state(Satelite sat[],int nsat,Shard shard[],int k){
  int j;
  /* Leitura dos satelites */
  for(j=1;j<=nsat;j++){
    sat[j].hmemory=oldsat[j].hmemory;
    sat[j].vmemory=oldsat[j].vmemory;
  }
  
  /* Leitura dos shards */
  for(j=1;j<=k;j++){
    shard[j].active=oldshard[j].active;
    shard[j].x=oldshard[j].x;
    shard[j].y=oldshard[j].y;
    shard[j].hcost=oldshard[j].hcost;
    shard[j].gain=oldshard[j].gain;
    shard[j].vcost=oldshard[j].vcost;
  }
}

void copy_sol(Solution* a)
{
  int i;
  (*a).value=zf.value;
  (*a).nshards=zf.nshards;

  for(i=0;i<(*a).nshards;i++){
    (*a).chosen[i]= zf.chosen[i];
  }
}

void save_sol(Solution* a)
{
  int i;
  zf.value=(*a).value;
  zf.nshards=(*a).nshards;

  for(i=0;i<(*a).nshards;i++){
    zf.chosen[i]=(*a).chosen[i];
  }
}

/*Debug functions*/

/*
  Verify if input is read correct
  Should be used only for debug
*/
void verify_input(int nsat,int k,Shard shard [],Satelite sat[])
{
  int aux,i;

  printf("---- INSTANCIA DO PROBLEMA ----\n");
  printf("NUMERO DE SATELITES: %d\n",nsat);

  printf("SATELITES HORIZONTAIS: \n");
  for(aux=1;aux<=nsat;aux++){
    printf("%d ",sat[aux].hmemory);
  }

  printf("\nSATELITES VERTICAIS: \n");
 
  for(aux=1;aux<=nsat;aux++){
    printf("%d ",sat[aux].vmemory);
  }
  printf("\n ");
  
  for(i=1;i<=k;i++){
    printf ("  %d  ", shard[i].x);
    printf ("  %d  ", shard[i].y);
    printf ("  %d  ", shard[i].gain);
    printf ("  %d  ", shard[i].hcost);
    printf ("  %d \n", shard[i].vcost);
  }
  
  printf("\n-------------------------\n");

}

void verify_solution(){
  /*Reread file of input*/
  int i=0,j=0,k,p,nsat;
  FILE * pFile;

  /* Reading input file (you should make a copy named verifica.dat)  */
  pFile = fopen("verifica.dat", "r"); 
  if (pFile == NULL) {
    printf("INPUT file is invalid\n");
    exit(0);
  }
  
  fscanf (pFile,"%d",&nsat);
  
  for(j=1;j<=nsat;j++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&insat[i].hmemory);
    solsat[i].hmemory=0;
  }
  for(j=1;j<=nsat;j++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&insat[i].vmemory);
    solsat[i].vmemory=0;
  }
  
  fscanf (pFile,"%d",&k);
   
  for(j=1;j<=k;j++){
    fscanf (pFile,"%d",&inshard[j].x);
    fscanf (pFile,"%d",&inshard[j].y);
    fscanf (pFile,"%d",&inshard[j].gain);
    fscanf (pFile,"%d",&inshard[j].hcost);
    fscanf (pFile,"%d",&inshard[j].vcost);
  }
  
 

  /*Buscar por shards no arquivo 1*/
  /*Criar vetor auxiliar de satelites e verficar 
    se saida e menor que a memoria para cada satelite*/ 
  
  for(i=0;i<zf.nshards;i++){
    
    if(zf.chosen[i].dir=='h'){
      for(p=1;p<k;p++){
	if(inshard[p].x==zf.chosen[i].x && inshard[p].y==zf.chosen[i].y){
	  if(zf.chosen[i].x==1)
	    /*	    printf("%d %d %d %d val %d atual %d\n",inshard[p].x,zf.chosen[i].x , inshard[p].y,zf.chosen[i].y,inshard[p].hcost, solsat[zf.chosen[i].x].hmemory);*/
	  solsat[zf.chosen[i].x].hmemory+=inshard[p].hcost;
	}
      }
    }
    else if(zf.chosen[i].dir=='v'){
      for(p=1;p<k;p++){
	if(inshard[p].x==zf.chosen[i].x && inshard[p].y==zf.chosen[i].y){
	  solsat[zf.chosen[i].y].vmemory+=inshard[p].vcost;
	  /* printf("%d %d %d %d\n",inshard[p].x,zf.chosen[i].x , inshard[p].y,zf.chosen[i].y);
	   */
	}
      }
    }
  }

  /*Compara valores do arq1 um com solucao*/
  for(p=1;p<=nsat;p++){
    if(solsat[p].hmemory>insat[p].hmemory){
      printf("\nh idx %d sol %d in %d",p,solsat[p].hmemory,insat[p].hmemory);
      printf("\nERRORRR\n!!!!");
      write_solution();
      exit(0);
    }
    if(solsat[p].vmemory>insat[p].vmemory){
      printf("\nv idx %d sol %d in %d",p,solsat[p].vmemory,insat[p].vmemory);
      printf("ERRORRR!!!!");
      write_solution();
      exit(0);
    }
  }
  printf("\n@@@@   SOLUTION FEASEBLE  @@@@@\n");
      
}
