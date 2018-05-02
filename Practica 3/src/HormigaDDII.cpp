/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HormigaDDII.cpp
 * Author: carla
 * 
 * Created on 6 de marzo de 2018, 18:37
 */

#include "HormigaDDII.h"
HormigaDDII::HormigaDDII() {
}

HormigaDDII::HormigaDDII(int x, int y, int m_iter):
    Agente(x,y,m_iter){}


 HormigaDDII::~HormigaDDII() {}


 void HormigaDDII::siguiente_paso(Tablero& rejilla){
     
     int color = rejilla.get_color(get_x(),get_y());
    
     if (color == 0){ //Si la hormiga esta en blanco
        rejilla.cambiar_color(get_x(),get_y(),1);  //Cambiamos el color a negro
        turn_r(); //Giramos izquierda
    }else if(color == 1){
        rejilla.cambiar_color(get_x(),get_y(),3);  //Cambiamos el color a blanco
        turn_r(); //Giramos derecha
    }else if(color == 2){
        rejilla.cambiar_color(get_x(),get_y(),0);  //Cambiamos el color a blanco
        turn_l(); //Giramos derecha
    }else{
        rejilla.cambiar_color(get_x(),get_y(),2);  //Cambiamos el color a blanco
        turn_l(); //Giramos derecha
    }
     
    forward();     
}

