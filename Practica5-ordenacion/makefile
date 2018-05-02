SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c
HDRS =$(INC)/Dni.hpp $(INC)/ordenacion.h $(INC)/termcolor.hpp $(INC)/nodoBB.h 

all: $(BIN)/ordenacion

$(BIN)/ordenacion: $(OBJ)/main.o
	$(CXX) $^ -o $@


$(OBJ)/main.o: $(SRC)/main.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@


clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(BIN)/*
