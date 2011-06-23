CC = gcc
CFLAGS = -ansi -W -Wall -pedantic
CDEBUG = -g -ggdb 
LIBS = -lm
OTM = -O3

name=heur
time= 120

all:
	make compile
	make exem

compile:
	$(CC) $(CFLAGS) $(LIBS) $(OTM) -o $(name) $(name).c 
	
exem:
	./heur exemplo.dat -o sol.out -t 2  
