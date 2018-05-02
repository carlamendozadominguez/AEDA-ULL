/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HormigaDIDI.h
 * Author: carla
 *
 * Created on 8 de marzo de 2018, 16:28
 */

#ifndef HORMIGADIDI_H
#define HORMIGADIDI_H

#include "Agente.h"
#include "Tablero.hpp"

class Agente;

class HormigaDIDI:public Agente {
public:
    HormigaDIDI();
    HormigaDIDI(int,int, int);
     ~HormigaDIDI();
     void siguiente_paso(Tablero& rejilla);

};

#endif /* HORMIGADIDI_H */

