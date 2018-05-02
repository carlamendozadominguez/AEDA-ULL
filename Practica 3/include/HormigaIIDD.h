/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HormigaIIDD.h
 * Author: carla
 *
 * Created on 13 de marzo de 2018, 10:46
 */

#ifndef HORMIGAIIDD_H
#define HORMIGAIIDD_H

#include "Agente.h"
#include "Tablero.hpp"

class Agente;

class HormigaIIDD:public Agente {
public:
    HormigaIIDD();
    HormigaIIDD(int,int, int);
     ~HormigaIIDD();
     void siguiente_paso(Tablero& rejilla);

};

#endif /* HORMIGAIIDD_H */


