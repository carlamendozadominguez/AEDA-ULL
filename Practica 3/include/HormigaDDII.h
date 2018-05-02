/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HormigaDDII.h
 * Author: carla
 *
 * Created on 6 de marzo de 2018, 18:37
 */

#ifndef HORMIGADDII_H
#define HORMIGADDII_H
#include "Agente.h"
#include "Tablero.hpp"

class Agente;

class HormigaDDII:public Agente {
public:
    HormigaDDII();
    HormigaDDII(int,int, int);
     ~HormigaDDII();
     void siguiente_paso(Tablero& rejilla);

};

#endif /* HORMIGADDII_H */

