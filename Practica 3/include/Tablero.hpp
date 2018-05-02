/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.hpp
 * Author: carla
 *
 * Created on 24 de febrero de 2018, 11:57
 */

#ifndef TABLERO_HPP
#define TABLERO_HPP
#include <iostream>
#include <iomanip>
#include <vector>

#include "Matriz.h"
#include "Agente.h"

using namespace std;

#define COLORES 2

class Tablero {
    
private:
    
    Matriz matriz;
    
public:
    Tablero();
    Tablero(int,int);
    ~Tablero();
    void rellena_tablero(void);
    void cambiar_color(int,int,int);
    int get_color(int,int);
    int get_m();
    int get_n();
    void write(ostream& os, vector <Agente*> a);
    void mostrar();
    Tablero& operator=(const Tablero& other);
};

#endif /* TABLERO_HPP */

