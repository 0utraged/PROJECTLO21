CC = gcc

BIN = ./bin/

SRC = ./src/

INC = ./include/

$(BIN)LO21BF: $(BIN)main.o $(BIN)proposition.o $(BIN)premisse.o $(BIN)regle.o $(BIN)baseconnaissance.o $(BIN)engine.o $(BIN)fileio.o
	$(CC) -o $(BIN)LO21BF $(BIN)main.o $(BIN)proposition.o $(BIN)premisse.o $(BIN)regle.o $(BIN)baseconnaissance.o $(BIN)engine.o $(BIN)fileio.o
$(BIN)main.o : $(SRC)main.c $(INC)list_structs.h
	$(CC) -c $(SRC)main.c
$(BIN)proposition.o : $(SRC)proposition.c $(INC)proposition.h $(INC)list_structs.h
	$(CC) -c $(SRC)proposition.c
$(BIN)premisse.o : $(SRC)premisse.c $(INC)premisse.h $(INC)list_structs.h
	$(CC) -c $(SRC)premisse.c
$(BIN)regle.o : $(SRC)regle.c $(INC)regle.h $(INC)list_structs.h
	$(CC) -c $(SRC)regle.c
$(BIN)baseconnaissance.o : $(SRC)baseconnaissance.c $(INC)baseconnaissance.h $(INC)list_structs.h
	$(CC) -c $(SRC)baseconnaissance.c
$(BIN)engine.o : $(SRC)engine.c $(INC)engine.h $(INC)list_structs.h
	$(CC) -c $(SRC)engine.c
$(BIN)fileio.o : $(SRC)fileio.c $(INC)fileio.h
	$(CC) -c $(SRC)fileio.c
clean :
	rm edit $(BIN)main.o $(BIN)proposition.o $(BIN)premisse.o $(BIN)regle.o $(BIN)baseconnaissance.o $(BIN)engine.o $(BIN)fileio.o
