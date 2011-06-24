#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<math.h>
#include<time.h>

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

/*Shard of solution*/
/*Dir: used vertical or horizontal satelite
 to take a photo of shard x,y
 idx: save index of shard in ordered list
 */
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


/*  Global variables used for debug purpose  */
Shard solshard [50914];
Satelite solsat[301];
Shard inshard [50914];
Satelite insat[301];
int gain;


/*            Macros            */
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)


/*            Heuristic function         */
void Greedy_solver(Shard s[],Satelite sat[],int k);
void Local_search(Shard s[],Satelite sat[], int k);

/*remove a shard from solution to have more space*/
void rm(int rm_shard,Solution* zrand,Satelite sat[],Shard s[]);

/*create lrc - possible 11 canditates to be put in place
  of the removed one, the last one is the removed one*/
int find_lrc(int LRC[],int nshards,Shard s[],int rm_shard);

/*chose candidates lrc - another gredy approach*/
int choose_lrc(Solution* zrand,int LRC[],int nshard,Shard s[],
	       Satelite sat[]);


/*         Sort function              */

/* we order by gain/min(cost to save shard)*/
int partition(Shard s[],int p,int r);
void change(Shard s[],int i,int j);
void quicksort(Shard s[],int begin,int end);


/*        Input/OUTPUT function        */

/*After time limit is reached save answer in a file*/
void write_solution();
void read_instances(char INPUT[], int* nsat,int* k,Shard shard [],Satelite sat[]);

/* Command line error message */
void error_args();

/*Get args */
void get_args(int argc, char** argv,int* TIME,char IN [],char OUT[]);


/*               Debug functios             */
void verify_input(int nsat,int k,Shard shard [],Satelite sat[]);
void verify_solution();/*Uses global variables listed below*/

/* Function called when time reached*/
void end_heur();

/*             Coping and saving solution          */
void copy_sol(Solution* a);
void save_sol(Solution* a);

 
