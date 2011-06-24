#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<math.h>
#include<time.h>

/* Program 
   Authors:
   - Murilo Fossa Vicentini
   - Tiago Chedraoui Silva
*/

/* Types of data*/
typedef struct {
  int x,y;
  int gain;
  int hcost,vcost; 
  int active;/*Is shard already in solution?*/
} Shard;

typedef struct {
  int hmemory;
  int vmemory; 
} Satelite;

typedef struct {
  int x;
  int y;
  char dir;
  int idx;
} CShard;

typedef struct {
  int value;
  int nshards; 
  CShard chosen[50914];
} Solution;

/* Global variables,
   used beacause of alarm signal
*/
Solution zf;
char OUTPUT [100];
int gain;

void Greedy_solver(Shard s[],Satelite sat[], int nsat, int k);
void copy_sol(Solution* a);
void Local_search(Shard s[],Satelite sat[], int nsat, int k);

/*Macros */
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

/*****     FUNCTIONS     *****/

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

  fscanf (pFile,"%d",&aux);
  *nsat=aux;

  for(j=1;j<=*nsat;j++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&sat[i].hmemory);
  }
  for(j=1;j<=*nsat;j++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&sat[i].vmemory);
  }
  
  fscanf (pFile,"%d",&aux);
  *k=aux;

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
  printf("\nINPUT:%s,OUTPUT:%s,TIME:%d\n",IN,OUT,*TIME);
}


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



/* Time limit's signal handler
   We should print our best solution 
   reached within time limit
*/
void end_heur() 
{
  printf("\nFim do programa: alarme é tratado pela função end_heur().\n");
  printf("TIME LIMIT EXCEDED\n");
  write_solution();

  exit(0);
}

/*
  Verify if input is read correct
  Should be used only for debug
*/
void verify_sort(int nsat,int k,Shard shard [],Satelite sat[])
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
  int nsat=0,k=0;
  int i;
  /* Defining my signal alarm*/
  signal(SIGALRM, end_heur);

  printf("Iniciando leitura de parametros...\n");
  get_args(argc,argv,&TIME,INPUT,OUTPUT);
  printf("\nINPUT:%s,OUTPUT:%s,TIME:%d\n",INPUT,OUTPUT,TIME);

  alarm(TIME); /*Alarme para tempo limite iniciado*/

  printf("Iniciando leitura de dados...\n");
  read_instances(INPUT,&nsat,&k,shard,sat);


  gain=0;
  for(i=1;i<=k;i++){
    shard[i].active=1;
    gain+=shard[i].gain;
  }

  verify_input(nsat,k,shard,sat);
  printf("Iniciando processamento dos dados...\n");

  quicksort(shard,1,k);
  verify_sort(nsat,k,shard,sat);
  printf("sort realizado");
  /*
    Greedy solution
  */
  zf.value=0;
  zf.nshards=0;
  Greedy_solver(shard,sat,nsat,k);
  Local_search(shard,sat,nsat,k);

   printf(" porcentagem de shards: %f",(float)zf.nshards/k);
  printf(" porcentagem de ganho: %f",(float)zf.value/gain);

  while(1);
  
  return 0;	
}

void copy_sol(Solution* a)
{
  int i;
  (*a).value=zf.value;
  (*a).nshards=zf.nshards;

  for(i=0;i<(*a).nshards;i++){
    (*a).chosen[i]= zf.chosen[i];
  }
  // printf("\n==NSHARDS: %d",(*a).nshards);
 
}

void save_sol(Solution* a)
{
  int i;
  zf.value=(*a).value;
  zf.nshards=(*a).nshards;

  for(i=0;i<(*a).nshards;i++){
    zf.chosen[i]=(*a).chosen[i];
  }
  //printf("\n==NSHARDS: %d",zf.nshards);
 
}

