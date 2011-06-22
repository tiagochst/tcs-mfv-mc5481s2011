#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<signal.h>

/* Program 
   Authors:
   - Murilo Fossa Vicentini
   - Tiago Chedraoui Silva
*/

typedef struct {
  int x,y;
  int gain;
  int hcost,vcost; 
} Shard;

typedef struct {
  int hmemory;
  int vmemory; 
} Satelite;

/*****     FUNCTIONS     *****/
void read_instances(char INPUT[], int* nsat,int* k,
		    Shard shard [],Satelite sat[])
{
  int i=0,j=0,aux=0;
  FILE * pFile;

  /* Leitura de arquivo de entrada  */
  pFile = fopen(INPUT, "r"); 
  if (pFile == NULL) {
    printf("INPUT file is invalid\n");
    return 0;
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
void errorParam()
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
    errorParam();
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
  printf("\n ",sat[aux].vmemory);
  
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
void end_heur(int signum) 
{
  printf("\nFim do programa: alarme é tratado pela função end_heur().\n");
  printf("TIME LIMIT EXCEDED\n");
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
  char OUTPUT [100], INPUT[100];

  /*Intances*/
  Shard shard [50913];
  Satelite sat[300];
  int nsat=0,k=0;

  /* Defining my signal alarm*/
  signal(SIGALRM, end_heur);

  printf("Iniciando leitura de parametros...\n");
  get_args(argc,argv,&TIME,INPUT,OUTPUT);
  printf("\nINPUT:%s,OUTPUT:%s,TIME:%d\n",INPUT,OUTPUT,TIME);

  printf("Iniciando leitura de dados...\n");
  read_instances(INPUT,&nsat,&k,shard,sat);

  verify_input(nsat,k,shard,sat);
  printf("Iniciando processamento dos dados...\n");

  alarm(TIME);
  while(1){
  }

  return 0;	
}

