/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HormigaIIDD.cpp
 * Author: carla
 * 
 * Created on 13 de marzo de 2018, 10:46
 */

#include "HormigaIIDD.h"

HormigaIIDD::HormigaIIDD() {
}

HormigaIIDD::HormigaIIDD(int x, int y, int m_iter):
    Agente(x,y,m_iter){}


 HormigaIIDD::~HormigaIIDD() {}


 void HormigaIIDD::siguiente_paso(Tablero& rejilla){
     
     int color = rejilla.get_color(get_x(),get_y());
    
     if (color == 0){ //Si la hormiga esta en blanco
        rejilla.cambiar_color(get_x(),get_y(),1);  //Cambiamos el color a negro
        turn_l(); //Giramos izquierda
    }else if(color == 1){
        rejilla.cambiar_color(get_x(),get_y(),3);  //Cambiamos el color a blanco
        turn_l(); //Giramos derecha
    }else if(color == 2){
        rejilla.cambiar_color(get_x(),get_y(),0);  //Cambiamos el color a blanco
        turn_r(); //Giramos derecha
    }else{
        rejilla.cambiar_color(get_x(),get_y(),2);  //Cambiamos el color a blanco
        turn_r(); //Giramos derecha
    }
     
    forward();     
}