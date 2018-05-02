SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c
HDRS =$(INC)/Dni.hpp $(INC)/Celdas.h $(INC)/Tabla.h $(INC)/fDispersionBase.h $(INC)/fExploracionBase.h

all: $(BIN)/tabla

$(BIN)/tabla: $(OBJ)/main.o
	$(CXX) $^ -o $@


$(OBJ)/main.o: $(SRC)/main.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(BIN)/*
