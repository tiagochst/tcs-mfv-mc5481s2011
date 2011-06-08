#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Program 
   Authors:
   - Murilo Fossa Vicentini
   - Tiago Chedraoui Silva
*/

int main( int argc, char** argv){
  int i=0,TIME=0;
  char OUTPUT [100], INPUT[100];
  time_t start,end;
  double dif;

  FILE * pFile;


  if (argc < 6){
    errorParam();
    return 1;
  }  	    
  else{
    for(i=1;i<6;i++){ 
      if(strcmp(argv[i],"-t")==0){
	printf("Time limit read ...\n");
	TIME=atoi(argv[i+1]);
	i++;
      }
      else if(strcmp(argv[i],"-o")==0){
	printf("Path output file read ...\n");
	strcpy(OUTPUT,argv[i+1]);
	i++;
      }
      else {
	printf("Path input file read ...\n");
	strcpy(INPUT,argv[i]);
      }
    }
    
  }

  printf("Iniciando leitura de dados...\n");
  int nsat=0,aux=0,val=0,k=0;
  int Sh[50],Sv[50];

  /* Leitura de arquivo de entrada  */
  pFile = fopen(INPUT, "r"); 
  if (pFile == NULL) {
    printf("INPUT file is invalid\n");
    return 0;
  }
  fscanf (pFile,"%d",&nsat);
  
  for(aux=1;aux<=nsat;aux++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&Sh[i]);
  }
  
  for(aux=1;aux<=nsat;aux++){
    fscanf (pFile,"%d",&i);
    fscanf (pFile,"%d",&Sv[i]);
  }
    fscanf (pFile,"%d",&k);
  
  fclose(pFile);
  printf("---- INSTANCIA DO PROBLEMA ----\n",nsat);

  printf("NUMERO DE SATELITES: %d\n",nsat);

  printf("SATELITES VERTICAIS: \n");
  for(aux=1;aux<=nsat;aux++){
    printf("%d ",Sh[aux]);
  }

  printf("\nSATELITES HORIZONTAIS: \n");
  for(aux=1;aux<=nsat;aux++){
    printf("%d ",Sv[aux]);
  }

  printf("\n-------------------------\n");

  printf("Iniciando processamento dos dados...\n");
  time (&start);

  while(1){
    time (&end);
    if(difftime (end,start)>TIME){
      printf("TIME LIMIT EXCEDED\n");
      break;
    }
  }
  printf("\nINPUT:%s,OUTPUT:%s,TIME:%d\n",INPUT,OUTPUT,TIME);

 
  return 0;	
}

/* Error message */
void errorParam(){

  printf("\n****************************************************\n");
  printf(" Program should receive the following parameters :\n");
  printf(" -t Time -o SAIDA ENTRADA\n");
  printf("****************************************************\n");

  return;
}
