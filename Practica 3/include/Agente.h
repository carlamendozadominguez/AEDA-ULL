/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Agente.h
 * Author: carla
 *
 * Created on 25 de febrero de 2018, 17:15
 */

#ifndef AGENTE_H
#define AGENTE_H

#include <cassert>
#include <iostream>

using namespace std;

class Tablero;

class Agente {

protected:
    int x_;
    int y_;
    int orientacion_;
    int max_move;

public:
    Agente();
    Agente(int,int,int);
     virtual ~Agente();
     int max_iter();
     int get_x();
     int get_y();
     int get_orientacion();
     void set(int,int);
     void set_orientacion(int);
     void forward();
     void turn_r();
     void turn_l();
     void go_back(void);
     void write(ostream& os) const;
     void caminar(Tablero& rejilla);
     virtual void siguiente_paso(Tablero& rejilla) = 0;
     

    Agente& operator=(const Agente& other);
   
    friend ostream& operator<<(ostream& os, const Agente& a){
        a.write(os);
        return os;
    }
    
    
};




#endif /* AGENTE_H */

