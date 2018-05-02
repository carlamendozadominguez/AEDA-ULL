/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Maquina.h
 * Author: carla
 *
 * Created on 25 de febrero de 2018, 17:49
 */

#ifndef MAQUINA_H
#define MAQUINA_H

#include "HormigaDDII.h"
#include "Tablero.hpp"
#include "HormigaDIDI.h"
#include "HormigaIIDD.h"
#include "Agente.h"
#include <unistd.h>

class Maquina {
private:
    vector <Agente*> hormiga;
    Tablero rejilla;
    int iter;
    
public:
    Maquina();
    Maquina(int m, int n, int x, int y ,int m_iter);
    ~Maquina();
    int get_iter(void);
    int max_iter();
    void siguiente_paso();
    void incrementar_iter();
    void write(ostream& os);
    
};

#endif /* MAQUINA_H */