void Local_search(Shard s[],Satelite sat[], int nsat, int k)
{
  Solution zrand;
  int LRC[11];/*At least 100 options*/
  int rm_shard,nlrc;
  int i,j,z;
  /* We choose a random shard to take off And make a list of k new possibilities
     to be chosen at random stops when cannot do more at actual state
     if better result, save if not a better result try other random shard
  */
  while(1){
    copy_sol(&zrand);
    //printf("\n Devem ser iguais otima %d  rand %d",zf.nshards,zrand.nshards);
    
    
    /*
      For every shard of solution we take it out
      And try to put other shards
    */
    for(rm_shard=zrand.nshards-1; rm_shard>=0; rm_shard--){
      /*Recover best solution*/
      //copy_sol(&zrand);
      
      /*Possible candidates to be in place in solution*/    
      for(i=0;i<11;i++){
	LRC[i]=0;
      }
      //printf("\n Devem ser iguais otima %d  rand %d",zf.value,zrand.value);
    
      nlrc=find_lrc(LRC,k,s,rm_shard,nsat,sat);
      LRC[nlrc]=zrand.chosen[rm_shard].idx;
      nlrc++;
      rm(rm_shard,&zrand,nsat,sat,s);
      //printf("\n== REMOVI: %d %d", zrand.chosen[rm_shard].x,zrand.chosen[rm_shard].y);
      //printf("\n== LISTA DE POSSIVEIS %d CANDIDATOS:\n",nlrc);
      /*    for(i=0;i<nlrc;i++){
	    printf("x %d y %d gain %d\n",s[LRC[i]].x,s[LRC[i]].y,s[LRC[i]].gain);
	    }  
      */
      z=choose_lrc(&zrand,LRC,nlrc,s,sat);
      /* Free memory and shard*/
      //printf("\n Comparando otima %d  rand %d",zf.value,zrand.value);
    
      if(zrand.value>zf.value){
	save_sol(&zrand);
	printf("\n porcentagem de shards: %f",(float)zf.nshards/k);
	printf("\n porcentagem de ganho: %f",(float)zf.value/gain);
      }
      else{
	/*Need to recover state before rand*/
	//s[(zrand).chosen[rm_shard].idx].active=0;
	//s[LRC[z]].active=1;
      }
    }
  }
}

int choose_lrc(Solution* zrand,int LRC[],int nshard,Shard s[],Satelite sat[])
{
  int save=0,i,min_vcost,min_hcost,init=nshard,tries=0;
  /* generate ramdom number: */

  for(i=0;i<nshard;i++){

    //printf("RAND: x %d y %d g %d",s[LRC[i]].x,s[LRC[i]].y,s[LRC[i]].gain);

    if(sat[s[LRC[i]].x].hmemory>= s[LRC[i]].hcost){
      save=1;
      (*zrand).chosen[(*zrand).nshards].dir='h';
      sat[s[LRC[i]].x].hmemory-=s[LRC[i]].hcost;
    }
    else if(sat[s[LRC[i]].y].vmemory>= s[LRC[i]].vcost){
      save=1;
      (*zrand).chosen[(*zrand).nshards].dir='v';
      sat[s[LRC[i]].y].vmemory-=s[LRC[i]].vcost;
    }
    if(save==1){
      s[LRC[i]].active=0;
      // printf("\nGANHOS %d Val anteiror: %d\n",s[LRC[i]].gain,(*zrand).value);
      (*zrand).value=(*zrand).value+s[LRC[i]].gain;
      (*zrand).chosen[(*zrand).nshards].idx=i;
      (*zrand).chosen[(*zrand).nshards].x=s[LRC[i]].x;
      (*zrand).chosen[(*zrand).nshards].y=s[LRC[i]].y;
      (*zrand).nshards++;
      save=0;
    }
  }
  return i;
}

int rm(int rm_shard,Solution* zrand,int nsat,Satelite sat[],Shard s[])
{
  int i;

  /*Todo: recover memory  */
  if((*zrand).chosen[rm_shard].dir=='h'){
    sat[(*zrand).chosen[rm_shard].x].hmemory+=s[(*zrand).chosen[rm_shard].idx].hcost;
    s[(*zrand).chosen[rm_shard].idx].active=1;
  }
  else{
    sat[(*zrand).chosen[rm_shard].y].vmemory+=s[(*zrand).chosen[rm_shard].idx].vcost;
    s[(*zrand).chosen[rm_shard].idx].active=1;
  }
  /*Todo: recover value
    Save value in chosen is better, isn't?
  */
  //printf("Retirando da sol otima %d\n",s[(*zrand).chosen[rm_shard].idx].gain);
  (*zrand).value-=s[(*zrand).chosen[rm_shard].idx].gain;
  /* Remove shard from solution */
  for(i=rm_shard;i<(*zrand).nshards;i++){
    (*zrand).chosen[i]=(*zrand).chosen[i+1];
  }
  (*zrand).nshards--;
}

int find_lrc(int LRC[],int nshards,Shard s[],int rm_shard,
	     int nsat, Satelite sat[])
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

void Greedy_solver(Shard s[],Satelite sat[], int nsat, int k)
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
