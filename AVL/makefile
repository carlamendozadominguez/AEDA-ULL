SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -std=c++11
CPPFLAGS = -Wall -g -I$(INC) -c
HDRS =$(INC)/Dni.h $(INC)/ABB.h $(INC)/cola_ABB.h $(INC)/nodoBB.h 

all: $(BIN)/ABB 

$(BIN)/ABB: $(OBJ)/main.o
	$(CXX) $^ -o $@


$(OBJ)/main.o: $(SRC)/main.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@


clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(BIN)/*
