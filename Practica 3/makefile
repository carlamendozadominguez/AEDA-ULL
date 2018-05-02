SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c
HDRS =$(INC)/Matriz.h $(INC)/Tablero.hpp $(INC)/Agente.h $(INC)/HormigaDDII.h $(INC)/HormigaDIDI.h $(INC)/HormigaIIDD.h $(INC)/Maquina.h

all: $(BIN)/langton 

$(BIN)/langton: $(OBJ)/main.o $(OBJ)/Agente.o $(OBJ)/HormigaDDII.o $(OBJ)/HormigaDIDI.o $(OBJ)/HormigaIIDD.o $(OBJ)/Matriz.o $(OBJ)/Tablero.o $(OBJ)/Maquina.o 
	$(CXX) $^ -o $@


$(OBJ)/main.o: $(SRC)/main.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Agente.o: $(SRC)/Agente.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/HormigaDDII.o: $(SRC)/HormigaDDII.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/HormigaDIDI.o: $(SRC)/HormigaDIDI.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/HormigaIIDD.o: $(SRC)/HormigaIIDD.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Matriz.o: $(SRC)/Matriz.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Tablero.o: $(SRC)/Tablero.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Maquina.o: $(SRC)/Maquina.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(BIN)/*
