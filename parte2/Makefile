CC = gcc
CFLAGS = -ansi -W -Wall -pedantic
CDEBUG = -g -ggdb 
LIBS = -lm
OTM = -O3

name=heur
time= 120

all:
	make compile2
	make exem2

compile2:
	$(CC) $(LIBS) -o $(name) $(name).c 
        

compile:
	$(CC) $(CFLAGS) $(LIBS) $(OTM) $(CDEBUG) -o $(name) $(name).c 
	
exem:
	./heur exemplo.dat -o sol.out -t 2
inst:
	for i in $(ls); do
	 	#./heur $i -o  $i.out -t $(time)
		echo $i
	done

exem2:
	./heur ex2.dat -o sol2.out -t 2

