all: TP3exo2

exo2.o: exo2.c
	gcc -c exo2.c

exo2_fcts.o: exo2_fcts.c exo2_fcts.h
	gcc -c exo2_fcts.c

TP3exo2: exo2.o exo2_fcts.o
	gcc exo2.o exo2_fcts.o -o TP3exo2