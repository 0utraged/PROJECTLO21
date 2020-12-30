OBJS	= main.o proposition.o premisse.o regle.o baseconnaissance.o engine.o fileio.o
SOURCE	= main.c proposition.c premisse.c regle.c baseconnaissance.c engine.c fileio.c
HEADER	= list_structs.h proposition.h premisse.h regle.h baseconnaissance.h engine.h fileio.h
OUT	= PROJETLO21

all: PROJETLO21

PROJETLO21: $(OBJS)
	$(CC) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OUT)
