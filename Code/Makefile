OBJS	= main.o proposition.o premisse.o regle.o baseconnaissance.o engine.o fileio.o
SOURCE	= main.c proposition.c premisse.c regle.c baseconnaissance.c engine.c fileio.c
HEADER	= list_structs.h proposition.h premisse.h regle.h baseconnaissance.h engine.h fileio.h
OUT	= PROJETLO21
CC	 = gcc
FLAGS	 = -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: main.c
	$(CC) $(FLAGS) main.c

proposition.o: proposition.c
	$(CC) $(FLAGS) proposition.c

premisse.o: premisse.c
	$(CC) $(FLAGS) premisse.c

regle.o: regle.c
	$(CC) $(FLAGS) regle.c

baseconnaissance.o: baseconnaissance.c
	$(CC) $(FLAGS) baseconnaissance.c

engine.o: engine.c
	$(CC) $(FLAGS) engine.c

fileio.o: fileio.c
	$(CC) $(FLAGS) fileio.c


clean:
	rm -f $(OBJS) $(OUT)
